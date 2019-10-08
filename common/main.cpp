#include <iostream>
#include "Compiler.hpp"

using namespace std;

int main (int argc, char *argv[]) {
	//"/home/user/Documents/ProjectI/common/file.txt"
	const std::string file = string(argv[1]);
    Ilang::Compiler* c = new Ilang::Compiler(file); // Параметр - имя файла


	delete c;

    return 0;
}
