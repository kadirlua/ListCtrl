#include "StdAfx.h"
#include "CustomListCtrl.h"
#include "ControlHolderWnd.h"

BEGIN_MESSAGE_MAP(CCustomListCtrl, CGridListCtrlEx)
	//{{AFX_MSG_MAP(CCustomSliderCtrl)
	ON_WM_LBUTTONDOWN()	// OnLButtonDown(UINT nFlags, CPoint point)
	ON_WM_RBUTTONDOWN()	// OnRButtonDown(UINT nFlags, CPoint point)
	ON_WM_LBUTTONDBLCLK() // OnLButtonDblClk
	ON_WM_KEYDOWN()
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
	ON_NOTIFY_EX(HDN_ITEMSTATEICONCLICK,0,OnHeaderItemStateIconClick)
	ON_NOTIFY_EX(TTN_NEEDTEXTA, 0, OnToolNeedText)
	ON_NOTIFY_EX(TTN_NEEDTEXTW, 0, OnToolNeedText)
	ON_NOTIFY_REFLECT_EX(LVN_COLUMNCLICK, OnHeaderClick)	// Column Click
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


CCustomListCtrl::CCustomListCtrl(void)
{
}

CCustomListCtrl::~CCustomListCtrl(void)
{
}

void CCustomListCtrl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	CGridListCtrlEx::OnKeyDown(nChar, nRepCnt, nFlags);
	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();
	
	if(pParent)
	{
		CString strContext;
		CString strCtrl, strAlt, strShift;

		strCtrl = "false";
		strAlt = "false";
		strShift = "false";

		if(GetKeyState(VK_CONTROL) & 32768)
		{
			strCtrl = "true";
		}
		if(GetKeyState(VK_MENU) & 32768)
		{
			strAlt = "true";
		}
		if(GetKeyState(VK_SHIFT) & 32768)
		{
			strShift = "true";
		}

		CString strArgs;
		strArgs.Format("local e_Key=%d;local e_Modifiers = {};e_Modifiers.ctrl=%s;e_Modifiers.alt=%s;e_Modifiers.shift=%s"
			,nChar,strCtrl,strAlt,strShift);
		pParent->m_pListCtrlObject->FireEvent("On KeyDown",strArgs);
	}
}

void CCustomListCtrl::OnSetFocus(CWnd* pOldWnd) 
{
	CGridListCtrlEx::OnSetFocus(pOldWnd);
	
	// TODO: Add your message handler code here
	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

	if(pParent)
	{
		pParent->m_pListCtrlObject->FireEvent("On Focus","");
	}
}

CString CCustomListCtrl::SetHeaderCheckbox(int nItem) {
	// We need to get the current format of the header
	// and set or remove the HDF_CHECKED flag
	BOOL bReturn = TRUE;
	CHeaderCtrl *header = GetHeaderCtrl();
	HDITEM hdi;
	hdi.mask = HDI_FORMAT;
	header->GetItem(nItem,&hdi);
	if (hdi.fmt & HDF_CHECKED) {
		hdi.fmt &= ~HDF_CHECKED;
		bReturn = FALSE;
	} else {
		hdi.fmt |= HDF_CHECKED;
	}
	header->SetItem(nItem,&hdi);
	return (hdi.fmt & HDF_CHECKED)?"true":"false";
}

BOOL CCustomListCtrl::OnHeaderItemStateIconClick(UINT id, NMHDR* pNMHDR, LRESULT* pResult)
{
	CGridListCtrlEx::OnHeaderItemStateIconClick(id, pNMHDR, pResult);
	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

	if(pParent)
	{
		NMHEADER* pNMH = reinterpret_cast<NMHEADER*>(pNMHDR);
		if (pNMH->pitem->mask & HDI_FORMAT && pNMH->pitem->fmt & HDF_CHECKBOX) {
			//CheckAllItems(!(pNMH->pitem->fmt & HDF_CHECKED));
			CString bReturn = SetHeaderCheckbox(pNMH->iItem);
			CString strArgs;
			strArgs.Format("local nCol=%d;local bChecked=%s",pNMH->iItem,bReturn);
			pParent->m_pListCtrlObject->FireEvent("On HeaderCheckBox",strArgs);
			return TRUE;
		}
	}
	return FALSE;
}

void CCustomListCtrl::OnRButtonDown(UINT nFlags, CPoint point) 
{
	CGridListCtrlEx::OnRButtonDown(nFlags,point);
	if( GetFocus() != this )
		SetFocus();	// Force focus to finish editing

	// Find out what subitem was clicked
	int nRow, nCol;
	CellHitTest(point, nRow, nCol);

	// If not right-clicking on an actual row, then don't update focus cell
	if (nRow!=-1)
	{
		// Update the focused cell before calling CListCtrl::OnRButtonDown()
		// as it might cause a row-repaint
		SetFocusCell(nCol);		
		CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

		if(pParent)
		{
			CString strArgs;
			strArgs.Format("local X=%d;local Y=%d",point.x,point.y);
			pParent->m_pListCtrlObject->FireEvent("On RightClick",strArgs);
		}
	}
}

bool CCustomListCtrl::OnDisplayCellColor(int nRow, int nCol, COLORREF& textColor, COLORREF& backColor)
{
	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

	if(pParent)
	{
		CString strArgs;
		strArgs.Format("local row=%d;local col=%d",nRow,nCol);
		pParent->m_pListCtrlObject->FireEvent("On CellColor",strArgs);
	}
	textColor = m_cTextColor;
	backColor = m_cBackColor;
	return true;
}

BOOL CCustomListCtrl::OnToolNeedText(UINT id, NMHDR* pNMHDR, LRESULT* pResult)
{
	CPoint pt(GetMessagePos());
	ScreenToClient(&pt);
	
	int nRow, nCol;
	CellHitTest(pt, nRow, nCol);

	// Make const-reference to the returned anonymous CString-object,
	// will keep it alive until reaching scope end
	
	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

	if(pParent)
	{
		_bstr_t _bstr;
		CString strArgs;
		strArgs.Format("local row=%d;local col=%d",nRow,nCol);
		pParent->m_pListCtrlObject->FireEvent("On ToolNeedText",strArgs);
			//if (strTooltipText.IsEmpty()) return FALSE;
			if (m_TooltipMaxWidth > 0)
			{
				CToolTipCtrl* pToolTipCtrl = (CToolTipCtrl*)CWnd::FromHandle((HWND)::SendMessage(m_hWnd, LVM_GETTOOLTIPS, 0, 0L));
				if (pToolTipCtrl!=NULL && pToolTipCtrl->m_hWnd!=NULL)
				{
				pToolTipCtrl->SetMaxTipWidth(m_TooltipMaxWidth);
				pToolTipCtrl->SetTitle(TTI_NONE,strTooltipTitleText);
				}
			}
			// Non-unicode applications can receive requests for tooltip-text in unicode
			TOOLTIPTEXTA* pTTTA = reinterpret_cast<TOOLTIPTEXTA*>(pNMHDR);
			TOOLTIPTEXTW* pTTTW = reinterpret_cast<TOOLTIPTEXTW*>(pNMHDR);
			_bstr = strTooltipText.AllocSysString();
			pTTTW->lpszText = _bstr;
			SysFreeString(_bstr);
		return TRUE;
	}
	return FALSE;
}

void CCustomListCtrl::OnKillFocus(CWnd* pNewWnd)
{
	OnSaveStateKillFocus();

	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

	if(pParent)
	{
		pParent->m_pListCtrlObject->FireEvent("On KillFocus","");
	}

}

//------------------------------------------------------------------------
//! The WM_LBUTTONDBLCLK message is posted when the user double-clicks the
//! left mouse button while the cursor is in the client area of a window
//! Used to flip the checkbox image even when double-clicking.
//! If wanting to handle the double-click event, then one should use NM_DBLCLK
//!
//! @param nFlags Indicates whether various virtual keys are down (MK_CONTROL, MK_SHIFT, etc.)
//! @param point Mouse cursor position relative to the upper-left corner of the client area.
//------------------------------------------------------------------------
void CCustomListCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// Find out what subitem was double-clicked
	int nRow, nCol;
	CellHitTest(point, nRow, nCol);

	int startEdit = 0;
	if (nRow!=-1)
	{
		if( GetFocus() != this )
			SetFocus();	// Force focus to finish editing

		startEdit = OnClickEditStart(nRow, nCol, point, true);
	}

	if (startEdit!=2)
		CListCtrl::OnLButtonDblClk(nFlags, point);

	if (startEdit!=0)
		EditCell(nRow, nCol, point);

	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

	if(pParent)
	{
		pParent->m_pListCtrlObject->FireEvent("On DoubleClick","");
	}
}

//------------------------------------------------------------------------
//! WM_LBUTTONDOWN message handler called when the user presses the left
//! mouse button while the cursor is in the client area of a window.
//! Used to activate the cell editor of the cell clicked using the mouse.
//!
//! @param nFlags Indicates whether various virtual keys are down (MK_CONTROL, MK_SHIFT, etc.)
//! @param point Mouse cursor position relative to the upper-left corner of the client area.
//------------------------------------------------------------------------
void CCustomListCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	// Find out what subitem was clicked
	int nRow, nCol;
	CellHitTest(point, nRow, nCol);

	// If not left-clicking on an actual row, then don't update focus cell
	if (nRow==-1)
	{
		CListCtrl::OnLButtonDown(nFlags, point);
		return;
	}

	if( GetFocus() != this )
		SetFocus();	// Force focus to finish editing

	int startEdit = OnClickEditStart(nRow, nCol, point, false);
	if (startEdit!=2)
	{
		// Update the focused cell before calling CListCtrl::OnLButtonDown()
		// as it might cause a row-repaint
		SetFocusCell(nCol);

		CListCtrl::OnLButtonDown(nFlags, point);

		// LVN_BEGINDRAG message can be fired when calling parent OnLButtonDown(),
		// this should not result in a start edit operation
		if (GetFocusCell() != nCol)
		{
			SetFocusCell(nCol);
			startEdit = 0;
		}

		// CListCtrl::OnLButtonDown() doesn't change row if clicking on subitem without fullrow selection
		if (!(GetExtendedStyle() & LVS_EX_FULLROWSELECT))
		{
			if (nRow!=GetFocusRow())
			{
				SetFocusRow(nRow);
				if (!(GetKeyState(VK_CONTROL) < 0) && !(GetKeyState(VK_SHIFT) < 0))
				{
					SelectRow(-1, false);
					SelectRow(nRow, true);
				}
			}
		}

		// CListCtrl::OnLButtonDown() doesn't always cause a row-repaint
		// call our own method to ensure the row is repainted
		SetFocusCell(nCol, true);
	}

	if (startEdit!=0)
	{
		// This will steal the double-click event when double-clicking a cell that already have focus,
		// but we cannot guess after the first click, whether the user will click a second time.
		// A timer could be used but it would cause slugish behavior (http://blogs.msdn.com/oldnewthing/archive/2004/10/15/242761.aspx)
		EditCell(nRow, nCol, point);
	}

	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

	if(pParent)
	{
		pParent->m_pListCtrlObject->FireEvent("On Click","");
	}

}

void CCustomListCtrl::OnContextMenu(CWnd* pWnd, CPoint point)
{
	if( GetFocus() != this )
		SetFocus();	// Force focus to finish editing

	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

	if(pParent)
	{
		CString strArgs;
		if ( CGridListCtrlGroups::IsGroupViewEnabled() )
			{
				if (pWnd!=GetHeaderCtrl())
				{
					if (point.x!=-1 && point.y!=-1)
					{
						CPoint pt = point;
						ScreenToClient(&pt);

						int nGroupId = GroupHitTest(pt);
						if (nGroupId!=-1)
						{
							strArgs.Format("local X=%d;local Y=%d;local nGroupID=%d",point.x,point.y,nGroupId);
							pParent->m_pListCtrlObject->FireEvent("On GroupMenuHeader",strArgs);
							return;
						}
					}
				}
			}
		if (point.x!=-1 && point.y!=-1)
		{
			SetFocusCell(GetFocusCell(), true);

			CPoint pt = point;
			ScreenToClient(&pt);

			if (pWnd==GetHeaderCtrl())
			{
				HDHITTESTINFO hdhti = {0};
				hdhti.pt = pt;
				hdhti.pt.x += GetScrollPos(SB_HORZ);
				::SendMessage(GetHeaderCtrl()->GetSafeHwnd(), HDM_HITTEST, 0, (LPARAM) &hdhti);
				strArgs.Format("local X=%d;local Y=%d;local nCol=%d",point.x,point.y,hdhti.iItem);
				pParent->m_pListCtrlObject->FireEvent("On ContextMenuHeader",strArgs);
			}
		}
	}
	//CGridListCtrlEx::OnContextMenu(pWnd, point);
}

//------------------------------------------------------------------------
//! LVN_COLUMNCLICK message handler called when clicking a column header.
//! Used to update the row sorting according to the clicked column.
//!
//! @param pNMHDR Pointer to an NMLISTVIEW structure specifying the column
//! @param pResult Not used
//! @return Is final message handler (Return FALSE to continue routing the message)
//------------------------------------------------------------------------
BOOL CCustomListCtrl::OnHeaderClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLISTVIEW* pLV = reinterpret_cast<NMLISTVIEW*>(pNMHDR);

	if( GetFocus() != this )
		SetFocus();	// Force focus to finish editing

	CControlHolderWnd* pParent = (CControlHolderWnd*) GetParent();

	if(pParent)
	{
		CString strArgs;
		strArgs.Format("local nCol=%d",pLV->iSubItem);
		pParent->m_pListCtrlObject->FireEvent("On HeaderClick",strArgs);
	}
	
	return FALSE;	// Let parent-dialog get chance
}