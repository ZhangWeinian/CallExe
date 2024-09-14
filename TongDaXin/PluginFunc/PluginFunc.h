#pragma once

#include "pch.h"

#include <minwindef.h>

#include "__inter__AttributeDefinition.h"

// 插件函数注册接口
extern "C" PLUGINFUNCTION_API BOOL RegisterTdxFunc(PluginTCalcFuncInfo* pFun[]);
