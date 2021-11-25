// IRPluginObject.cpp: implementation of the CIRPluginObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IRPluginObject.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIRPluginObject::CIRPluginObject()
{
	memset(m_szObjectID,0,100);
}

CIRPluginObject::~CIRPluginObject()
{

}

void CIRPluginObject::DrawDesign(HDC hDC, HWND hMainWnd, RECT rcObRect,BOOL bVisible,BOOL bEnabled)
{
	// Default does nothing
}

void CIRPluginObject::DrawRuntime(HDC hDC, HWND hMainWnd, RECT rcObRect,BOOL bVisible,BOOL bEnabled)
{
	// Default does nothing
}

void CIRPluginObject::HideInternalObject()
{
	// Default does nothing
}

int CIRPluginObject::GetCustomProperties(char* szBuffer, int* pnBufferSize)
{
	int nLength = lstrlen("");
	if(*pnBufferSize < nLength)
	{
		*pnBufferSize = nLength;
		return -1;
	} else
	{
		memset(szBuffer,0,*pnBufferSize);
		lstrcpy(szBuffer,"");
		return nLength;
	}
}

void CIRPluginObject::SetCustomProperties(char* szPropsList)
{
	// Default does nothing
}

BOOL CIRPluginObject::ShowProperties(char* szPluginFolder)
{
	return TRUE;
}


BOOL CIRPluginObject::GetEvent(int nIndex, IRPluginEventInfo* pEventInfo)
{
	pEventInfo = NULL;
	return FALSE;
}

int CIRPluginObject::GetNumEvents()
{
	return 0;
}

int CIRPluginObject::RegisterLUAFunctions(lua_State* L)
{
	m_pLuaState = L;
	return 0;
}

void CIRPluginObject::FireEvent(LPCTSTR strEventName, LPCTSTR strArguments)
{
	if(!m_pLuaState) return;

	lua_getglobal(m_pLuaState,"Page");
	lua_pushstring(m_pLuaState,"FireEvent");
	lua_gettable(m_pLuaState,-2);
	lua_remove(m_pLuaState,-2);

	if(lua_isfunction(m_pLuaState,-1))
	{
		lua_pushnumber(m_pLuaState,(double)((DWORD)this));
		lua_pushstring(m_pLuaState,strEventName);
		lua_pushstring(m_pLuaState,strArguments);
		if(lua_pcall(m_pLuaState,3,0,0) != 0)
		{
			// Error
			lua_remove(m_pLuaState,-1);
		}
	} else
	{
		lua_remove(m_pLuaState,-1);
	}
}

int CIRPluginObject::GetObjectID(char* szBuffer, int* pnBufferSize)
{
	int nLength = lstrlen(m_szObjectID);
	if(*pnBufferSize < nLength)
	{
		*pnBufferSize = nLength;
		return -1;
	} else
	{
		memset(szBuffer,0,*pnBufferSize);
		lstrcpy(szBuffer,m_szObjectID);
		return nLength;
	}
}

CIRPluginObject* IRLUA_PLUGIN_GetObjectPtr(lua_State *luaState,LPCTSTR strObjectName)
{
	CIRPluginObject* pRet = NULL;
	DWORD dwObjectAddress;

	if(luaState)
	{
		lua_getglobal(luaState,"Page");
		lua_pushstring(luaState,"GetPluginObjectPtr");
		lua_gettable(luaState,-2);
		lua_remove(luaState,-2);

		if(lua_isfunction(luaState,-1))
		{
			lua_pushstring(luaState,strObjectName);
			if(lua_pcall(luaState,1,1,0) != 0)
			{
				// Error
				lua_remove(luaState,-1);
			} else
			{
				if(lua_isnumber(luaState,-1))
				{
					dwObjectAddress = (DWORD) lua_tonumber(luaState,-1);
					if(dwObjectAddress != 0)
					{
						pRet = (CIRPluginObject*) dwObjectAddress;
					}
				}
				lua_remove(luaState,-1);
			}
		} else
		{
			lua_remove(luaState,-1);
		}
	}

	return pRet;
}

void IRLUA_PLUGIN_RedrawObject(lua_State *luaState,LPCTSTR strObjectName)
{
	if(luaState)
	{
		lua_getglobal(luaState,"Page");
		lua_pushstring(luaState,"RedrawObject");
		lua_gettable(luaState,-2);
		lua_remove(luaState,-2);

		if(lua_isfunction(luaState,-1))
		{
			lua_pushstring(luaState,strObjectName);
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
}