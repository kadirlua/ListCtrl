#include "StdAfx.h"
#include "ControlHolderWnd.h"

CControlHolderWnd::CControlHolderWnd(void)
{
	m_pListCtrl = NULL;
	m_pListCtrlObject = NULL;
	m_bIsDesignTime = TRUE;
	m_bEnabledRT = TRUE;
}

CControlHolderWnd::~CControlHolderWnd(void)
{
	DestroyListCtrl();
}

BEGIN_MESSAGE_MAP(CControlHolderWnd, CWnd)
	//{{AFX_MSG_MAP(CControlHolderWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CControlHolderWnd message handlers
void CControlHolderWnd::DestroyListCtrl()
{
	if(m_pListCtrl)
	{
		if(IsWindow(m_pListCtrl->m_hWnd))
		{
			m_pListCtrl->ShowWindow(SW_HIDE);
			m_pListCtrl->DestroyWindow();
		}

		delete m_pListCtrl;
		m_pListCtrl = NULL;
	}
}

int CControlHolderWnd::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	
	// TODO: Add your specialized creation code here

	DWORD dwStyle = WS_CHILD|LVS_REPORT|WS_VISIBLE|LVS_ALIGNLEFT |WS_BORDER;

	if(m_bIsDesignTime == FALSE)
	{
		if(m_bEnabledRT == FALSE)
		{
			dwStyle |= WS_DISABLED;
		}
	}
	
	m_pListCtrl = new CCustomListCtrl;
	if(!m_pListCtrl->Create(dwStyle,CRect(0,0,0,0),this,ID_LIST_WINDOW))
	{
		return -1;
	}
	//m_pListCtrl->SetExtendedStyle(m_pListCtrl->GetExtendedStyle()|LVS_EX_LABELTIP|LVS_EX_INFOTIP);
	HWND header = ListView_GetHeader(m_pListCtrl->m_hWnd);
	DWORD dwHeaderStyle = ::GetWindowLong(header, GWL_STYLE);
	dwHeaderStyle |= HDS_CHECKBOXES;
	::SetWindowLong(header, GWL_STYLE, dwHeaderStyle);
	return 0;
}

void CControlHolderWnd::PositionChild()
{
	if(!m_pListCtrl) return;
	if(!IsWindow(m_pListCtrl->m_hWnd)) return;

	CRect rcClient;
	GetClientRect(&rcClient);

	m_pListCtrl->MoveWindow(&rcClient);
}

void CControlHolderWnd::OnSize(UINT nType, int cx, int cy) 
{
	CWnd::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	PositionChild();	
}

void CControlHolderWnd::DoAutoTab(BOOL bNextField)
{
	if(m_pListCtrlObject)
	{
		IRLUA_PLUGIN_DoAutoTab(m_pListCtrlObject->m_pLuaState,bNextField);
	}
}