#include <cstdlib>
#include <string>

int main(int argc, char* argv[])
{
	using namespace ::std;

	string commandLine { R"("E:\Project\Git\bin\git.exe")" };

	for (int i = 1; i < argc; ++i)
	{
		commandLine += ' ';
		commandLine += argv[i];
	}

	system(commandLine.data());

	return EXIT_SUCCESS;
}
