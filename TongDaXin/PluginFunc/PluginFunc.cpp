#pragma once

#include "pch.h"

#include <minwindef.h>

#include "__inter__FunctionalFunctions.h"
#include "PluginFunc.h"


PluginTCalcFuncInfo g_CalcFuncSets[] = {
	{ 1, (pPluginFUNC)&SaveData },
	{ 0, nullptr				 }
};

BOOL RegisterTdxFunc(PluginTCalcFuncInfo* pFun[])
{
	if ((*pFun) == nullptr)
	{
		(*pFun) = g_CalcFuncSets;

		return TRUE;
	}

	return FALSE;
}
