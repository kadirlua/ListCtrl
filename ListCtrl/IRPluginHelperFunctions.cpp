#include "stdafx.h"
#include "IRPluginHelperFunctions.h"
#include <io.h>

#ifdef LUA_VERSION

/*

Function:	IRLUA_PLUGIN_SetLastError
Purpose:	Sets the last error value in the runtime engine.
			This value can then be retrieved using the aciton
			Application.GetLastError. This functions should
			be called at the end of your functions.
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
			nCode - The actual error code to set. Note that
				setting the error code to 0 signifies that
				there was no error and anything else signifies
				that the last action produced an error.
Returns:	Nothing.

*/


void IRLUA_PLUGIN_SetLastError(lua_State *luaState,int nCode)
{
	// Find the Application.SetLastError function
	lua_getglobal(luaState,"Application");
	lua_pushstring(luaState,"SetLastError");
	lua_gettable(luaState,-2);
	lua_remove(luaState,-2);

	if(lua_isfunction(luaState,-1))
	{
		// Push the error code argument onto the stack
		lua_pushnumber(luaState,nCode);

		// Call the function
		if(lua_pcall(luaState,1,0,0) != 0)
		{
			// Error, remove the error message string
			// from the stack
			lua_remove(luaState,-1);
		}
	} else
	{
		// Take the value off of the stack because we will not
		// be using it
		lua_remove(luaState,-1);
	}
}

/*

Function:	IRLUA_PLUGIN_ResetLastError
Purpose:	Resets the last error value in the runtime
			engine back to 0. This should be called at the
			begginning of your functions.
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
Returns:	Nothing.

*/
void IRLUA_PLUGIN_ResetLastError(lua_State *luaState)
{
	// Find the Application.ResetLastError function
	lua_getglobal(luaState,"Application");
	lua_pushstring(luaState,"ResetLastError");
	lua_gettable(luaState,-2);
	lua_remove(luaState,-2);

	if(lua_isfunction(luaState,-1))
	{
		if(lua_pcall(luaState,0,0,0) != 0)
		{
			// Error, remove the error message string
			// from the stack
			lua_remove(luaState,-1);
		}
	} else
	{
		// Take the value off of the stack because we will not
		// be using it
		lua_remove(luaState,-1);
	}
}

/*

Function:	IR_PLUGIN_GetTextFromResourceFile
Purpose:	Reads text from a resource file in the current module (DLL)
			and returns is. This function is usually used to read the
			Action XML file.

			** NOTE: This functions uses MFC and should be commented out or
			removed from projects that do not link to MFC. **
Arguments:	lpszType - The type of resource being loaded.  Usually "TEXTFILE"
			nResourceID - The resource ID of the text resource to load
			szBuffer - The buffer that will receive the text data
			nBufferSize - The size of szBuffer
Returns:	TRUE if it succeeds or FALSE if not

*/
bool IR_PLUGIN_GetTextFromResourceFile(LPCTSTR lpszType, UINT nResourceID, char* szBuffer, int nBufferSize)
{
	bool bRet = TRUE;
	char* pszTemp;

	if(bRet)
	{
		memset(szBuffer,0,nBufferSize);
		HRSRC hRscr;
		HGLOBAL hGlobal;

		hRscr = FindResource(AfxGetResourceHandle(), MAKEINTRESOURCE(nResourceID),lpszType);
		if(hRscr)
		{
			hGlobal = LoadResource(AfxGetResourceHandle(), hRscr);
			if(hGlobal) 
			{
				pszTemp = (char*)LockResource(hGlobal);
				if(lstrlen(pszTemp) > nBufferSize)
				{
					bRet = FALSE;
				} else
				{
					lstrcpy(szBuffer,pszTemp);
					bRet = TRUE;
				}
				DeleteObject((HGDIOBJ)hGlobal);
			} else
			{
				bRet = FALSE;
			}
		} else
		{
			bRet = FALSE;
		}
	}

	return bRet;
}

/*

Function:	IRLUA_PLUGIN_SetGlobalErrorMessage
Purpose:	Sets a global error message in the runtime engine.
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
			nCode - The error code
			szMessage - The error message
Returns:	Nothing.
Example:

IRLUA_PLUGIN_SetGlobalErrorMessage(luaState, 5001, "Custom error message.");

*/
void IRLUA_PLUGIN_SetGlobalErrorMessage(lua_State *luaState, int nCode, LPCTSTR szMessage)
{
	lua_getglobal(luaState,"_tblErrorMessages");
	lua_pushnumber(luaState,nCode);
	lua_pushstring(luaState,szMessage);
	lua_settable(luaState,-3);
	lua_pop(luaState,1);
}

/*

Function:	IRLUA_PLUGIN_DoAutoTab
Purpose:	Used by object plugins to tell the runtime engine
			to tab to the next object capable of being tabbed to
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
			bNextTab - Whether to tab forward (TRUE) or backward (FALSE) in
				the tab order.
Returns:	Nothing.

*/
void IRLUA_PLUGIN_DoAutoTab(lua_State *luaState, BOOL bNextTab)
{
	// Call the "hidden" Page.DoAutoTab action...
	lua_getglobal(luaState,"Page");
	lua_pushstring(luaState,"DoAutoTab");
	lua_gettable(luaState,-2);
	lua_remove(luaState,-2);
	if(lua_isfunction(luaState,-1))
	{
		lua_pushboolean(luaState,bNextTab);
		if(lua_pcall(luaState,1,0,0) != 0)
		{
			// Error
			lua_remove(luaState,-1);
		}
	} else
	{
		lua_remove(luaState,-1);
	}
}

/*

Function:	IRLUA_PLUGIN_FormatSyntaxError
Purpose:	Formats an internal syntax error from your plugin to
			be the same as those produced by internal actions.
			This formatting includes the line number, etc.
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
			szErrorMsg - The syntax error message produced by your
				code.
			szFullMessage - The string that will be filled with the full
				formatted syntax error. This string should be IR_PLUGIN_MAX_FORMATTED_ERROR
				in length.
Returns:	Nothing.

*/
void IRLUA_PLUGIN_FormatSyntaxError(lua_State *luaState, char* szErrorMsg,
								   char* szFullMessage)
{
	// Call the "hidden" Debug.GetSyntaxErrorString action...
	lua_getglobal(luaState,"Debug");
	lua_pushstring(luaState,"GetSyntaxErrorString");
	lua_gettable(luaState,-2);
	lua_remove(luaState,-2);

	if(lua_isfunction(luaState,-1))
	{
		lua_pushstring(luaState,szErrorMsg);
		if(lua_pcall(luaState,1,1,0) != 0)
		{
			// Error
			lua_remove(luaState,-1);
		} else
		{
			// Success... formatted string on stack
			if(lstrlen(lua_tostring(luaState,-1)) < IR_PLUGIN_MAX_FORMATTED_ERROR)
			{
				lstrcpy(szFullMessage,lua_tostring(luaState,-1));
			} else
			{
				lstrcpy(szFullMessage,"Formatted error string is too long for buffer.");
			}
			lua_remove(luaState,-1);
		}
	} else
	{
		lua_remove(luaState,-1);
	}
}

/*

Function:	IRLUA_PLUGIN_CheckNumArgs
Purpose:	Checks the number of items currently on the Lua stack
			and throws a syntax error if there are not enough. This
			is useful for checking the number of arguments available
			to your aciton.
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
			nNumArgsRequired - The minimum number of argumenst required.
Returns:	Nothing.

*/
void IRLUA_PLUGIN_CheckNumArgs(lua_State* luaState, int nNumArgsRequired)
{
	char szBuffer[IR_PLUGIN_MAX_FORMATTED_ERROR];
	char szFinalError[IR_PLUGIN_MAX_FORMATTED_ERROR];
	if(lua_gettop(luaState) < nNumArgsRequired)
	{
		wsprintf(szBuffer,"%d arguments required.",nNumArgsRequired);
		IRLUA_PLUGIN_FormatSyntaxError(luaState,szBuffer,szFinalError);
		lua_pushstring(luaState,szFinalError);
		lua_error(luaState);
	}
}
				
/*

Function:	IRLUA_PLUGIN_CheckString
Purpose:	Checks the value at a given Lua stack position to see if it
			is a string. If not, it tries to convert it to a string. If
			it can't it throws a syntax error.
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
			nArg - The Lua stack position to check.
Returns:	A pointer to the string data.

*/
const char* IRLUA_PLUGIN_CheckString (lua_State *luaState, int nArg)
{
	char szBuffer[IR_PLUGIN_MAX_FORMATTED_ERROR];
	char szFinalError[IR_PLUGIN_MAX_FORMATTED_ERROR];
	const char *s = lua_tostring(luaState, nArg);
	if (!s)
	{
		wsprintf(szBuffer,"Argument %d must be a string.",nArg);
		IRLUA_PLUGIN_FormatSyntaxError(luaState,szBuffer,szFinalError);
		lua_pushstring(luaState,szFinalError);
		lua_error(luaState);
	}
	return s;
}

/*

Function:	IRLUA_PLUGIN_CheckBoolean
Purpose:	Checks the value at a given Lua stack position to see if it
			is a boolean. If not, it tries to convert it to a boolean. If
			it can't it throws a syntax error.
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
			nArg - The Lua stack position to check.
Returns:	The boolean value.

*/
BOOL IRLUA_PLUGIN_CheckBoolean (lua_State *luaState, int nArg)
{
	BOOL bRet = FALSE;
	char szBuffer[IR_PLUGIN_MAX_FORMATTED_ERROR];
	char szFinalError[IR_PLUGIN_MAX_FORMATTED_ERROR];
	if(!lua_isboolean(luaState, nArg))
	{
		wsprintf(szBuffer,"Argument %d must be a boolean.",nArg);
		IRLUA_PLUGIN_FormatSyntaxError(luaState,szBuffer,szFinalError);
		lua_pushstring(luaState,szFinalError);
		lua_error(luaState);
	} else
	{
		bRet = lua_toboolean(luaState, nArg);
	}
	return bRet;
}

/*

Function:	IRLUA_PLUGIN_CheckNumber
Purpose:	Checks the value at a given Lua stack position to see if it
			is a number. If not, it tries to convert it to a number. If
			it can't it throws a syntax error.
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
			nArg - The Lua stack position to check.
Returns:	The number value.

*/
double IRLUA_PLUGIN_CheckNumber (lua_State *luaState, int nArg)
{
	double nReturn = 0;

	nReturn = lua_tonumber(luaState, nArg);
	
	return nReturn;
}

void IRLUA_PLUGIN_CheckTable(lua_State *luaState, int nArg)
{
	char szBuffer[IR_PLUGIN_MAX_FORMATTED_ERROR];
	char szFinalError[IR_PLUGIN_MAX_FORMATTED_ERROR];
	if(!lua_istable(luaState, nArg))
	{
		wsprintf(szBuffer,"Argument %d must be a table.",nArg);
		IRLUA_PLUGIN_FormatSyntaxError(luaState,szBuffer,szFinalError);
		lua_pushstring(luaState,szFinalError);
		lua_error(luaState);
	}
}

/*

Function:	IRLUA_PLUGIN_ExpandRelativePath
Purpose:	Takes a path that may be relative to AutoPlay folder
			(i.e. "AutoPlay\Images\myfile.bmp") and returns the fully-qualified
			path.  If the path is already complete, it is returned as-is
Arguments:	luaState - a pointer to the lua_State structure
				used by the runtime engine.
			szShortPath - The relative path
			szFullPath - [out] The full path - MUST be MAX_PATH in length
Returns:	Nothing.

*/
void IRLUA_PLUGIN_ExpandRelativePath(lua_State *luaState, char* szShortPath,
								   char* szFullPath)
{
	// Call the "hidden" Debug.GetSyntaxErrorString action...
	lua_getglobal(luaState,"_SourceFolder");
	char szReturn[MAX_PATH];
	memset(szReturn,0,MAX_PATH);
	char szLongPath[MAX_PATH*2];
	memset(szLongPath,0,MAX_PATH*2);

	char szSourceFolder[MAX_PATH];

	if(lua_isstring(luaState,-1))
	{
		lstrcpy(szSourceFolder,lua_tostring(luaState,-1));
	}

	lua_remove(luaState,-1);

	int nSourceFolderLength = lstrlen(szSourceFolder);
	int nShortPathLength = lstrlen(szShortPath);
	if(nShortPathLength > 0)
	{
		if(nSourceFolderLength > 2)
		{
			// Strip trailing backslash...
			if(szSourceFolder[nSourceFolderLength-1] != '\\')
			{
				lstrcat(szSourceFolder,"\\");
			}

			lstrcpy(szLongPath,szSourceFolder);
			lstrcat(szLongPath,szShortPath);

			if(_access(szLongPath,00) == 0)
			{
				// It exists...
				lstrcpy(szReturn,szLongPath);
			} else
			{
				lstrcpy(szReturn,szShortPath);
			}
		} else
		{
			lstrcpy(szReturn,szShortPath);
		}
	} else
	{
		lstrcpy(szReturn,szShortPath);
	}

	lstrcpy(szFullPath,szReturn);
}

CString IRLUA_PLUGIN_ExpandSessionVariables (lua_State *luaState,
												 const char* szSessionString)
{
	CString strReturn = szSessionString;

	lua_getglobal(luaState,"SessionVar");
	lua_pushstring(luaState,"Expand");
	lua_gettable(luaState,-2);
	lua_remove(luaState,-2);

	if(lua_isfunction(luaState,-1))
	{
		lua_pushstring(luaState,szSessionString);
		if(lua_pcall(luaState,1,1,0) != 0)
		{
			// Error
			lua_remove(luaState,-1);
		} 
		else
		{
			// Success... expanded string on stack
			strReturn = lua_tostring(luaState,-1);
			lua_remove(luaState,-1);
		}
	} 
	else
	{
		lua_remove(luaState,-1);
	}

	return strReturn;
}
#endif

__declspec(dllexport) int __cdecl irPlg_GetSDKVersion(void)
{
	return IR_SDK_VERSION;
}
