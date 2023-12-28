#ifndef KSCOMPILER_H
#define KSCOMPILER_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>

int SimpleCOMP(std::string path, std::string language) {

	if (language == "python") {

		std::string exe = "python " + path;
		return system(exe.c_str());

	}
	else if (language == "nodejs") {

		std::string exe = "node " + path;
		return system(exe.c_str());

	}
	else {

		std::string exe = "start " + path;
		return system(exe.c_str());

	}

}

int HardCOMP(std::string name, std::string language) {

	std::ifstream arq("./ProjectsPath.csv");

	std::map<std::string, std::string> translatorMAP = { {"#python", "python"}, {"#nodejs", "nodejs"}, {"#html", "html"}, {"python", "python"}, {"nodejs", "node"}, {"html", "start"} };

	if (!arq.is_open()) {

		std::cerr << "Error. ProjectsPath.csv Not Found" << std::endl;
		return 1;

	}

	std::vector<std::vector<std::string>> datas;

	std::string row;
	while (std::getline(arq, row)) {

		std::vector<std::string> row_data;
		std::istringstream linha_stream(row);
		std::string camp;

		while (std::getline(linha_stream, camp, ',')) {

			row_data.push_back(camp);

		}

		datas.push_back(row_data);
	}

	arq.close();
	bool found = false;
	for (const auto& row_data : datas) {

		for (const auto& campo : row_data) {

			if (campo == name && !found) {

				std::string pathReal = row_data[1];
				std::string languageReal = row_data[2];

				if (languageReal == translatorMAP[language]) {

					std::string exe = translatorMAP[translatorMAP[language]] + " " + pathReal;
					return system(exe.c_str());

				}

				found = true;

			}

		}

	}

}

#endif