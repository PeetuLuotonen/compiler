#include "../headers/preprocessor.h"

using namespace std;

string Preprocessor::readFileToString(string sourceFile) {
	ifstream t(sourceFile);
	stringstream buffer;
	buffer << t.rdbuf();
	string contents = buffer.str();
	return contents;
}

void Preprocessor::removeComments(string &sourceCode) {
    // single line comment removal
    std::regex singleLinePattern_re("#[a-zA-Z0-9_;: ]*\\n");
    sourceCode = std::regex_replace(sourceCode, singleLinePattern_re, "\n");
    
    // multiline comment removal
    std::regex singleLinePattern_re("###[a-zA-Z0-9_;: \\]*###\\n");
    sourceCode = std::regex_replace(sourceCode, singleLinePattern_re, "\n");
}

void Preprocessor::removeWhitespace(string &sourceCode) {
    // resolve the overload with isspace method
    auto f = [](unsigned char const c) { return std::isspace(c); };
    sourceCode.erase(remove_if(sourceCode.begin(), sourceCode.end(), f), sourceCode.end());
}

string Preprocessor::preprocess(string sourceFile) {
	string sourceCode = readFileToString(sourceFile);
    cout << "Unprocessed string: " << sourceCode << endl;
	removeComments(sourceCode);
	removeWhitespace(sourceCode);
    cout << "Processed string: " << sourceCode << endl;
	return sourceCode;
}