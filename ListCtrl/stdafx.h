// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently

#pragma once

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // Exclude rarely-used stuff from Windows headers
#endif

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // some CString constructors will be explicit

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>         // MFC OLE classes
#include <afxodlgs.h>       // MFC OLE dialog classes
#include <afxdisp.h>        // MFC Automation classes
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>                      // MFC ODBC database classes
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>                     // MFC DAO database classes
#endif // _AFX_NO_DAO_SUPPORT

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC support for Internet Explorer 4 Common Controls
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

#include "lua.hpp"

#define USE_PLUGIN_LIB
#include "IRPluginHelperFunctions.h"

#if _MSC_VER >= 1400
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif

#ifndef UNICODE
#define CGRIDLISTCTRLEX_GROUPMODE
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#pragma warning( disable:4514 )	// warning C4514: unreferenced inline function has been remove
#pragma warning( disable:4710 )	// warning C4710: function not inlined
#pragma warning( disable:4711 )	// warning C4711: function selected for automatic inline expansion
#pragma warning( disable:4820 )	// warning C4820: X bytes padding added after data member

#pragma warning( push )
#pragma warning( disable:4548 )	// warning C4548: expression before comma has no effect; expected expression with side-effect
#pragma warning( disable:4812 )	// warning C4812: obsolete declaration style: please use '_CIP<_Interface,_IID>::_CIP' instead
#pragma warning( disable:4996 )	// warning C4996: This function or variable may be unsafe.
#pragma warning( disable:4005 )	// warning C4005: '_WIN32_WINDOWS' : macro redefinition
#pragma warning( disable:4668 )	// warning C4668: '__midl' is not defined as a preprocessor macro, replacing with '0' for '#if/#elif'
#pragma warning( disable:4820 )	// warning C4820: X bytes padding added after data member
#pragma warning( disable:4619 )	// warning C4619: #pragma warning : there is no warning number
#pragma warning( disable:4625 )	// warning C4625: copy constructor could not be generated because a base class copy constructor is inaccessible
#pragma warning( disable:4626 )	// warning C4626: assignment operator could not be generated because a base class assignment operator is inaccessible
#pragma warning( disable:4365 )	// warning C4365: '=' : conversion from 'int' to 'size_t', signed/unsigned mismatch
#pragma warning( disable:4244 )	// warning C4244: 'return' : conversion from 'const time_t' to 'LONG_PTR', possible loss of data
#pragma warning( disable:4263 )	// warning C4263: member function does not override any base class virtual member function
#pragma warning( disable:4264 )	// warning C4264: no override available for virtual member function from base; function is hidden
#pragma warning( disable:4917 )	// warning C4917: a GUID can only be associated with a class, interface or namespace
#pragma warning( disable:4555 )	// warning C4555: expression has no effect; expected expression with side-effect
#pragma warning( disable:4640 )	// warning C4640: construction of local static object is not thread-safe
#pragma warning( disable:4571 )	// warning C4571: Informational: catch(...) semantics changed since Visual C++ 7.1; structured exceptions (SEH) are no longer caught

#pragma warning( pop )

#include <string>
#include <vector>
#include <algorithm>

using namespace std;