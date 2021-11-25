// IRPluginObject.h: interface for the CIRPluginObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IRPLUGINOBJECT_H__345EA06E_203A_4565_990A_B6A70C5B6B9E__INCLUDED_)
#define AFX_IRPLUGINOBJECT_H__345EA06E_203A_4565_990A_B6A70C5B6B9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "lua.h"

#define IR_PLUGIN_CLASS_VERSION 1

#define IR_PLUGIN_EVENT_NAME_MAX 200
#define IR_PLUGIN_EVENT_ARGS_MAX 1000

#ifdef SDK_DLL_EXPORT
struct __declspec(dllexport) IRPluginEventInfo
#else
struct IRPluginEventInfo
#endif
{
	char m_szName[IR_PLUGIN_EVENT_NAME_MAX];
	char m_szArgs[IR_PLUGIN_EVENT_ARGS_MAX];
};

#ifdef SDK_DLL_EXPORT
class __declspec(dllexport) CIRPluginObject  
#else
class CIRPluginObject  
#endif

{
public:
	CIRPluginObject();
	virtual ~CIRPluginObject();

	// Informational:
	virtual void GetDefaultSize(SIZE* pSize) {pSize->cx=100;pSize->cy=100;};
	virtual BOOL IsWindowedObject() {return FALSE;};
	virtual HWND GetWindowHandle() {return NULL;};

	virtual void DrawDesign(HDC hDC, HWND hMainWnd, RECT rcObRect,BOOL bVisible,BOOL bEnabled);
	virtual void DrawRuntime(HDC hDC, HWND hMainWnd, RECT rcObRect,BOOL bVisible,BOOL bEnabled);
	virtual void HideInternalObject();
	virtual int GetCustomProperties(char* szBuffer, int* pnBufferSize);
	virtual void SetCustomProperties(char* szPropsList);
	virtual BOOL ShowProperties(char* szPluginFolder);
	virtual BOOL GetEvent(int nIndex, IRPluginEventInfo* pEventInfo);
	virtual int GetNumEvents();
	virtual int RegisterLUAFunctions(lua_State* L);
	virtual BOOL LetAMSHandleCursorChange() {return TRUE;};
	virtual BOOL LetAMSHandleSounds() {return TRUE;};
	virtual BOOL LetAMSHandleTooltip() {return TRUE;};
	virtual BOOL CanSetFocus() {return FALSE;};
	virtual void DoSetFocus() {;};
	virtual void ShowWindow(BOOL bVisible) {;};

	// Events from above...
	virtual void OnMouseOver(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnMouseLeave(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnLBtnDown(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnLBtnUp(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnLBtnDoubleClick(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnRBtnDown(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnRBtnUp(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnRBtnDoubleClick(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};

	void FireEvent(LPCTSTR strEventName, LPCTSTR strArguments);

	// Non-Virtuals
	int GetObjectID(char* szBuffer, int* pnBufferSize);

	lua_State* m_pLuaState;

protected:
	char m_szObjectID[100];
};

// Some useful functions...
CIRPluginObject* IRLUA_PLUGIN_GetObjectPtr(lua_State *luaState,LPCTSTR strObjectName);
void IRLUA_PLUGIN_RedrawObject(lua_State *luaState,LPCTSTR strObjectName);

#endif // !defined(AFX_IRPLUGINOBJECT_H__345EA06E_203A_4565_990A_B6A70C5B6B9E__INCLUDED_)
