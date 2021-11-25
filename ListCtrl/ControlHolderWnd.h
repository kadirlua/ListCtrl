#pragma once
#include "afxwin.h"
#include "IRPluginObject.h"
#include "CustomListCtrl.h"

#include "CGridListCtrlEx\CGridColumnTraitDateTime.h"
#include "CGridListCtrlEx\CGridColumnTraitEdit.h"
#include "CGridListCtrlEx\CGridColumnTraitCombo.h"
#include "CGridListCtrlEx\CGridColumnTraitHyperLink.h"
#include "CGridListCtrlEx\CGridRowTraitXP.h"
#include "CGridListCtrlEx\ViewConfigSection.h"
#include "CGridListCtrlEx\CGridColumnTraitMultilineEdit.h"
#include "CGridListCtrlEx\CGridColumnTraitMaskedEdit.h"

#define ID_LIST_WINDOW 78654

class CControlHolderWnd :
	public CWnd
{
public:
	CControlHolderWnd(void);
	~CControlHolderWnd(void);
public:
	CCustomListCtrl* m_pListCtrl;
	void DestroyListCtrl();
	void PositionChild();

	CIRPluginObject* m_pListCtrlObject;
	void DoAutoTab(BOOL bNextField);

	BOOL m_bIsDesignTime;
	BOOL m_bEnabledRT;
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
