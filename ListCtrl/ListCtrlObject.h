#pragma once
#include "irpluginobject.h"
#include "ControlHolderWnd.h"

#define NUM_OB_EVENTS 12

class CListCtrlObject :
	public CIRPluginObject
{
public:
	CListCtrlObject(void);
	virtual ~CListCtrlObject(void);
	virtual void GetDefaultSize(SIZE* pSize) {pSize->cx=250;pSize->cy=250;};
	virtual BOOL IsWindowedObject() {return TRUE;};
	virtual HWND GetWindowHandle();

	virtual void DrawDesign(HDC hDC, HWND hMainWnd, RECT rcObRect,BOOL bVisible,BOOL bEnabled);
	virtual void DrawRuntime(HDC hDC, HWND hMainWnd, RECT rcObRect,BOOL bVisible,BOOL bEnabled);
	// Unused: virtual void HideInternalObject();
	virtual int GetCustomProperties(char* szBuffer, int* pnBufferSize);
	virtual void SetCustomProperties(char* szPropsList);
	virtual BOOL ShowProperties(char* szPluginFolder);
	virtual BOOL GetEvent(int nIndex, IRPluginEventInfo* pEventInfo);
	virtual int GetNumEvents();
	virtual int RegisterLUAFunctions(lua_State* L);
	virtual void HideInternalObject();
	virtual BOOL LetAMSHandleCursorChange() {return FALSE;};
	virtual BOOL LetAMSHandleSounds() {return FALSE;};
	virtual BOOL LetAMSHandleTooltip() {return TRUE;};
	virtual BOOL CanSetFocus() {return TRUE;};
	virtual void DoSetFocus();
	virtual void ShowWindow(BOOL bVisible);

	// Events from above...
	virtual void OnMouseOver(HWND hWndParent,POINT ptMousePos,RECT rcObRect)  {;};
	virtual void OnMouseLeave(HWND hWndParent,POINT ptMousePos,RECT rcObRect)  {;};
	virtual void OnLBtnDown(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnLBtnUp(HWND hWndParent,POINT ptMousePos,RECT rcObRect)  {;};
	virtual void OnLBtnDoubleClick(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnRBtnDown(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnRBtnUp(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};
	virtual void OnRBtnDoubleClick(HWND hWndParent,POINT ptMousePos,RECT rcObRect) {;};

protected:
	IRPluginEventInfo* m_pEvents[NUM_OB_EVENTS];
	char m_szPropertiesString[1000];
	void DestroyListCtrl();

public:
	int m_nCheckBox;
	int m_nHeaderDragDrop;
	int m_nFullRowSelect;
	int m_nGridLines;
	int m_nTooltipCtrl;
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
	COLORREF m_BackgroundColor;
	//Cell text color
	COLORREF m_CellTextColor;
	//Cell back color
	COLORREF m_CellBackColor;
	//
	//Tooltip
	CString m_TooltipText;
	CString m_TooltipTitleText;
	//
	CString m_EmptyMarkupText;

	CControlHolderWnd* m_pListCtrlHolder;
};
