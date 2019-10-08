#include <iostream>
#include "Compiler.hpp"

using namespace std;

int main (int argc, char *argv[]) {
    const std::string file = string(argv[1]);
    Ilang::Compiler* c = new Ilang::Compiler(file);

    c->compile();

    delete c;

    return 0;
}
