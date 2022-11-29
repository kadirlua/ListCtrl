#ifndef __IR_PLUGIN_HELPER_FUNCTIONS_H_
#define __IR_PLUGIN_HELPER_FUNCTIONS_H_

/*

The following functions are used as helper functions
when developing plugins for AutoPlay Media Studio.

Each function is individually documented in IRPluginHelperFunctions.cpp
above the respective function implementation.

This source code is Copyright © 2010 Indigo Rose Corporation. You may
freely use it when developing plugins for AutoPlay Media Studio
provided that this comment block is left as-is.

AutoPlay Media Studio is a trademanrk of Indigo Rose Corporation.
http://www.indigorose.com

*/

#define IR_PLUGIN_MAX_FORMATTED_ERROR 1024
#define IR_SDK_VERSION 2

#ifdef LUA_VERSION

void IRLUA_PLUGIN_SetLastError(lua_State *luaState,int nCode);
void IRLUA_PLUGIN_ResetLastError(lua_State *luaState);
bool IR_PLUGIN_GetTextFromResourceFile(LPCTSTR lpszType, UINT nResourceID, char* szBuffer, int nBufferSize);
void IRLUA_PLUGIN_SetGlobalErrorMessage(lua_State *luaState, int nCode, LPCTSTR szMessage);
void IRLUA_PLUGIN_DoAutoTab(lua_State *luaState, BOOL bNextTab);
void IRLUA_PLUGIN_FormatSyntaxError(lua_State *luaState, char* szErrorMsg, 
								   char* szFullMessage);
void IRLUA_PLUGIN_ExpandRelativePath(lua_State *luaState, char* szShortPath,
								   char* szFullPath);
void IRLUA_PLUGIN_CheckNumArgs(lua_State* luaState, int nNumArgsRequired);
const char* IRLUA_PLUGIN_CheckString (lua_State *luaState, int nArg);
BOOL IRLUA_PLUGIN_CheckBoolean (lua_State *luaState, int nArg);
double IRLUA_PLUGIN_CheckNumber (lua_State *luaState, int nArg);
void IRLUA_PLUGIN_CheckTable(lua_State *luaState, int nArg);

CString IRLUA_PLUGIN_ExpandSessionVariables (lua_State *luaState,
						const char* szSessionString);

#endif

__declspec(dllexport) int __cdecl irPlg_GetSDKVersion(void);

#endif