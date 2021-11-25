#pragma once
#include "CGridListCtrlEx\CGridListCtrlGroups.h"
#include <comdef.h>  // for _bstr_t

class CCustomListCtrl :
	public CGridListCtrlGroups
{
public:
	CCustomListCtrl(void);
	virtual ~CCustomListCtrl(void);
protected:
	CString SetHeaderCheckbox(int nItem);
	bool OnDisplayCellColor(int nRow, int nCol, COLORREF& textColor, COLORREF& backColor);
	afx_msg void OnRButtonDown(UINT nFlags,CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg BOOL OnHeaderItemStateIconClick(UINT id, NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg BOOL OnToolNeedText(UINT, NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd*, CPoint point);
	afx_msg BOOL OnHeaderClick(NMHDR* pNMHDR, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
};
