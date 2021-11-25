#pragma once
#include "afxwin.h"
#include "resource.h"
#include "ColourPicker.h"

class CPropertiesDlg :
	public CDialog
{
public:
	CPropertiesDlg(CWnd* pParent =NULL);
	~CPropertiesDlg(void);
	enum { IDD = IDD_PROPERTIES };
	int m_nCheckBox;
	int m_nHeaderDragDrop;
	int m_nFullRowSelect;
	int m_nGridLines;
	int m_nTooltipCtrl;
	CString m_strHelpPath;
	//Font
	CFont m_font;
	CString m_strFaceName;
	int m_nHeight;
	int m_nWidth;
	int m_nEscapement;
	int m_nOrientation;
	int m_nWeight;
	BYTE m_bItalic;
	BYTE m_bUnderline;
	BYTE m_bStrikeOut;
	BYTE m_bCharSet;
	BYTE m_bOutPrecision;
	BYTE m_bClipPrecision;
	BYTE m_bQuality;
	BYTE m_bPitchAndFamily;
	//BackGround color
	CColourPicker c_btnBackGroundColor;
	COLORREF m_BackgroundColor;
	//Cell text color
	CColourPicker c_btnCellTextColor;
	COLORREF m_CellTextColor;
	//Cell back color
	CColourPicker c_btnCellBackColor;
	COLORREF m_CellBackColor;
	//Tooltip
	CString m_TooltipText;
	CString m_TooltipTitleText;
	CString m_EmptyMarkupText;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPropertiesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedFontButton();
};
