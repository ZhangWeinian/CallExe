#pragma once

#include "pch.h"

#include <minwindef.h>


#ifdef PLUGINFUNC_EXPORTS
	#define PLUGINFUNCTION_API __declspec(dllexport)
#else
	#define PLUGINFUNCTION_API __declspec(dllimport)
#endif // PLUGINFUNC_EXPORTS


#pragma pack(push, 1)

//函数(数据个数,输出,输入a,输入b,输入c)
using pPluginFUNC = void (*)(int, float*, float*, float*, float*);

// 插件函数信息
using PluginTCalcFuncInfo = struct tagPluginTCalcFuncInfo
{
	unsigned short nFuncMark; //函数编号
	pPluginFUNC	   pCallFunc; //函数地址
};

// 插件函数注册接口
using pRegisterPluginFUNC = BOOL (*)(PluginTCalcFuncInfo**);

#pragma pack(pop)
