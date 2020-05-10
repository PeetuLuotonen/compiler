#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class Preprocessor {
public:
	std::string preprocess(std::string sourceFile);
private:
	std::string readFileToString(std::string sourceFile);
	void removeComments(std::string sourceCode);
	void removeWhitespace(std::string sourceCode);
};