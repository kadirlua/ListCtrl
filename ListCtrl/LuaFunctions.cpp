#include "stdafx.h"
#include "LuaFunctions.h"
#include "ListCtrlObject.h"
#include "IRPluginHelperFunctions.h"

// LUA FUNCTIONS:

luaL_reg lib_ListCtrl[] = {
		{"InsertItem", ListCtrl_InsertItem},
		{"InsertColumn",ListCtrl_InsertColumn},
		{"SetRedraw",ListCtrl_SetRedraw},
		{"SetItemText",ListCtrl_SetItemText},
		{"SetFocus",ListCtrl_SetFocus},
		{"DeleteAllItems",ListCtrl_DeleteAllItems},
		{"DeleteColumn",ListCtrl_DeleteColumn},
		{"DeleteItem",ListCtrl_DeleteItem},
		{"GetItemCount",ListCtrl_GetItemCount},
		{"GetColumnCount",ListCtrl_GetColumnCount},
		{"GetColumnWidth",ListCtrl_GetColumnWidth},
		{"GetColumnHeading",ListCtrl_GetColumnHeading},
		{"GetItemText",ListCtrl_GetItemText},
		{"GetFocusCell",ListCtrl_GetFocusCell},
		{"GetFocusRow",ListCtrl_GetFocusRow},
		{"GetHotItem",ListCtrl_GetHotItem},
		{"SetCheckBoxOnHeader",ListCtrl_SetCheckBoxOnHeader},
		{"GetCheck",ListCtrl_GetCheck},
		{"SetCheck",ListCtrl_SetCheck},
		{"SetCheckAllItems",ListCtrl_SetCheckAllItems},
		{"SetColumnWidthAuto",ListCtrl_SetColumnWidthAuto},
		{"InsertColumnTrait",ListCtrl_InsertColumnTrait},
		{"ComboTraitSetMaxItems",ListCtrl_ComboTraitSetMaxItems},
		{"ComboTraitAddItem",ListCtrl_ComboTraitAddItem},
		{"CreateComboTrait",ListCtrl_CreateComboTrait},
		{"ComboTraitSetSingleClickEdit",ListCtrl_ComboTraitSetSingleClickEdit},
		{"ComboTraitSetShowDropDown",ListCtrl_ComboTraitSetShowDropDown},
		{"ComboClearFixedItems",ListCtrl_ComboClearFixedItems},
		{"CreateEditTrait",ListCtrl_CreateEditTrait},
		{"CreateDateTimeTrait",ListCtrl_CreateDateTimeTrait},
		{"CreateHyperLinkTrait",ListCtrl_CreateHyperLinkTrait},
		{"DateTimeSetFormat",ListCtrl_DateTimeSetFormat},
		{"DateTimeSetToggleSelection",ListCtrl_DateTimeSetToggleSelection},
		{"HyperLinkSetShellFilePrefix",ListCtrl_HyperLinkSetShellFilePrefix},
		{"SelectRow",ListCtrl_SelectRow},
		{"SelectAllRows",ListCtrl_SelectAllRows},
		{"SetCellBackColor",ListCtrl_SetCellBackColor},
		{"SetCellTextColor",ListCtrl_SetCellTextColor},
		{"SetTooltipTitle",ListCtrl_SetTooltipTitle},
		{"SetTooltipText",ListCtrl_SetTooltipText},
		{"SetBkColor",ListCtrl_SetBkColor},
		{"GetBkColor",ListCtrl_GetBkColor},
		{"IsCellEditorOpen",ListCtrl_IsCellEditorOpen},
		{"RedrawItems",ListCtrl_RedrawItems},
		{"SetColumnWidth",ListCtrl_SetColumnWidth},
		{"SetFocusRow",ListCtrl_SetFocusRow},
		{"SetFocusCell",ListCtrl_SetFocusCell},
		{"SetHotItem",ListCtrl_SetHotItem},
		{"SetItemData",ListCtrl_SetItemData},
		{"GetItemData",ListCtrl_GetItemData},
		{"EditTraitSetLimitText",ListCtrl_EditTraitSetLimitText},
		{"EditTraitGetLimitText",ListCtrl_EditTraitGetLimitText},
		{"EditTraitSetSingleClickEdit",ListCtrl_EditTraitSetSingleClickEdit},
		{"DateTimeGetFormat",ListCtrl_DateTimeGetFormat},
		{"DateTimeSetSingleClickEdit",ListCtrl_DateTimeSetSingleClickEdit},
		{"DateTimeSetTime",ListCtrl_DateTimeSetTime},
		{"EnableTooltips",ListCtrl_EnableTooltips},
		{"HyperLinkGetShellFilePrefix",ListCtrl_HyperLinkGetShellFilePrefix},
		{"HyperLinkGetShellFileSuffix",ListCtrl_HyperLinkGetShellFileSuffix},
		{"HyperLinkSetShellFileSuffix",ListCtrl_HyperLinkSetShellFileSuffix},
		{"HyperLinkSetSingleClickEdit",ListCtrl_HyperLinkSetSingleClickEdit},
		{"HyperLinkSetShellApplication",ListCtrl_HyperLinkSetShellApplication},
		{"SetFont",ListCtrl_SetFont},
		{"FindItem",ListCtrl_FindItem},
		{"EnsureVisible",ListCtrl_EnsureVisible},
		{"UpdateWindow",ListCtrl_UpdateWindow},
		{"GetSelectedItems",ListCtrl_GetSelectedItems},
		{"GetSelectedCount",ListCtrl_GetSelectedCount},
		{"IsItemSelected",ListCtrl_IsItemSelected},
		{"EnsureColumnVisible",ListCtrl_EnsureColumnVisible},
		{"CreateMultilineEditTrait",ListCtrl_CreateMultilineEditTrait},
		{"MultilineEditTraitGetLimitText",ListCtrl_MultilineEditTraitGetLimitText},
		{"MultilineEditTraitGetMaxLines",ListCtrl_MultilineEditTraitGetMaxLines},
		{"MultilineEditTraitSetSingleClickEdit",ListCtrl_MultilineEditTraitSetSingleClickEdit},
		{"MultilineEditTraitSetLimitText",ListCtrl_MultilineEditTraitSetLimitText},
		{"MultilineEditTraitSetMaxLines",ListCtrl_MultilineEditTraitSetMaxLines},
		{"CreateMaskedEditTrait",ListCtrl_CreateMaskedEditTrait},
		{"MaskedEditSetPromptSymbol",ListCtrl_MaskedEditSetPromptSymbol},
		{"MaskedEditSetMask",ListCtrl_MaskedEditSetMask},
		{"GetColumnTrait",ListCtrl_GetColumnTrait},
		{"MaskedEditGetPromptSymbol",ListCtrl_MaskedEditGetPromptSymbol},
		{"MaskedEditGetMask",ListCtrl_MaskedEditGetMask},
		{"MaskedEditTraitSetSingleClickEdit",ListCtrl_MaskedEditTraitSetSingleClickEdit},
		{"EditCell",ListCtrl_EditCell},
		{"ShowColumn",ListCtrl_ShowColumn},
		{"IsColumnVisible",ListCtrl_IsColumnVisible},
		{"MoveFocusCell",ListCtrl_MoveFocusCell},
		{"CopyToClipBoard",ListCtrl_CopyToClipBoard},
		{"GetCheckedItems",ListCtrl_GetCheckedItems},
		{"GroupByColumn",ListCtrl_GroupByColumn},
		{"IsGroupViewEnabled",ListCtrl_IsGroupViewEnabled},
		{"RemoveAllGroups",ListCtrl_RemoveAllGroups},
		{"IsGroupStateEnabled",ListCtrl_IsGroupStateEnabled},
		{"GetGroupHeader",ListCtrl_GetGroupHeader},
		{"CheckEntireGroup",ListCtrl_CheckEntireGroup},
		{"ExpandAllGroups",ListCtrl_ExpandAllGroups},
		{"CollapseAllGroups",ListCtrl_CollapseAllGroups},
		{"DeleteEntireGroup",ListCtrl_DeleteEntireGroup},
		{"SortColumn",ListCtrl_SortColumn},
		{"SetSortArrow",ListCtrl_SetSortArrow},
		{"GetColumnTraitState",ListCtrl_GetColumnTraitState},
		{"GetColumnData",ListCtrl_GetColumnData},
		{"GetColumnOrder",ListCtrl_GetColumnOrder},
		{"SetColumnOrder",ListCtrl_SetColumnOrder},
		{"SetItemCount",ListCtrl_SetItemCount},
		{"SetEmptyMarkupText",ListCtrl_SetEmptyMarkupText},
		{NULL, NULL}
	};

int ListCtrl_InsertColumnTrait(lua_State* luaState)
{

	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	int nResult = -1;
	CString strObjectName;
	int nCol = 0;
	CString strColumnHeading = "";
	int nFormat = -1;
	int nWidth = 100;
	int nSubItem = -1;
	CGridColumnTrait* pTrait = NULL;
	IRLUA_PLUGIN_CheckNumArgs(luaState,7);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	strColumnHeading = IRLUA_PLUGIN_CheckString(luaState,3);
	nFormat = (int)IRLUA_PLUGIN_CheckNumber(luaState,4);
	nWidth = (int)IRLUA_PLUGIN_CheckNumber(luaState,5);
	nSubItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,6);
	pTrait = (CGridColumnTrait*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,7);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->InsertColumnTrait(nCol,strColumnHeading,nFormat,nWidth,nSubItem,pTrait);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nResult);
	return 1;
}

int ListCtrl_GetColumnTrait(lua_State* luaState)
{

	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CGridColumnTrait* pColumnTrait = NULL;
	CString strObjectName;
	int nCol = 0;
	
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pColumnTrait = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetColumnTrait(nCol);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	if (pColumnTrait)
	lua_pushnumber(luaState,(LPARAM)pColumnTrait);
	else
	lua_pushnil(luaState);
	return 1;
}

int ListCtrl_GetColumnTraitState(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTrait* pTrait = (CGridColumnTrait*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	if (pTrait)
		{
			CGridColumnTrait::ColumnState& columnState = pTrait->GetColumnState();
				lua_newtable(luaState);
				lua_pushstring(luaState, "bSortable");
				lua_pushboolean(luaState, (columnState.m_Sortable == true)?TRUE:FALSE);
				lua_rawset(luaState, -3);

				lua_pushstring(luaState, "bEditable");
				lua_pushboolean(luaState, (columnState.m_Editable == true)?TRUE:FALSE);
				lua_rawset(luaState, -3);

				lua_pushstring(luaState, "nMaxWidth");
				lua_pushnumber(luaState, columnState.m_MaxWidth);
				lua_rawset(luaState, -3);

				lua_pushstring(luaState, "nMinWidth");
				lua_pushnumber(luaState, columnState.m_MinWidth);
				lua_rawset(luaState, -3);

				lua_pushstring(luaState, "nOrgPosition");
				lua_pushnumber(luaState, columnState.m_OrgPosition);
				lua_rawset(luaState, -3);

				lua_pushstring(luaState, "nOrgWidth");
				lua_pushnumber(luaState, columnState.m_OrgWidth);
				lua_rawset(luaState, -3);

				lua_pushstring(luaState, "bResizable");
				lua_pushnumber(luaState, (columnState.m_Resizable == true)?TRUE:FALSE);
				lua_rawset(luaState, -3);

				lua_pushstring(luaState, "bVisible");
				lua_pushnumber(luaState, (columnState.m_Visible == true)?TRUE:FALSE);
				lua_rawset(luaState, -3);
		}
		else
				lua_pushnil(luaState);
	return 1;
}

int ListCtrl_MaskedEditSetPromptSymbol(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitMaskedEdit* pEditTraitMaskedEdit = (CGridColumnTraitMaskedEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	CString promptsmybol = IRLUA_PLUGIN_CheckString(luaState,2);
	char *str;
	str = (char *)malloc(sizeof(char));
	strcpy_s(str,strlen(promptsmybol)+1,promptsmybol);
	if (pEditTraitMaskedEdit)
		{
			pEditTraitMaskedEdit->SetPromptSymbol(str[0]);
		}
	return 0;
}

int ListCtrl_MaskedEditGetPromptSymbol(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTraitMaskedEdit* pEditTraitMaskedEdit = (CGridColumnTraitMaskedEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	CString promptsmybol = "";
	if (pEditTraitMaskedEdit)
		{
			promptsmybol = pEditTraitMaskedEdit->GetPromptSymbol();
		}
	lua_pushstring(luaState, promptsmybol);
	return 1;
}

int ListCtrl_MaskedEditSetMask(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitMaskedEdit* pEditTraitMaskedEdit = (CGridColumnTraitMaskedEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	CString strMask = IRLUA_PLUGIN_CheckString(luaState,2);
	if (pEditTraitMaskedEdit)
		{
			pEditTraitMaskedEdit->SetMaskText(strMask);
		}
	return 0;
}

int ListCtrl_MaskedEditGetMask(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTraitMaskedEdit* pEditTraitMaskedEdit = (CGridColumnTraitMaskedEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	CString strMask = "";
	if (pEditTraitMaskedEdit)
		{
			strMask = pEditTraitMaskedEdit->GetMaskText();
		}
	lua_pushstring(luaState, strMask);
	return 1;
}

int ListCtrl_MaskedEditTraitSetSingleClickEdit(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitMaskedEdit* pEditTraitMaskedEdit = (CGridColumnTraitMaskedEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	BOOL bValue = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	if (pEditTraitMaskedEdit)
		{
			pEditTraitMaskedEdit->SetSingleClickEdit(bValue?true:false);
		}
	return 0;
}

int ListCtrl_CreateMaskedEditTrait(lua_State* luaState)
{
	CGridColumnTraitMaskedEdit *pEditTraitMaskedEdit = new CGridColumnTraitMaskedEdit;
	if (pEditTraitMaskedEdit)
	lua_pushnumber(luaState,(LPARAM)pEditTraitMaskedEdit);
	else
	lua_pushnil(luaState);
	return 1;
}

int ListCtrl_MultilineEditTraitSetMaxLines(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitMultilineEdit* pMultilineEditTrait = (CGridColumnTraitMultilineEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	UINT nMaxLines = (UINT)IRLUA_PLUGIN_CheckNumber(luaState,2);
	if (pMultilineEditTrait)
		{
			pMultilineEditTrait->SetMaxLines(nMaxLines);
		}
	return 0;
}

int ListCtrl_MultilineEditTraitSetLimitText(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitMultilineEdit* pMultilineEditTrait = (CGridColumnTraitMultilineEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	UINT nMaxChars = (UINT)IRLUA_PLUGIN_CheckNumber(luaState,2);
	if (pMultilineEditTrait)
		{
			pMultilineEditTrait->SetLimitText(nMaxChars);
		}
	return 0;
}

int ListCtrl_MultilineEditTraitSetSingleClickEdit(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitMultilineEdit* pMultilineEditTrait = (CGridColumnTraitMultilineEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	BOOL bValue = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	if (pMultilineEditTrait)
		{
			pMultilineEditTrait->SetSingleClickEdit(bValue?true:false);
		}
	return 0;
}

int ListCtrl_MultilineEditTraitGetLimitText(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTraitMultilineEdit* pMultilineEditTrait = (CGridColumnTraitMultilineEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	UINT nLimitText = -1;
	if (pMultilineEditTrait)
		{
			nLimitText = pMultilineEditTrait->GetLimitText();
		}
	lua_pushnumber(luaState,nLimitText);
	return 1;
}

int ListCtrl_MultilineEditTraitGetMaxLines(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTraitMultilineEdit* pMultilineEditTrait = (CGridColumnTraitMultilineEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	UINT nMaxLines = -1;
	if (pMultilineEditTrait)
		{
			nMaxLines = pMultilineEditTrait->GetMaxLines();
		}
	lua_pushnumber(luaState,nMaxLines);
	return 1;
}

int ListCtrl_CreateMultilineEditTrait(lua_State* luaState)
{
	CGridColumnTraitMultilineEdit *pMultilineEditTrait = new CGridColumnTraitMultilineEdit;
		if (pMultilineEditTrait)
		{
			lua_pushnumber(luaState,(LPARAM)pMultilineEditTrait);
		} else
			lua_pushnil(luaState);
	return 1;
}

int ListCtrl_ComboTraitAddItem(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	CGridColumnTraitCombo* pComboTrait = (CGridColumnTraitCombo*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	DWORD_PTR nItemData = (DWORD_PTR)IRLUA_PLUGIN_CheckNumber(luaState,2);
	CString strItemText = IRLUA_PLUGIN_CheckString(luaState,3);	
		if (pComboTrait)
		{
		pComboTrait->AddItem(nItemData,strItemText);
		}
	return 0;
}

int ListCtrl_ComboTraitSetShowDropDown(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitCombo* pComboTrait = (CGridColumnTraitCombo*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	BOOL bShowIt = IRLUA_PLUGIN_CheckBoolean(luaState,2);
		if (pComboTrait)
		{
		pComboTrait->SetShowDropDown(bShowIt);
		}
	return 0;
}

int ListCtrl_ComboTraitSetMaxItems(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitCombo* pComboTrait = (CGridColumnTraitCombo*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	UINT nMaxItems = (UINT)IRLUA_PLUGIN_CheckNumber(luaState,2);
		if (pComboTrait)
		{
		pComboTrait->SetMaxItems(nMaxItems);
		}
	return 0;
}

int ListCtrl_ComboTraitSetSingleClickEdit(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitCombo* pComboTrait = (CGridColumnTraitCombo*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	BOOL bValue = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	if (pComboTrait)
		{
		pComboTrait->SetSingleClickEdit(bValue?true:false);
		}
	return 0;
}

int ListCtrl_ComboClearFixedItems(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTraitCombo* pComboTrait = (CGridColumnTraitCombo*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
		if (pComboTrait)
		{
		pComboTrait->ClearFixedItems();
		}
	return 0;
}

int ListCtrl_CreateComboTrait(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	BOOL bDropList = IRLUA_PLUGIN_CheckBoolean(luaState,1);
	CGridColumnTraitCombo *pComboTrait = new CGridColumnTraitCombo;
		if (pComboTrait)
		{
		if (bDropList)	pComboTrait->SetStyle(pComboTrait->GetStyle() | CBS_DROPDOWNLIST);
		lua_pushnumber(luaState,(LPARAM)pComboTrait);
		} else
			lua_pushnil(luaState);
	return 1;
}

int ListCtrl_CreateEditTrait(lua_State* luaState)
{
	CGridColumnTraitEdit *pEditTrait = new CGridColumnTraitEdit;
	if (pEditTrait)
	lua_pushnumber(luaState,(LPARAM)pEditTrait);
	else
	lua_pushnil(luaState);
	return 1;
}

int ListCtrl_EditTraitSetLimitText(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitEdit* pEditTrait = (CGridColumnTraitEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	UINT nMaxChars = (UINT)IRLUA_PLUGIN_CheckNumber(luaState,2);
	if (pEditTrait)
	pEditTrait->SetLimitText(nMaxChars);
	return 0;
}

int ListCtrl_EditTraitGetLimitText(lua_State* luaState)
{
	UINT nMaxChars = 0;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTraitEdit* pEditTrait = (CGridColumnTraitEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	if (pEditTrait)
	nMaxChars = pEditTrait->GetLimitText();
	
	lua_pushnumber(luaState,nMaxChars);
	return 1;
}

int ListCtrl_EditTraitSetSingleClickEdit(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitEdit* pEditTrait = (CGridColumnTraitEdit*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	BOOL bValue = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	if (pEditTrait)
	pEditTrait->SetSingleClickEdit(bValue?true:false);
	return 0;
}

int ListCtrl_DateTimeSetFormat(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitDateTime* pDateTimeTrait = (CGridColumnTraitDateTime*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	CString strfmt = IRLUA_PLUGIN_CheckString(luaState,2);
	if (pDateTimeTrait)
	pDateTimeTrait->SetFormat(strfmt);
	return 0;
}

int ListCtrl_DateTimeGetFormat(lua_State* luaState)
{
	CString strFormat = "";
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTraitDateTime* pDateTimeTrait = (CGridColumnTraitDateTime*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	if (pDateTimeTrait)
	strFormat = pDateTimeTrait->GetFormat();

	lua_pushstring(luaState,strFormat);
	return 1;
}

int ListCtrl_DateTimeSetSingleClickEdit(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitDateTime* pDateTimeTrait = (CGridColumnTraitDateTime*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	BOOL bValue = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	if (pDateTimeTrait)
	pDateTimeTrait->SetSingleClickEdit(bValue?true:false);
	return 0;
}

int ListCtrl_DateTimeSetTime(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,4);
	CGridColumnTraitDateTime* pDateTimeTrait = (CGridColumnTraitDateTime*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	int nYear = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	int nMonth = (int)IRLUA_PLUGIN_CheckNumber(luaState,3);
	int nDay = (int)IRLUA_PLUGIN_CheckNumber(luaState,4);
	if (pDateTimeTrait)
	pDateTimeTrait->SetDateTime(nYear,nMonth,nDay,0,0,0);
	return 0;
}

int ListCtrl_DateTimeSetToggleSelection(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitDateTime* pDateTimeTrait = (CGridColumnTraitDateTime*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	BOOL bValue = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	if (pDateTimeTrait)
	pDateTimeTrait->SetToggleSelection(bValue?true:false);
	return 0;
}

int ListCtrl_CreateDateTimeTrait(lua_State* luaState)
{
	CGridColumnTraitDateTime *pDateTimeTrait = new CGridColumnTraitDateTime;
	if (pDateTimeTrait)
	lua_pushnumber(luaState,(LPARAM)pDateTimeTrait);
	else
	lua_pushnil(luaState);
	return 1;
}

int ListCtrl_HyperLinkGetShellFilePrefix(lua_State* luaState)
{
	CString strRet = "";
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTraitHyperLink* pHyperLinkTrait = (CGridColumnTraitHyperLink*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	if (pHyperLinkTrait)
		strRet = pHyperLinkTrait->GetShellFilePrefix();
	lua_pushstring(luaState,strRet);
	return 1;
}

int ListCtrl_HyperLinkGetShellFileSuffix(lua_State* luaState)
{
	CString strRet = "";
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	CGridColumnTraitHyperLink* pHyperLinkTrait = (CGridColumnTraitHyperLink*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	if (pHyperLinkTrait)
		strRet = pHyperLinkTrait->GetShellFileSuffix();
	lua_pushstring(luaState,strRet);
	return 1;
}

int ListCtrl_HyperLinkSetShellFilePrefix(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitHyperLink* pHyperLinkTrait = (CGridColumnTraitHyperLink*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	CString strPrefix = IRLUA_PLUGIN_CheckString(luaState,2);
	if (pHyperLinkTrait)
	pHyperLinkTrait->SetShellFilePrefix(strPrefix);
	return 0;
}

int ListCtrl_HyperLinkSetShellFileSuffix(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitHyperLink* pHyperLinkTrait = (CGridColumnTraitHyperLink*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	CString strSuffix = IRLUA_PLUGIN_CheckString(luaState,2);
	if (pHyperLinkTrait)
		pHyperLinkTrait->SetShellFileSuffix(strSuffix);
	return 0;
}

int ListCtrl_HyperLinkSetSingleClickEdit(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitHyperLink* pHyperLinkTrait = (CGridColumnTraitHyperLink*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	BOOL bValue = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	if (pHyperLinkTrait)
		pHyperLinkTrait->SetSingleClickEdit(bValue?true:false);
	return 0;
}

int ListCtrl_HyperLinkSetShellApplication(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitHyperLink* pHyperLinkTrait = (CGridColumnTraitHyperLink*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	CString strApp = IRLUA_PLUGIN_CheckString(luaState,2);
	if (pHyperLinkTrait)
		pHyperLinkTrait->SetShellApplication(strApp);
	return 0;
}

int ListCtrl_HyperLinkSetLinkColor(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitHyperLink* pHyperLinkTrait = (CGridColumnTraitHyperLink*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	COLORREF Color = (COLORREF)IRLUA_PLUGIN_CheckNumber(luaState,2);
	if (pHyperLinkTrait)
		pHyperLinkTrait->SetLinkColor(Color);
	return 0;
}

int ListCtrl_HyperLinkSetLinkColorHot(lua_State* luaState)
{
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	CGridColumnTraitHyperLink* pHyperLinkTrait = (CGridColumnTraitHyperLink*)(LPARAM)IRLUA_PLUGIN_CheckNumber(luaState,1);
	COLORREF Color = (COLORREF)IRLUA_PLUGIN_CheckNumber(luaState,2);
	if (pHyperLinkTrait)
		pHyperLinkTrait->SetLinkColorHot(Color);
	return 0;
}

int ListCtrl_CreateHyperLinkTrait(lua_State* luaState)
{
	CGridColumnTraitHyperLink *pHyperLinkTrait = new CGridColumnTraitHyperLink;
	if (pHyperLinkTrait)
	lua_pushnumber(luaState,(LPARAM)pHyperLinkTrait);
	else
	lua_pushnil(luaState);
	return 1;
}

int ListCtrl_InsertColumn(lua_State* luaState)
{

	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nResult = -1;
	int nCol = 0;
	CString lpszColumnHeading = "";
	int nFormat = -1;
	int nWidth = 100;
	int nSubItem = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,6);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	lpszColumnHeading = IRLUA_PLUGIN_CheckString(luaState,3);
	nFormat = (int)IRLUA_PLUGIN_CheckNumber(luaState,4);
	nWidth = (int)IRLUA_PLUGIN_CheckNumber(luaState,5);
	nSubItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,6);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->InsertColumn(nCol,lpszColumnHeading,nFormat,nWidth,nSubItem);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nResult);
	return 1;
}


int ListCtrl_InsertItem(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	CString strText = "";
	int nResult = -1 ,nItem = 0;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	strText = IRLUA_PLUGIN_CheckString(luaState,3);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->InsertItem(nItem,strText);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nResult);
	return 1;
}

int ListCtrl_SetRedraw(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bRedraw = TRUE;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	bRedraw = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetRedraw(bRedraw);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetItemText(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nItem,nSubItem;
	LPCTSTR lpszText;
	IRLUA_PLUGIN_CheckNumArgs(luaState,4);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	nSubItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,3);
	lpszText = IRLUA_PLUGIN_CheckString(luaState,4);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetItemText(nItem,nSubItem,lpszText);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetFocus(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetFocus();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_DeleteAllItems(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bResult = FALSE;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						bResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->DeleteAllItems();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bResult);
	return 1;
}

int ListCtrl_DeleteColumn(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nCol;
	BOOL bResult = FALSE;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						bResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->DeleteColumn(nCol);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bResult);
	return 1;
}

int ListCtrl_DeleteItem(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nItem;
	BOOL bResult = FALSE;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						bResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->DeleteItem(nItem);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bResult);
	return 1;
}

int ListCtrl_GetItemCount(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nResult = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetItemCount();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nResult);
	return 1;
}

int ListCtrl_GetColumnCount(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nResult = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetColumnCount();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nResult);
	return 1;
}

int ListCtrl_GetColumnWidth(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nResult = -1,nCol;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetColumnWidth(nCol);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nResult);
	return 1;
}

int ListCtrl_GetColumnHeading(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	CString sResult = "";
	int nCol;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						sResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetColumnHeading(nCol);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushstring(luaState,sResult);
	return 1;
}

int ListCtrl_GetItemText(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	CString sResult = "";
	int nItem,nSubItem;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	nSubItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,3);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						sResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetItemText(nItem,nSubItem);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushstring(luaState,sResult);
	return 1;
}

int ListCtrl_GetFocusCell(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nResult = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetFocusCell();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nResult);
	return 1;
}

int ListCtrl_GetFocusRow(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nResult = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetFocusRow();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nResult);
	return 1;
}

int ListCtrl_GetHotItem(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nResult = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetHotItem();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nResult);
	return 1;
}

int ListCtrl_SetCheckBoxOnHeader(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nCol;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						HWND header = ListView_GetHeader(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd);
						// Store the ID of the header control so we can handle its notification by ID
						//int m_HeaderId = ::GetDlgCtrlID(header);

						// Now, we can update the format for the first header item,
						// which corresponds to the first column
						HDITEM hdi;
						hdi.mask = HDI_FORMAT;
						Header_GetItem(header, nCol, &hdi);
						hdi.fmt |= HDF_CHECKBOX /*| HDF_FIXEDWIDTH*/;
						Header_SetItem(header, nCol, &hdi);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_GetCheck(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nItem;
	BOOL bResult = FALSE;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						bResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetCheck(nItem);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bResult);
	return 1;
}

int ListCtrl_SetCheck(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nItem;
	BOOL fCheck;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	fCheck = IRLUA_PLUGIN_CheckBoolean(luaState,3);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetCheck(nItem,fCheck);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetCheckAllItems(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL fCheck;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	fCheck = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetCheck(-1,fCheck);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetColumnWidthAuto(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nCol;
	BOOL bIncludeHeader;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	bIncludeHeader = IRLUA_PLUGIN_CheckBoolean(luaState,3);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetColumnWidthAuto(nCol,bIncludeHeader?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SelectAllRows(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bSelect;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	bSelect = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SelectRow(-1,bSelect?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SelectRow(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nRow;
	BOOL bSelect;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nRow = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	bSelect = IRLUA_PLUGIN_CheckBoolean(luaState,3);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SelectRow(nRow,bSelect?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetCellTextColor(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	COLORREF cTextColor;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	cTextColor = (COLORREF)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetCellTextColor(cTextColor);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetCellBackColor(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	COLORREF cBackColor;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	cBackColor = (COLORREF)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetCellBackColor(cBackColor);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetTooltipText(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	CString strText;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	strText = IRLUA_PLUGIN_CheckString(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetTooltipText(strText);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetTooltipTitle(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	CString strText;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	strText = IRLUA_PLUGIN_CheckString(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetTooltipTitle(strText);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetBkColor(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	COLORREF cr;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	cr = (COLORREF)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetBkColor(cr);
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->Invalidate(FALSE);
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->UpdateWindow();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}

	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_GetBkColor(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	COLORREF cr = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);

	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						cr = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetBkColor();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,cr);
	return 1;
}

int ListCtrl_IsCellEditorOpen(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	bool bResult = false;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);

	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						bResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->IsCellEditorOpen();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bResult?TRUE:FALSE);
	return 1;
}

int ListCtrl_RedrawItems(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nFirst = 0;
	int nLast = 0;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nFirst = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	nLast = (int)IRLUA_PLUGIN_CheckNumber(luaState,3);

	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->RedrawItems(nFirst,nLast);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetColumnWidth(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nCol = 0;
	int cx = 100;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	cx = (int)IRLUA_PLUGIN_CheckNumber(luaState,3);

	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetColumnWidth(nCol,cx);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetFocusCell(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nCol = 0;
	BOOL bRedraw = FALSE;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	bRedraw = IRLUA_PLUGIN_CheckBoolean(luaState,3);

	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetFocusCell(nCol,bRedraw?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetFocusRow(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nRow = 0;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nRow = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetFocusRow(nRow);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetHotItem(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int iIndex = 0;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	iIndex = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetHotItem(iIndex);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetItemData(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nItem = 0;
	DWORD_PTR dwData = 0;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	dwData = (int)IRLUA_PLUGIN_CheckNumber(luaState,3);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetItemData(nItem,dwData);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_GetItemData(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nItem = 0;
	DWORD_PTR dwData = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						dwData = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetItemData(nItem);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState, dwData);
	return 1;
}

int ListCtrl_EnableTooltips(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bValue;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	bValue = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						CToolTipCtrl* pToolTipCtrl = (CToolTipCtrl*)CWnd::FromHandle((HWND)::SendMessage(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd, LVM_GETTOOLTIPS, 0, 0L));
						//CToolTipCtrl* pToolTipCtrl = AfxGetModuleThreadState()->m_pToolTip;
						if (pToolTipCtrl!=NULL && pToolTipCtrl->m_hWnd!=NULL)
						{
							pToolTipCtrl->Activate(bValue);
						}
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetFont(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	CString strFontName;
	int FontSize,Weigth,Charset;
	BOOL Italic,Underline,StrikeOut;
	IRLUA_PLUGIN_CheckNumArgs(luaState,8);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	FontSize = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	Weigth = (int)IRLUA_PLUGIN_CheckNumber(luaState,3);
	Italic = IRLUA_PLUGIN_CheckBoolean(luaState,4);
	Underline = IRLUA_PLUGIN_CheckBoolean(luaState,5);
	StrikeOut = IRLUA_PLUGIN_CheckBoolean(luaState,6);
	strFontName = IRLUA_PLUGIN_CheckString(luaState,7);
	Charset = (int)IRLUA_PLUGIN_CheckNumber(luaState,8);

	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						CFont m_font;
						   m_font.CreateFont(
						   FontSize,                        // nHeight
						   0,                         // nWidth
						   0,                         // nEscapement
						   0,                         // nOrientation
						   Weigth,                 // nWeight
						   Italic,                     // bItalic
						   Underline,                     // bUnderline
						   StrikeOut,                         // cStrikeOut
						   Charset,              // nCharSet
						   OUT_DEFAULT_PRECIS,        // nOutPrecision
						   CLIP_DEFAULT_PRECIS,       // nClipPrecision
						   DEFAULT_QUALITY,           // nQuality
						   DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
						   strFontName);
							pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetFont(&m_font,TRUE);
							m_font.DeleteObject();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_FindItem(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	CString strText;
	int nIndex = -1;
	int nStart = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	strText = IRLUA_PLUGIN_CheckString(luaState,2);
	nStart = (int)IRLUA_PLUGIN_CheckNumber(luaState,3);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						LVFINDINFO info;
						info.flags = LVFI_PARTIAL|LVFI_STRING;
						info.psz = strText;
						nIndex = pListCtrl->m_pListCtrlHolder->m_pListCtrl->FindItem(&info,nStart);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState, nIndex);
	return 1;
}

int ListCtrl_EnsureVisible(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nItem;
	BOOL bPartialOK;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	bPartialOK = IRLUA_PLUGIN_CheckBoolean(luaState,3);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->EnsureVisible(nItem,bPartialOK);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_UpdateWindow(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bRedraw;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	bRedraw = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->Invalidate(bRedraw);
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->UpdateWindow();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_GetSelectedItems(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						POSITION pos = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetFirstSelectedItemPosition();
						if (pos == NULL) lua_pushnil(luaState);
						else
						lua_newtable(luaState);
						int i=1;
						while (pos)
							{
								int nItem = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetNextSelectedItem(pos);
								lua_pushnumber(luaState, nItem);
								lua_rawseti(luaState, -2,i++);
							}
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 1;
}

int ListCtrl_GetSelectedCount(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	UINT nSelectedItems = -1;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nSelectedItems = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetSelectedCount();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,nSelectedItems);
	return 1;
}

int ListCtrl_IsItemSelected(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bValue = FALSE;
	int nItem;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItem = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						if (pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetItemState(nItem,LVNI_SELECTED) & LVNI_SELECTED)
							bValue = TRUE;
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bValue);
	return 1;
}

int ListCtrl_EditCell(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nRow,nCol;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nRow = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,3);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->EditCell(nRow,nCol);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_EnsureColumnVisible(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bPartialOK = FALSE;
	int nCol;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	bPartialOK = IRLUA_PLUGIN_CheckBoolean(luaState,3);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->EnsureColumnVisible(nCol,bPartialOK?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_ShowColumn(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nCol;
	BOOL bShow;

	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	bShow = IRLUA_PLUGIN_CheckBoolean(luaState,3);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->ShowColumn(nCol,bShow?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_IsColumnVisible(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nCol;
	bool bShow = false;

	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						bShow = pListCtrl->m_pListCtrlHolder->m_pListCtrl->IsColumnVisible(nCol);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bShow?TRUE:FALSE);
	return 1;
}

int ListCtrl_MoveFocusCell(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bMoveRight;

	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	bMoveRight = IRLUA_PLUGIN_CheckBoolean(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->MoveFocusCell(bMoveRight?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_CopyToClipBoard(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;

	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->OnCopyToClipboard();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_GetCheckedItems(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						int count = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetItemCount();
						if (count>0)
						{
							lua_newtable(luaState);
							int index = 1;
								for (int i=0;i<count;i++)
								{
									if (pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetCheck(i))
									{
										lua_pushnumber(luaState, i);
										lua_rawseti(luaState, -2,index++);
									}
								}
						}
						else
						{
							lua_pushnil(luaState);
						}
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 1;
}

int ListCtrl_GroupByColumn(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nCol;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->GroupByColumn(nCol);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_IsGroupViewEnabled(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bRet = FALSE;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						bRet = pListCtrl->m_pListCtrlHolder->m_pListCtrl->IsGroupViewEnabled();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bRet);
	return 1;
}

int ListCtrl_RemoveAllGroups(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;

	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						int pos = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetScrollPos(SB_VERT);
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->EnsureVisible(0,FALSE);
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->RemoveAllGroups();
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->EnableGroupView(FALSE);
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->Scroll(CSize(0,pos));
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_IsGroupStateEnabled(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	BOOL bRet = FALSE;
	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						bRet = pListCtrl->m_pListCtrlHolder->m_pListCtrl->IsGroupStateEnabled();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bRet);
	return 1;
}

int ListCtrl_GetGroupHeader(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	CString strHeader = "";
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	int nGroupId = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						strHeader = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetGroupHeader(nGroupId);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushstring(luaState,strHeader);
	return 1;
}

int ListCtrl_CheckEntireGroup(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nGroupId;
	BOOL bChecked;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nGroupId = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	bChecked = IRLUA_PLUGIN_CheckBoolean(luaState,3);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->CheckEntireGroup(nGroupId,bChecked?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_ExpandAllGroups(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;

	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->ExpandAllGroups();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_CollapseAllGroups(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;

	IRLUA_PLUGIN_CheckNumArgs(luaState,1);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->CollapseAllGroups();
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_DeleteEntireGroup(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;

	CString strObjectName;
	int nGroupId;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nGroupId = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->DeleteEntireGroup(nGroupId);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SortColumn(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;
	bool bResult = false;
	CString strObjectName;
	int nCol;
	BOOL bAscending;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	bAscending = IRLUA_PLUGIN_CheckBoolean(luaState,3);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						bResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->SortColumn(nCol,bAscending?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushboolean(luaState,bResult?TRUE:FALSE);
	return 1;
}

int ListCtrl_SetSortArrow(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;
	
	CString strObjectName;
	int nCol;
	BOOL bAscending;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	bAscending = IRLUA_PLUGIN_CheckBoolean(luaState,3);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetSortArrow(nCol,bAscending?true:false);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_GetColumnData(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;
	
	int nResult = 0;
	CString strObjectName;
	int nCol;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetColumnData(nCol);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,(int)nResult);
	return 1;
}

int ListCtrl_GetColumnOrder(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;
	
	int nResult = -1;
	CString strObjectName;
	int nCol;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						nResult = pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetColumnOrder(nCol);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	lua_pushnumber(luaState,(int)nResult);
	return 1;
}

int ListCtrl_SetColumnOrder(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;
	
	CString strObjectName;
	int nCol,nOrder;
	LVCOLUMN lvc = {0};
	lvc.mask = LVCF_ORDER;
	IRLUA_PLUGIN_CheckNumArgs(luaState,3);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nCol = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	nOrder = (int) IRLUA_PLUGIN_CheckNumber(luaState,3);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						if (pListCtrl->m_pListCtrlHolder->m_pListCtrl->GetColumn(nCol,&lvc))
						{
							lvc.iOrder = nOrder;
							pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetColumn(nCol,&lvc);
						}
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetItemCount(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;
	
	CString strObjectName;
	int nItems;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	nItems = (int)IRLUA_PLUGIN_CheckNumber(luaState,2);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetItemCount(nItems);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

int ListCtrl_SetEmptyMarkupText(lua_State* luaState)
{
	IRLUA_PLUGIN_ResetLastError(luaState);
	int nLastError = 0;
	
	CString strObjectName,strText;
	IRLUA_PLUGIN_CheckNumArgs(luaState,2);
	strObjectName = IRLUA_PLUGIN_CheckString(luaState,1);
	strText = IRLUA_PLUGIN_CheckString(luaState,2);
	CIRPluginObject* pObject = NULL;
	pObject = IRLUA_PLUGIN_GetObjectPtr(luaState,strObjectName);
	if(pObject)
	{
		int nSize = 1000;
		char szObjectID[1000];
		pObject->GetObjectID(szObjectID,&nSize);

		if(lstrcmp(szObjectID,"IR_LISTCTRL_OBJECT") == 0)
		{
			CListCtrlObject* pListCtrl = (CListCtrlObject*) pObject;
			if(pListCtrl->m_pListCtrlHolder)
			{
				if(pListCtrl->m_pListCtrlHolder->m_pListCtrl)
				{
					if(IsWindow(pListCtrl->m_pListCtrlHolder->m_pListCtrl->m_hWnd))
					{
						pListCtrl->m_pListCtrlHolder->m_pListCtrl->SetEmptyMarkupText(strText);
					}
				}
			}
		} else
		{
			nLastError = 1100; // "The specified object could not be found."
		}
	} else
	{
		nLastError = 1100; // "The specified object could not be found."
	}
	IRLUA_PLUGIN_SetLastError(luaState,nLastError);
	return 0;
}

void ListCtrl_RegisterLuaFunctions(lua_State* luaState)
{
	luaL_openlib(luaState, "ListCtrl", lib_ListCtrl, 0);
}