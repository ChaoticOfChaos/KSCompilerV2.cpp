#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

#include "KSCompiler.h"

// Argv = [0]: Path | [1]: Type, [2]: Name/Path, [3]: Lenguage
int main(int argc, char *argv[]) {
	if (argc < 4) {
		std::cerr << "Error. Arguments Missing" << std::endl;
		return 1;
	}

	std::string type = argv[1];
	std::string name = argv[2];
	std::string lenguage = argv[3];

	if (type == "1" || type == "name") {
		int result = HardCOMP(name, lenguage);

		if (result == 1) {
			std::cerr << "Error. Compile" << std::endl;
		}
		return result;
	}
	else if (type == "2" || type == "path") {
		int result = SimpleCOMP(name, lenguage);

		if (result == 1) {
			std::cerr << "Error. Compile" << std::endl;
		}
		return result;
	}
}