// ListCtrl.h : main header file for the ListCtrl DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CListCtrlApp
// See ListCtrl.cpp for the implementation of this class
//

class CListCtrlApp : public CWinApp
{
public:
	CListCtrlApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
