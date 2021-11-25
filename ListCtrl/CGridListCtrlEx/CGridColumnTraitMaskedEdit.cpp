//------------------------------------------------------------------------
// Author:  Rolf Kristensen	
// Source:  http://www.codeproject.com/KB/list/CGridListCtrlEx.aspx
// License: Free to use for all (New BSD License)
//------------------------------------------------------------------------

#include "stdafx.h"
#pragma warning(disable:4100)	// unreferenced formal parameter

#include "CGridColumnTraitMaskedEdit.h"

#include "CGridColumnTraitVisitor.h"
#include "CGridListCtrlEx.h"

//------------------------------------------------------------------------
//! CGridColumnTraitMaskedEdit - Constructor
//------------------------------------------------------------------------
CGridColumnTraitMaskedEdit::CGridColumnTraitMaskedEdit()
	:m_EditStyle(ES_AUTOHSCROLL | ES_NOHIDESEL | WS_BORDER)
	,strMask("")
	,PromptSymbol(' ')
{
}

//------------------------------------------------------------------------
//! Accept Visitor Pattern
//------------------------------------------------------------------------
void CGridColumnTraitMaskedEdit::Accept(CGridColumnTraitVisitor& visitor)
{
	visitor.Visit(*this);
}

//------------------------------------------------------------------------
//! Set style used when creating CEdit for cell value editing
//!
//! @param dwStyle Style flags
//------------------------------------------------------------------------
void CGridColumnTraitMaskedEdit::SetStyle(DWORD dwStyle)
{
	m_EditStyle = dwStyle;
}

//------------------------------------------------------------------------
//! Get style used when creating CEdit for cell value editing
//------------------------------------------------------------------------
DWORD CGridColumnTraitMaskedEdit::GetStyle() const
{
	return m_EditStyle;
}

//------------------------------------------------------------------------
//! Set max number of characters the CEdit will accept
//!
//! @param nMax The text limit, in characters.
//------------------------------------------------------------------------
void CGridColumnTraitMaskedEdit::SetMaskText(CString strText)
{
	strMask = strText;
}

//------------------------------------------------------------------------
//! Set max number of characters the CEdit will accept
//!
//! @param nMax The text limit, in characters.
//------------------------------------------------------------------------
void CGridColumnTraitMaskedEdit::SetPromptSymbol(TCHAR promptsymbol)
{
	PromptSymbol = promptsymbol;
}

//------------------------------------------------------------------------
//! Create a CEdit as cell value editor
//!
//! @param owner The list control starting a cell edit
//! @param nRow The index of the row
//! @param nCol The index of the column
//! @param rect The rectangle where the inplace cell value editor should be placed
//! @return Pointer to the cell editor to use
//------------------------------------------------------------------------
COXMaskedEdit* CGridColumnTraitMaskedEdit::CreateEdit(CGridListCtrlEx& owner, int nRow, int nCol, const CRect& rect)
{
	// Get the text-style of the cell to edit
	DWORD dwStyle = m_EditStyle;
	HDITEM hd = {0};
	hd.mask = HDI_FORMAT;
	VERIFY( owner.GetHeaderCtrl()->GetItem(nCol, &hd) );
	if (hd.fmt & HDF_CENTER)
		dwStyle |= ES_CENTER;
	else if (hd.fmt & HDF_RIGHT)
		dwStyle |= ES_RIGHT;
	else
		dwStyle |= ES_LEFT;

	COXMaskedEdit* pEdit = new CGridMaskedEditorText(nRow, nCol);
	VERIFY( pEdit->Create( WS_CHILD | dwStyle, rect, &owner, 0) );

	return pEdit;
}

//------------------------------------------------------------------------
//! Overrides OnEditBegin() to provide a CEdit cell value editor
//!
//! @param owner The list control starting edit
//! @param nRow The index of the row for the cell to edit
//! @param nCol The index of the column for the cell to edit
//! @return Pointer to the cell editor to use (NULL if cell edit is not possible)
//------------------------------------------------------------------------
CWnd* CGridColumnTraitMaskedEdit::OnEditBegin(CGridListCtrlEx& owner, int nRow, int nCol)
{
	// Get position of the cell to edit
	CRect rectCell = GetCellEditRect(owner, nRow, nCol);

	// Create edit control to edit the cell
	COXMaskedEdit* pEdit = CreateEdit(owner, nRow, nCol, rectCell);
	VERIFY(pEdit!=NULL);
	if (pEdit==NULL)
		return NULL;
	// Configure font
	pEdit->SetFont(owner.GetCellFont());
	pEdit->SetPromptSymbol(PromptSymbol);
	pEdit->SetMask(strMask);
	pEdit->SetInputData(owner.GetItemText(nRow, nCol),0,TRUE);
	//pEdit->SetWindowText(owner.GetItemText(nRow, nCol));
	pEdit->SetSel(0, -1, 0);
	return pEdit;
}

//------------------------------------------------------------------------
// CGridNumericEditorText (For internal use)
//------------------------------------------------------------------------
BEGIN_MESSAGE_MAP(CGridMaskedEditorText, COXMaskedEdit)
	//{{AFX_MSG_MAP(CGridNumericEditorText)
	ON_WM_KEYDOWN()
	ON_WM_KILLFOCUS()
	ON_WM_NCDESTROY()
	ON_CONTROL_REFLECT_EX(EN_CHANGE, OnEnChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//------------------------------------------------------------------------
//! CGridNumericEditorText - Constructor
//------------------------------------------------------------------------
CGridMaskedEditorText::CGridMaskedEditorText(int nRow, int nCol)
	:m_Row(nRow)
	,m_Col(nCol)
	,m_Completed(false)
	,m_Modified(false)
{
}

//------------------------------------------------------------------------
//! The cell value editor was closed and the entered should be saved.
//!
//! @param bSuccess Should the entered cell value be saved
//------------------------------------------------------------------------
void CGridMaskedEditorText::EndEdit(bool bSuccess)
{
	// Avoid two messages if key-press is followed by kill-focus
	if (m_Completed)
		return;

	m_Completed = true;

	// Send Notification to parent of ListView ctrl
	CString str;
	str = GetInputData();

	LV_DISPINFO dispinfo = {0};
	dispinfo.hdr.hwndFrom = GetParent()->m_hWnd;
	dispinfo.hdr.idFrom = GetDlgCtrlID();
	dispinfo.hdr.code = LVN_ENDLABELEDIT;

	dispinfo.item.iItem = m_Row;
	dispinfo.item.iSubItem = m_Col;
	if (bSuccess && m_Modified)
	{
		dispinfo.item.mask = LVIF_TEXT;
		dispinfo.item.pszText = str.GetBuffer(0);
		dispinfo.item.cchTextMax = str.GetLength();
	}
	ShowWindow(SW_HIDE);
	GetParent()->GetParent()->SendMessage( WM_NOTIFY, GetParent()->GetDlgCtrlID(), (LPARAM)&dispinfo );
	PostMessage(WM_CLOSE);
}

//------------------------------------------------------------------------
//! WM_KILLFOCUS message handler called when CEdit is loosing focus
//! to other control. Used register that cell value editor should close.
//!
//! @param pNewWnd Pointer to the window that receives the input focus (may be NULL or may be temporary).
//------------------------------------------------------------------------
void CGridMaskedEditorText::OnKillFocus(CWnd *pNewWnd)
{
	CEdit::OnKillFocus(pNewWnd);
	EndEdit(true);
}

//------------------------------------------------------------------------
//! WM_NCDESTROY message handler called when CEdit window is about to
//! be destroyed. Used to delete the inplace CEdit editor object as well.
//! This is necessary when the CDateTimeCtrl is created dynamically.
//------------------------------------------------------------------------
void CGridMaskedEditorText::OnNcDestroy()
{
	CEdit::OnNcDestroy();
	delete this;
}

//------------------------------------------------------------------------
//! EN_CHANGE notification handler to monitor text modifications
//------------------------------------------------------------------------
BOOL CGridMaskedEditorText::OnEnChange()
{
	if (m_InitialModify)
		m_Modified = true;
	else
		m_InitialModify = true;
	return TRUE;
}

///////////////////////////////////////////////////////////////////
//On key down//////////////////////////////////////////////////////
void CGridMaskedEditorText::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch(nChar)
	{
		case 0x41:		// CTRL+A (Select all)
		{
			if (GetKeyState(VK_CONTROL) < 0)
			{
				SetSel(0,-1);
			}
		} break;
		case VK_RETURN:
			{
			if (GetStyle() & ES_WANTRETURN)
				break;

			EndEdit(true);
			} break;
		case VK_ESCAPE:
			{
			EndEdit(false);
			} break;
		case VK_TAB:
			{
			 EndEdit(true);
			} break;

	}
	COXMaskedEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}