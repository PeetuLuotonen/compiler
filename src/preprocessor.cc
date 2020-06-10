#include "../headers/preprocessor.h"

using namespace std;

string Preprocessor::readFileToString(string sourceFile) {
	ifstream t(sourceFile);
	if (!t)
	{
		cerr << "File could not be opened!\n";
		cerr << "Error code: " << strerror(errno);
	}
	stringstream buffer;
	buffer << t.rdbuf();
	string contents = buffer.str();
	return contents;
}

void Preprocessor::removeSinglelineComment(string &sourceCode) {
    // single line comment removal
    std::regex singleLinePattern_re("#[a-zA-Z0-9_;: ]*\\n");
    sourceCode = std::regex_replace(sourceCode, singleLinePattern_re, "\n");
}

void Preprocessor::removeWhitespace(string &sourceCode) {
    // resolve the overload with isspace method
    auto f = [](unsigned char const c) { return std::isspace(c); };
    sourceCode.erase(remove_if(sourceCode.begin(), sourceCode.end(), f), sourceCode.end());
}

std::string Preprocessor::removeMultilineComment(std::string& sourceCode)
{
	std::string output;
	for (size_t i = 0; i < sourceCode.length(); ++i)
	{
		if (sourceCode[i] == '#')
		{
			i++;
			while (!(sourceCode[i] == '#' && sourceCode[i+1] == '#'))
			{
				i++;
			}
			i++;
		}
		else
		{
			output += sourceCode[i];
		}
	}
	return output;
}

string Preprocessor::preprocess(string sourceFile) {
	string sourceCode = readFileToString(sourceFile);
    cout << "Unprocessed string: \n" << sourceCode << endl;
	removeSinglelineComment(sourceCode);
	// removeWhitespace(sourceCode);
	std::string cleanStr = removeMultilineComment(sourceCode);
    cout << "Processed string: " << cleanStr << endl;
	return cleanStr;
}