#include "StdAfx.h"
#include "ListCtrl.h"
#include "PropertiesDlg.h"

CPropertiesDlg::CPropertiesDlg(CWnd* pParent /*=NULL*/)
: CDialog(CPropertiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPropertiesDlg)
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
	//}}AFX_DATA_INIT
	//
	m_EmptyMarkupText = "There are no items to show in this view.";

	m_strHelpPath.Empty();
}

CPropertiesDlg::~CPropertiesDlg(void)
{
}

void CPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX,IDC_CHECK_STYLE,m_nCheckBox);
	DDX_Check(pDX,IDC_ENABLE_TOOLTIP,m_nTooltipCtrl);
	DDX_Check(pDX,IDC_HEADERDRAGDROP, m_nHeaderDragDrop);
	DDX_Check(pDX,IDC_FULLROWSELECT,m_nFullRowSelect);
	DDX_Check(pDX,IDC_GRIDLINES,m_nGridLines);
	DDX_Control(pDX,IDC_BACKGROUND_COLOR,c_btnBackGroundColor);
	DDX_ColourPicker(pDX,IDC_BACKGROUND_COLOR,m_BackgroundColor);
	DDX_Control(pDX,IDC_CELL_TEXT_COLOR,c_btnCellTextColor);
	DDX_ColourPicker(pDX,IDC_CELL_TEXT_COLOR,m_CellTextColor);
	DDX_Control(pDX,IDC_CELL_BACK_COLOR,c_btnCellBackColor);
	DDX_ColourPicker(pDX,IDC_CELL_BACK_COLOR,m_CellBackColor);
	DDX_Text(pDX,IDC_TOOLTIP_TEXT,m_TooltipText);
	DDX_Text(pDX,IDC_TOOLTIP_TITLE_TEXT,m_TooltipTitleText);
	DDX_Text(pDX,IDC_EMPTY_MARKUP_TEXT,m_EmptyMarkupText);
	//{{AFX_DATA_MAP(CPropertiesDlg)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CPropertiesDlg)
	ON_BN_CLICKED(IDC_BTN_HELP, OnBtnHelp)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_FONT_BUTTON, &CPropertiesDlg::OnBnClickedFontButton)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg message handlers

BOOL CPropertiesDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPropertiesDlg::OnBtnHelp() 
{
	// TODO: Add your control notification handler code here
	if(GetFileAttributes(m_strHelpPath) != -1)
	{
		ShellExecute(m_hWnd,"open",m_strHelpPath,NULL,NULL,SW_NORMAL);
	}
}

void CPropertiesDlg::OnBnClickedFontButton()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

	// get font for current dialog, just to fill in LOGFONT
	LOGFONT lf;
	CFont *pFont = GetFont();
	pFont->GetLogFont(&lf);

	// use last font height
	lf.lfHeight = m_nHeight;
	lf.lfWidth = m_nWidth;
	lf.lfEscapement = m_nEscapement;
	lf.lfOrientation = m_nOrientation;
	lf.lfWeight = m_nWeight;
	lf.lfItalic = m_bItalic;
	lf.lfUnderline = m_bUnderline;
	lf.lfStrikeOut = m_bStrikeOut;
	lf.lfCharSet = m_bCharSet;
	lf.lfOutPrecision = m_bOutPrecision;
	lf.lfClipPrecision = m_bClipPrecision;
	lf.lfQuality = m_bQuality;
	lf.lfPitchAndFamily = m_bPitchAndFamily;
	// use last face name
	_tcscpy(lf.lfFaceName, m_strFaceName);

	// display CFontDialog
	CFontDialog dlg(&lf);
	//dlg.m_cf.rgbColors = m_TextColor;
	//if (m_nFonts == 3)
	//dlg.m_cf.Flags |= CF_NOSCRIPTSEL;		// disable the script combo

	if (dlg.DoModal() == IDOK)
	{
		dlg.GetCurrentFont(&lf);
		m_nHeight = lf.lfHeight;
		m_strFaceName = lf.lfFaceName;
		m_nWidth = lf.lfWidth;
		m_nEscapement = lf.lfEscapement;
		m_nOrientation = lf.lfOrientation;
		m_nWeight = lf.lfWeight;
		m_bItalic = lf.lfItalic;
		m_bUnderline = lf.lfUnderline;
		m_bStrikeOut = lf.lfStrikeOut;
		m_bCharSet = lf.lfCharSet;
		m_bOutPrecision = lf.lfOutPrecision;
		m_bClipPrecision = lf.lfClipPrecision;
		m_bQuality = lf.lfQuality;
		m_bPitchAndFamily = lf.lfPitchAndFamily;
		//m_TextColor = dlg.GetColor();
	}
	// TODO: Add your control notification handler code here
}
