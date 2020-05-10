#include "../headers/preprocessor.h"

using namespace std;

string Preprocessor::readFileToString(string sourceFile) {
	ifstream t(sourceFile);
	stringstream buffer;
	buffer << t.rdbuf();
	string contents = buffer.str();
	return contents;
}

void Preprocessor::removeComments(string sourceCode) {

}

void Preprocessor::removeWhitespace(string sourceCode) {

}

string Preprocessor::preprocess(string sourceFile) {
	string sourceCode = readFileToString(sourceFile);
	removeComments(sourceCode);
	removeWhitespace(sourceCode);
	return sourceCode;
}