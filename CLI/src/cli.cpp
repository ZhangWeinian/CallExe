#pragma once

#include <cstdlib>
#include <string>

int main(int argc, char* argv[])
{
	using namespace ::std;

	string commandLine { R"("D:\Program Files (local)\N_m3u8DL-RE\N_m3u8DL-RE.exe")" };

	for (int i = 1; i < argc; ++i)
	{
		commandLine += ' ';
		commandLine += argv[i];
	}

	::system(commandLine.data());

	return EXIT_SUCCESS;
}
