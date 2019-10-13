#include <sstream>

char* s_t=0;
long l1=0;

std::ostringstream gatherstr;

extern std::ostringstream* mirror() {
	return &gatherstr;
}

extern "C" void drop_buf() {
	gatherstr.str("");
}

extern "C" void printf_into(char* s) {
	gatherstr << std::string(s);
}
 
