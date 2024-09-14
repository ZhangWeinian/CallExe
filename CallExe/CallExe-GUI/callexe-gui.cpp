#include <cstdlib>
#include <cstring>
#include <string>

#include <sal.h>
#include <Windows.h>

static inline int CallEXE(const wchar_t* exePath, LPTSTR cmdLineArgs)
{
	STARTUPINFO			si;			 // 用于存储启动信息的结构体
	PROCESS_INFORMATION pi;			 // 用于存储进程信息的结构体

	ZeroMemory(&si, sizeof(si));	 // 清空 STARTUPINFO 结构体
	si.cb = sizeof(si);				 // 设置 STARTUPINFO 结构体的大小
	ZeroMemory(&pi, sizeof(pi));	 // 清空 PROCESS_INFORMATION 结构体

	if (!CreateProcess(exePath,		 // 应用程序名称
					   cmdLineArgs,	 // 命令行参数
					   nullptr,		 // 进程句柄不可继承
					   nullptr,		 // 线程句柄不可继承
					   FALSE,		 // 禁止句柄继承
					   0,			 // 无创建标志
					   nullptr,		 // 使用父进程环境块
					   nullptr,		 // 使用父进程的工作目录
					   &si,			 // 指向 STARTUPINFO 结构体的指针
					   &pi			 // 指向 PROCESS_INFORMATION 结构体的指针
					   ))
	{
		return EXIT_FAILURE;
	}

	// 等待子进程退出
	WaitForSingleObject(pi.hProcess, INFINITE);

	// 关闭线程句柄和进程
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);

	return EXIT_SUCCESS;
}

int WINAPI WinMain(_In_ HINSTANCE	  hInstance,	  // 当前实例的句柄
				   _In_opt_ HINSTANCE hPrevInstance,  // 上一实例的句柄
				   _In_ LPSTR		  lpCmdLine,	  // 命令行
				   _In_ int			  nCmdShow		  // 显示状态
)
{
	using namespace std;

	string	commandArgs(lpCmdLine);
	wstring wCommandArgs(commandArgs.begin(), commandArgs.end());

	wCommandArgs = LR"("C:\Windows\regedit.exe" )" + wCommandArgs;

	/*
	* 关于 pwCommandArgs 数组大小的说明：
	* 此处的数组大小置为 MAX_PATH 会更合理，因为这是 Windows API 中定义的最大路径长度
	* 但是此电脑中已经启用了 LongPathsEnabled，所以这里直使用一个更大的值
	* 这是否会导致一些错误？我不确定，因为我目前没有遇到实际的命令行参数特别长（超过 MAX_PATH ）的情况
	* 通常来说，由此代码编译出的程序，其接受的命令行参数长度取决于实际调用的程序的限制和 CreateProcess 函数对命令行参数长度的限制的最小值
	* 所以这里的数组大小是一个不确定的值
	*/
	TCHAR pwCommandArgs[8000];

	wcscpy_s(pwCommandArgs, 8000, wCommandArgs.data());

	return CallEXE(nullptr, pwCommandArgs);
}
