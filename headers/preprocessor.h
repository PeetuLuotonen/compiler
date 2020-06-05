#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <regex>

class Preprocessor {
public:
	std::string preprocess(std::string sourceFile);
private:
	std::string readFileToString(std::string sourceFile);
	void removeSinglelineComment(std::string &sourceCode);
	void removeWhitespace(std::string &sourceCode);
	std::string removeMultilineComment(std::string& sourceCode);
};