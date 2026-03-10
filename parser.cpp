#include "parser.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <set>

const std::string sigmaIdentifier = "[sigma]";
const std::string nodesIdentifier = "[nodes]";
const std::string finalIdentifier = "[final]";
const std::string relationsIdentifier = "[relations]";
const std::string startIdentifier = "[start]";
const std::string endIdentifier = "[end]";
const std::string inputIdentifier = "[input]";


parser::parser(std::string path) {
	filePath = path;
}

const std::set<std::string> const parser::getSigma () {
	std::set<std::string> sigma = getElements(sigmaIdentifier);
	return sigma;
}

const std::set<std::string> const parser::getNodes() {
	std::set<std::string> nodes = getElements(nodesIdentifier);
	return nodes;
}

const std::set<std::string> const parser::getFinals() {
	std::set<std::string> finals = getElements(finalIdentifier);
	return finals;
}

const std::string const parser::getStart() {
	std::set<std::string> start = getElements(startIdentifier);
	if (start.empty())
		return "";
	return *start.begin();
}

const std::vector<std::string> const parser::getStringToParse() {
	std::vector<std::string>toParse = getElementsVector(inputIdentifier);
	return toParse;
}

const std::set<std::string> const parser::getElements(std::string searched) {
	std::ifstream file(filePath);
	std::set<std::string> sigma;
	if (!file.is_open()) {
		std::cout << "Could not open file " << filePath << std::endl;
		return sigma;
	}

	std::string currentLine;
	bool isSearched = false;
	while (std::getline(file, currentLine)) {
		if (isSearched && currentLine != endIdentifier)
			sigma.insert(currentLine);
		if (currentLine == searched)
			isSearched = true;
		else if (isSearched && currentLine == endIdentifier)
			break;

	}
	file.close();
	return sigma;
}

const std::vector<std::string> const parser::getElementsVector(std::string searched) {
	std::ifstream file(filePath);
	std::vector<std::string> sigma;
	if (!file.is_open()) {
		std::cout << "Could not open file " << filePath << std::endl;
		return sigma;
	}

	std::string currentLine;
	bool isSearched = false;
	while (std::getline(file, currentLine)) {
		if (isSearched && currentLine != endIdentifier)
			sigma.push_back(currentLine);
		if (currentLine == searched)
			isSearched = true;
		else if (isSearched && currentLine == endIdentifier)
			break;

	}
	file.close();
	return sigma;
}

const std::map < std::string, std::map < std::string, std::string >> const parser::getRelations() {
	std::ifstream file(filePath);
	std::map < std::string, std::map < std::string, std::string >>relations;
	if (!file.is_open()) {
		std::cout << "Could not open file " << filePath << std::endl;
		return relations;
	}

	std::string currentLine;
	bool isSearched = false;
	while (std::getline(file, currentLine)) {
		if (isSearched && currentLine != endIdentifier) {
			modifyRelations(currentLine, relations);
		}
		if (currentLine == relationsIdentifier)
			isSearched = true;
		else if (isSearched && currentLine == endIdentifier)
			break;
	}

	file.close();
	return relations;
}

void parser::modifyRelations(std::string &currentLine,std::map < std::string, std::map < std::string, std::string >>& relations) {
	std::string operand1, operand2, result;
	bool plus, equal;
	plus = equal = false;
	for (char& c : currentLine) {
		if (c == ' ')
			continue;
		if (c == '+')
			plus = true;
		else if (c == '=')
			equal = true;
		else {
			if (plus == false)
				operand1 += c;
			else if (plus == true && equal == false)
				operand2 += c;
			else
				result += c;
		}
	}
	relations[operand1][operand2] = result;
}