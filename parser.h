#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>


class parser {
private:
	std::string filePath;
	const std::set<std::string> const getElements(std::string);
	const std::vector<std::string> const getElementsVector(std::string);
	void modifyRelations(std::string& currentLine, std::map < std::string, std::map < std::string, std::string >>& relations);
public:
	parser(std::string path);

	const std::set<std::string> const getSigma();
	const std::set<std::string> const getNodes();
	const std::set<std::string> const getFinals();
	const std::string const getStart();
	const std::map < std::string, std::map < std::string, std::string >> const getRelations();
	const std::vector<std::string> const getStringToParse();
};
