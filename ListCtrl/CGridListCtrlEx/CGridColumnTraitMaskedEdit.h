#pragma once

//------------------------------------------------------------------------
// Author:  Rolf Kristensen	
// Source:  http://www.codeproject.com/KB/list/CGridListCtrlEx.aspx
// License: Free to use for all (New BSD License)
//------------------------------------------------------------------------

#include "CGridColumnTraitImage.h"
#include "OXMaskedEdit.h"
//------------------------------------------------------------------------
//! CGridColumnTraitNumericEdit implements a CEdit as cell-editor
//------------------------------------------------------------------------
class CGridColumnTraitMaskedEdit : public CGridColumnTraitImage
{
public:
	CGridColumnTraitMaskedEdit();

	void SetStyle(DWORD dwStyle);
	DWORD GetStyle() const;

	void SetMaskText(CString strText);
	CString GetMaskText(){ return strMask;};

	void SetPromptSymbol(TCHAR promptsymbol);
	TCHAR GetPromptSymbol(){ return PromptSymbol; };

	virtual CWnd* OnEditBegin(CGridListCtrlEx& owner, int nRow, int nCol);

protected:
	virtual void Accept(CGridColumnTraitVisitor& visitor);
	virtual COXMaskedEdit* CreateEdit(CGridListCtrlEx& owner, int nRow, int nCol, const CRect& rect);

	DWORD m_EditStyle;				//!< Style to use when creating CEdit
	
	CString strMask;
	TCHAR PromptSymbol;
};


//------------------------------------------------------------------------
//! CEdit for inplace edit. For internal use by CGridColumnTraitNumericEdit
//------------------------------------------------------------------------
class CGridMaskedEditorText : public COXMaskedEdit
{
public:
	CGridMaskedEditorText(int nRow, int nCol);
	virtual void EndEdit(bool bSuccess);

protected:
	int		m_Row;					//!< The index of the row being edited
	int		m_Col;					//!< The index of the column being edited
	bool	m_Completed;			//!< Ensure the editor only reacts to a single close event
	bool	m_Modified;				//!< Register if text was modified while the editor was open
	bool m_InitialModify;
protected:
	afx_msg void OnKillFocus(CWnd *pNewWnd);
	afx_msg void OnNcDestroy();
	afx_msg BOOL OnEnChange();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	DECLARE_MESSAGE_MAP();
};