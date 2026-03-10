#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "parser.h"

const std::string file = "Text.txt";

int main()
{
	parser myParser(file);
	std::set<std::string>sigma = myParser.getSigma();
	std::set<std::string>nodes = myParser.getNodes();
	std::set<std::string>finals = myParser.getFinals();
	std::string start = myParser.getStart();
	std::map < std::string, std::map < std::string, std::string >>relations = myParser.getRelations();

	std::vector<std::string>toParse = myParser.getStringToParse();


	for (auto& currentString : toParse) {
		if (relations[start].empty()) {
			std::cout << "Compilation error\n";
			break;
		}
			
		else if (relations[start][currentString].empty()) {
			std::cout << "Compilation error\n";
			break;
		}
			
		else
			start = relations[start][currentString];
	}

	if (finals.find(start) != finals.end())
		std::cout << "Accepted input!";
	else
		std::cout << "Invalid input!";
}
