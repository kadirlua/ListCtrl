#include "StdAfx.h"
#include "ListCtrlObject.h"
#include "LuaFunctions.h"
#include "PropertiesDlg.h"
#include "Token.h"

CListCtrlObject::CListCtrlObject(void)
{
	for(int i = 0; i < NUM_OB_EVENTS; i++)
		m_pEvents[i] = NULL;

	m_pEvents[0] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[0]->m_szName,"On CellColor");
	lstrcpy(m_pEvents[0]->m_szArgs,"number row, number col");

	m_pEvents[1] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[1]->m_szName,"On KeyDown");
	lstrcpy(m_pEvents[1]->m_szArgs,"number e_Key, table e_Modifiers");

	m_pEvents[2] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[2]->m_szName,"On Focus");
	lstrcpy(m_pEvents[2]->m_szArgs,"");

	m_pEvents[3] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[3]->m_szName,"On HeaderCheckBox");
	lstrcpy(m_pEvents[3]->m_szArgs,"number nCol, boolean bChecked");

	m_pEvents[4] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[4]->m_szName,"On RightClick");
	lstrcpy(m_pEvents[4]->m_szArgs,"number X, number Y");

	m_pEvents[5] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[5]->m_szName,"On ToolNeedText");
	lstrcpy(m_pEvents[5]->m_szArgs,"number row, number col");

	m_pEvents[6] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[6]->m_szName,"On KillFocus");
	lstrcpy(m_pEvents[6]->m_szArgs,"");

	m_pEvents[7] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[7]->m_szName,"On Click");
	lstrcpy(m_pEvents[7]->m_szArgs,"");

	m_pEvents[8] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[8]->m_szName,"On DoubleClick");
	lstrcpy(m_pEvents[8]->m_szArgs,"");

	m_pEvents[9] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[9]->m_szName,"On ContextMenuHeader");
	lstrcpy(m_pEvents[9]->m_szArgs,"number X, number Y, number nCol");

	m_pEvents[10] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[10]->m_szName,"On GroupMenuHeader");
	lstrcpy(m_pEvents[10]->m_szArgs,"number X, number Y, number nGroupID");

	m_pEvents[11] = new IRPluginEventInfo;
	lstrcpy(m_pEvents[11]->m_szName,"On HeaderClick");
	lstrcpy(m_pEvents[11]->m_szArgs,"number nCol");

	lstrcpy(m_szObjectID,"IR_LISTCTRL_OBJECT");

	m_pListCtrlHolder = NULL;

	m_nCheckBox = BST_CHECKED;
	m_nHeaderDragDrop = BST_CHECKED;
	m_nFullRowSelect = BST_CHECKED;
	m_nGridLines = BST_UNCHECKED;
	m_nTooltipCtrl = BST_CHECKED;
	//Font
	m_strFaceName = "Arial";
	m_nHeight = 12;
	m_nWidth = 0;
	m_nEscapement = 0;
	m_nOrientation = 0;
	m_nWeight = FW_NORMAL;
	m_bItalic = FALSE;
	m_bUnderline = FALSE;
	m_bStrikeOut = 0;
	m_bCharSet = ANSI_CHARSET;
	m_bOutPrecision = OUT_DEFAULT_PRECIS;
	m_bClipPrecision = CLIP_DEFAULT_PRECIS;
	m_bQuality = DEFAULT_QUALITY;
	m_bPitchAndFamily = DEFAULT_PITCH | FF_SWISS;

	m_BackgroundColor = RGB(255,255,255);
	m_CellTextColor = RGB(0,0,0);
	m_CellBackColor = RGB(255,255,255);

	//Tooltip
	m_TooltipText = "";
	m_TooltipTitleText = "";

	m_EmptyMarkupText = "There are no items to show in this view.";
}

CListCtrlObject::~CListCtrlObject(void)
{
	for(int i = 0; i < NUM_OB_EVENTS; i++)
	{
		delete m_pEvents[i];
		m_pEvents[i] = NULL;
	}

	DestroyListCtrl();
}

void CListCtrlObject::DestroyListCtrl()
{
	if(m_pListCtrlHolder)
	{
		if(IsWindow(m_pListCtrlHolder->m_hWnd))
		{
			m_pListCtrlHolder->ShowWindow(SW_HIDE);
			m_pListCtrlHolder->DestroyWindow();
		}

		delete m_pListCtrlHolder;
		m_pListCtrlHolder = NULL;
	}
}

HWND CListCtrlObject::GetWindowHandle()
{
	if(m_pListCtrlHolder)
	{
		if(IsWindow(m_pListCtrlHolder->m_hWnd))
		{
			//To work with sizing
			return m_pListCtrlHolder->m_hWnd;
			/*
			if(m_pSliderHolder->m_pSliderCtrl)
			{
				if(IsWindow(m_pSliderHolder->m_pSliderCtrl->m_hWnd))
				{
					return m_pSliderHolder->m_pSliderCtrl->m_hWnd;
				}
			}
			*/
		}
	} 
	return NULL;
}

void CListCtrlObject::DrawDesign(HDC hDC, HWND hMainWnd, RECT rcObRect,BOOL bVisible,BOOL bEnabled)
{
	if(bVisible)
	{
		bEnabled = FALSE; // Always disabled at design-time

		if(!m_pListCtrlHolder)
			m_pListCtrlHolder = new CControlHolderWnd;
		
		m_pListCtrlHolder->m_bIsDesignTime = TRUE;

		DWORD dwStyle;

		dwStyle = WS_CHILD|WS_VISIBLE;
		if(!bEnabled)
		{
			dwStyle |= WS_DISABLED;
		}

		if(!IsWindow(m_pListCtrlHolder->m_hWnd))
		{
			if(!m_pListCtrlHolder->Create(NULL,"ir_ListCtrl",dwStyle,rcObRect,CWnd::FromHandle(hMainWnd),
				6262))
			{
				DestroyListCtrl();
				return;
			} else
			{
				m_font.DeleteObject();
			   m_font.CreateFont(
			   m_nHeight,                        // nHeight
			   m_nWidth,                         // nWidth
			   m_nEscapement,                         // nEscapement
			   m_nOrientation,                         // nOrientation
			   m_nWeight,                 // nWeight
			   m_bItalic,                     // bItalic
			   m_bUnderline,                     // bUnderline
			   m_bStrikeOut,                         // cStrikeOut
			   m_bCharSet,              // nCharSet
			   m_bOutPrecision,        // nOutPrecision
			   m_bClipPrecision,       // nClipPrecision
			   m_bQuality,           // nQuality
			   m_bPitchAndFamily,  // nPitchAndFamily
			   m_strFaceName);
				m_pListCtrlHolder->m_pListCtrlObject = this;
				m_pListCtrlHolder->m_pListCtrl->SetEmptyMarkupText(m_EmptyMarkupText);
				m_pListCtrlHolder->m_pListCtrl->SetBkColor(m_BackgroundColor);
				m_pListCtrlHolder->m_pListCtrl->SetFont(&m_font,TRUE);
				m_font.DeleteObject();
			}
		}

		m_pListCtrlHolder->MoveWindow(&rcObRect);
	} else
	{
		DestroyListCtrl();
	}
}

void CListCtrlObject::DrawRuntime(HDC hDC, HWND hMainWnd, RECT rcObRect,BOOL bVisible,BOOL bEnabled)
{
	if(!m_pListCtrlHolder)
		m_pListCtrlHolder = new CControlHolderWnd;

	m_pListCtrlHolder->m_bIsDesignTime = FALSE;
	m_pListCtrlHolder->m_bEnabledRT = bEnabled;

	DWORD dwStyle;

	dwStyle = WS_CHILD;
	
	if(bVisible)
	{
		dwStyle |= WS_VISIBLE;
	}

	if(!IsWindow(m_pListCtrlHolder->m_hWnd))
	{
		if(!m_pListCtrlHolder->Create(NULL,"ir_ListCtrl",dwStyle,rcObRect,CWnd::FromHandle(hMainWnd),
			6262))
		{
			DestroyListCtrl();
			return;
		} else
		{
			m_font.DeleteObject();
			   m_font.CreateFont(
			   m_nHeight,                        // nHeight
			   m_nWidth,                         // nWidth
			   m_nEscapement,                         // nEscapement
			   m_nOrientation,                         // nOrientation
			   m_nWeight,                 // nWeight
			   m_bItalic,                     // bItalic
			   m_bUnderline,                     // bUnderline
			   m_bStrikeOut,                         // cStrikeOut
			   m_bCharSet,              // nCharSet
			   m_bOutPrecision,        // nOutPrecision
			   m_bClipPrecision,       // nClipPrecision
			   m_bQuality,           // nQuality
			   m_bPitchAndFamily,  // nPitchAndFamily
			   m_strFaceName);
			m_pListCtrlHolder->m_pListCtrlObject = this;
			m_pListCtrlHolder->m_pListCtrl->SetEmptyMarkupText(m_EmptyMarkupText);
			m_pListCtrlHolder->m_pListCtrl->SetBkColor(m_BackgroundColor);
			m_pListCtrlHolder->m_pListCtrl->SetFont(&m_font,TRUE);
			m_pListCtrlHolder->m_pListCtrl->SetCellMargin(1.2);
			m_pListCtrlHolder->m_pListCtrl->SetCellBackColor(m_CellBackColor);
			m_pListCtrlHolder->m_pListCtrl->SetCellTextColor(m_CellTextColor);
			m_font.DeleteObject();
				if (m_nCheckBox == BST_CHECKED)
				{
					m_pListCtrlHolder->m_pListCtrl->SetExtendedStyle( m_pListCtrlHolder->m_pListCtrl->GetExtendedStyle() | LVS_EX_CHECKBOXES);
				}
				if (m_nHeaderDragDrop == BST_CHECKED)
				{
					m_pListCtrlHolder->m_pListCtrl->SetExtendedStyle( m_pListCtrlHolder->m_pListCtrl->GetExtendedStyle() | LVS_EX_HEADERDRAGDROP);
				}
				if (m_nFullRowSelect == BST_CHECKED)
				{
					m_pListCtrlHolder->m_pListCtrl->SetExtendedStyle( m_pListCtrlHolder->m_pListCtrl->GetExtendedStyle() | LVS_EX_FULLROWSELECT);
				}
				if (m_nGridLines == BST_CHECKED)
				{
					m_pListCtrlHolder->m_pListCtrl->SetExtendedStyle( m_pListCtrlHolder->m_pListCtrl->GetExtendedStyle() | LVS_EX_GRIDLINES);
				}
				CToolTipCtrl* pToolTipCtrl = (CToolTipCtrl*)CWnd::FromHandle((HWND)::SendMessage(m_pListCtrlHolder->m_pListCtrl->m_hWnd, LVM_GETTOOLTIPS, 0, 0L));
				//CToolTipCtrl* pToolTipCtrl = AfxGetModuleThreadState()->m_pToolTip;
				if (pToolTipCtrl!=NULL && pToolTipCtrl->m_hWnd!=NULL)
				{
					if (m_nTooltipCtrl == BST_CHECKED)
					pToolTipCtrl->Activate(TRUE);
					else
					pToolTipCtrl->Activate(FALSE);
				}
				m_pListCtrlHolder->m_pListCtrl->SetTooltipText(m_TooltipText);
				m_pListCtrlHolder->m_pListCtrl->SetTooltipTitle(m_TooltipTitleText);
		}
	}

	m_pListCtrlHolder->MoveWindow(&rcObRect);

	ShowWindow(bVisible);
}

void CListCtrlObject::ShowWindow(BOOL bVisible)
{
	if(bVisible)
	{
		if(m_pListCtrlHolder)
		{
			if(m_pListCtrlHolder->m_pListCtrl)
			{
				if(IsWindow(m_pListCtrlHolder->m_pListCtrl->m_hWnd))
				{
					m_pListCtrlHolder->m_pListCtrl->ShowWindow(SW_SHOW);
				}
			}
			if(IsWindow(m_pListCtrlHolder->m_hWnd))
			{
				m_pListCtrlHolder->ShowWindow(SW_SHOW);
			}
		}
	} else
	{
		if(m_pListCtrlHolder)
		{
			if(m_pListCtrlHolder->m_pListCtrl)
			{
				if(IsWindow(m_pListCtrlHolder->m_pListCtrl->m_hWnd))
				{
					m_pListCtrlHolder->m_pListCtrl->ShowWindow(SW_HIDE);
				}
			}
			if(IsWindow(m_pListCtrlHolder->m_hWnd))
			{
				m_pListCtrlHolder->ShowWindow(SW_HIDE);
			}
		}
	}
}

int CListCtrlObject::GetCustomProperties(char* szBuffer, int* pnBufferSize)
{
	memset(m_szPropertiesString,0,1000);

	wsprintf(m_szPropertiesString,"%d,%d,%d,%d,%d,%s,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%u,%u,%u,%s,%s,%s",
		m_nCheckBox,m_nHeaderDragDrop,m_nFullRowSelect,m_nGridLines,m_nTooltipCtrl,m_strFaceName,m_nHeight,m_nWidth,m_nEscapement,m_nOrientation,m_nWeight,m_bItalic,m_bUnderline,m_bStrikeOut,m_bCharSet,m_bOutPrecision,m_bClipPrecision,m_bQuality,m_bPitchAndFamily,m_BackgroundColor,m_CellBackColor,m_CellTextColor,m_TooltipText,m_TooltipTitleText,m_EmptyMarkupText);
	
	int nLength = lstrlen(m_szPropertiesString);
	if(*pnBufferSize < nLength)
	{
		*pnBufferSize = nLength;
		return -1;
	} else
	{
		memset(szBuffer,0,*pnBufferSize);
		lstrcpy(szBuffer,m_szPropertiesString);
		return nLength;
	}
}

void CListCtrlObject::SetCustomProperties(char* szPropsList)
{
	int nTokens = 0;

	CToken tok(szPropsList);
	tok.SetToken(",");

	while(tok.MoreTokens())
	{
		switch(nTokens)
		{
			case 0: // Minimum
				m_nCheckBox = atoi(tok.GetNextToken());
				break;
			case 1:
				m_nHeaderDragDrop = atoi(tok.GetNextToken());
				break;
			case 2:
				m_nFullRowSelect = atoi(tok.GetNextToken());
				break;
			case 4:
				m_nGridLines = atoi(tok.GetNextToken());
				break;
			case 5:
				m_nTooltipCtrl = atoi(tok.GetNextToken());
				break;
			case 6:
				m_strFaceName = tok.GetNextToken();
				break;
			case 7:
				m_nHeight = atoi(tok.GetNextToken());
				break;
			case 8:
				m_nWidth = atoi(tok.GetNextToken());
				break;
			case 9:
				m_nEscapement = atoi(tok.GetNextToken());
				break;
			case 10:
				m_nOrientation = atoi(tok.GetNextToken());
				break;
			case 11:
				m_nWeight = atoi(tok.GetNextToken());
				break;
			case 12:
				m_bItalic = atoi(tok.GetNextToken());
				break;
			case 13:
				m_bUnderline = atoi(tok.GetNextToken());
				break;
			case 14:
				m_bStrikeOut = atoi(tok.GetNextToken());
				break;
			case 15:
				m_bCharSet = atoi(tok.GetNextToken());
				break;
			case 16:
				m_bOutPrecision = atoi(tok.GetNextToken());
				break;
			case 17:
				m_bClipPrecision = atoi(tok.GetNextToken());
				break;
			case 18:
				m_bQuality = atoi(tok.GetNextToken());
				break;
			case 19:
				m_bPitchAndFamily = atoi(tok.GetNextToken());
				break;
			case 20:
				m_BackgroundColor = atol(tok.GetNextToken());
				break;
			case 21:
				m_CellBackColor = atol(tok.GetNextToken());
				break;
			case 22:
				m_CellTextColor = atol(tok.GetNextToken());
				break;
			case 23:
				m_TooltipText = tok.GetNextToken();
				break;
			case 24:
				m_TooltipTitleText = tok.GetNextToken();
				break;
			case 25:
				m_EmptyMarkupText = tok.GetNextToken();
			default: break;
		}

		nTokens++;
	}
}

void CListCtrlObject::DoSetFocus()
{
	if(m_pListCtrlHolder)
	{
		if(IsWindow(m_pListCtrlHolder->m_hWnd))
		{
			if(m_pListCtrlHolder->m_pListCtrl)
			{
				if(IsWindow(m_pListCtrlHolder->m_pListCtrl->m_hWnd))
				{
					m_pListCtrlHolder->m_pListCtrl->SetFocus();
				}
			}
		}
	}
}

void CListCtrlObject::HideInternalObject()
{
	DestroyListCtrl();
}

BOOL CListCtrlObject::ShowProperties(char* szPluginFolder)
{
	CPropertiesDlg dlgProps;
	BOOL bRet;
	CString strHelpFile;

	strHelpFile.Format("%s",szPluginFolder);
	strHelpFile.TrimRight("\\");
	strHelpFile += "\\ListCtrl_Help.htm";

	dlgProps.m_nCheckBox = m_nCheckBox;
	dlgProps.m_nHeaderDragDrop = m_nHeaderDragDrop;
	dlgProps.m_nFullRowSelect = m_nFullRowSelect;
	dlgProps.m_nGridLines = m_nGridLines;
	dlgProps.m_nTooltipCtrl = m_nTooltipCtrl;
	dlgProps.m_strFaceName = m_strFaceName;
	dlgProps.m_nHeight = m_nHeight;
    dlgProps.m_nWidth = m_nWidth;
	dlgProps.m_nEscapement = m_nEscapement;
	dlgProps.m_nOrientation = m_nOrientation;
	dlgProps.m_nWeight = m_nWeight;
	dlgProps.m_bItalic = m_bItalic;
	dlgProps.m_bUnderline = m_bUnderline;
	dlgProps.m_bStrikeOut = m_bStrikeOut;
	dlgProps.m_bCharSet = m_bCharSet;
	dlgProps.m_bOutPrecision = m_bOutPrecision;
	dlgProps.m_bClipPrecision = m_bClipPrecision;
	dlgProps.m_bQuality = m_bQuality;
	dlgProps.m_bPitchAndFamily = m_bPitchAndFamily;
	dlgProps.m_BackgroundColor = m_BackgroundColor;
	dlgProps.m_CellBackColor = m_CellBackColor;
	dlgProps.m_CellTextColor = m_CellTextColor;
	dlgProps.m_strHelpPath = strHelpFile;
	dlgProps.m_TooltipText = m_TooltipText;
	dlgProps.m_TooltipTitleText = m_TooltipTitleText;
	dlgProps.m_EmptyMarkupText = m_EmptyMarkupText;

	if(dlgProps.DoModal() == IDOK)
	{
		bRet = TRUE;

		m_nCheckBox = dlgProps.m_nCheckBox;
		m_nHeaderDragDrop = dlgProps.m_nHeaderDragDrop;
		m_nFullRowSelect = dlgProps.m_nFullRowSelect;
		m_nGridLines = dlgProps.m_nGridLines;
		m_nTooltipCtrl = dlgProps.m_nTooltipCtrl;
		m_strFaceName = dlgProps.m_strFaceName;
		m_nHeight = dlgProps.m_nHeight;
		m_nWidth = dlgProps.m_nWidth;
		m_nEscapement = dlgProps.m_nEscapement;
		m_nOrientation = dlgProps.m_nOrientation;
		m_nWeight = dlgProps.m_nWeight;
		m_bItalic = dlgProps.m_bItalic;
		m_bUnderline = dlgProps.m_bUnderline;
		m_bStrikeOut = dlgProps.m_bStrikeOut;
		m_bCharSet = dlgProps.m_bCharSet;
		m_bOutPrecision = dlgProps.m_bOutPrecision;
		m_bClipPrecision = dlgProps.m_bClipPrecision;
		m_bQuality = dlgProps.m_bQuality;
		m_bPitchAndFamily = dlgProps.m_bPitchAndFamily;
		m_BackgroundColor = dlgProps.m_BackgroundColor;
		m_CellBackColor = dlgProps.m_CellBackColor;
		m_CellTextColor = dlgProps.m_CellTextColor;
		m_TooltipText = dlgProps.m_TooltipText;
		m_TooltipTitleText = dlgProps.m_TooltipTitleText;
		m_EmptyMarkupText = dlgProps.m_EmptyMarkupText;
	} else
	{
		bRet = FALSE;
	}

	return bRet;
}

BOOL CListCtrlObject::GetEvent(int nIndex, IRPluginEventInfo* pEventInfo)
{
	if((nIndex >= 0) && nIndex < NUM_OB_EVENTS)
	{
		if(m_pEvents[nIndex])
		{
			lstrcpy(pEventInfo->m_szName,m_pEvents[nIndex]->m_szName);
			lstrcpy(pEventInfo->m_szArgs,m_pEvents[nIndex]->m_szArgs);
			return TRUE;
		} else
		{
			return FALSE;
		}
	} else
	{
		return NULL;
	}
}

int CListCtrlObject::GetNumEvents()
{
	return NUM_OB_EVENTS;
}

int CListCtrlObject::RegisterLUAFunctions(lua_State* L)
{
	// Always call base class first
	CIRPluginObject::RegisterLUAFunctions(L);

	ListCtrl_RegisterLuaFunctions(L);

	return 0;
}