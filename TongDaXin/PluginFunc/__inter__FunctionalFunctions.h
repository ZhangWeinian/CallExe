#pragma once

#include "pch.h"

// 测试函数
void SaveData(int IOArgCount, float* Output, const float* Input_a, const float* Input_b, const float* Input_c)
{
	for (int i = 0; i < IOArgCount; i++)
	{
		Output[i] = Input_a[i] + Input_b[i] + Input_c[i];
	}
}
