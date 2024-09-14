#pragma once

#include <format>
#include <iostream>
#include <string>

#include "./PluginFunc/PluginFunc.h"

int main(int argc, char* argv[])
{
	using namespace std;

	auto IOArgCount = 20;

	auto Output		= new float[IOArgCount];
	auto Input_a	= new float[IOArgCount];
	auto Input_b	= new float[IOArgCount];
	auto Input_c	= new float[IOArgCount];

	for (auto i = 0; i < IOArgCount; i++)
	{
		Input_a[i] = (float)i;
		Input_b[i] = (float)i * 2;
		Input_c[i] = (float)i * 3;
	}

	if (PluginTCalcFuncInfo* pluginFuncs = nullptr; RegisterTdxFunc(&pluginFuncs))
	{
		for (size_t i = 0; pluginFuncs[i].nFuncMark != 0; ++i)
		{
			cout << format("插件功能列表注册成功，插件功能标识：{}\n", pluginFuncs[i].nFuncMark);

			if (pluginFuncs[i].pCallFunc == nullptr)
			{
				cout << format("插件功能标识：{}，函数指针为空。\n", pluginFuncs[i].nFuncMark);
				continue;
			}

			pluginFuncs[i].pCallFunc(IOArgCount, Output, Input_a, Input_b, Input_c);

			if (Output == nullptr)
			{
				cout << format("插件功能标识：{}，输出指针为空。\n", pluginFuncs[i].nFuncMark);
				break;
			}

			for (auto j = 0; j < IOArgCount; j++)
			{
				cout << format("插件功能标识：{}，输出值：{}\n", pluginFuncs[i].nFuncMark, Output[j]);
			}

			cout << endl;
		}
	}
	else
	{
		cout << format("插件功能列表注册失败。\n");
	}

	delete[] Output;
	delete[] Input_a;
	delete[] Input_b;
	delete[] Input_c;

	return 0;
}
