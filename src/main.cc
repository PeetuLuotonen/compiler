#include <iostream>
#include "../headers/compiler.h"
#include "../headers/preprocessor.h"
#include "../headers/lexer.h"
#include "../headers/parser.h"

int main() {
	Compiler compiler;
	Preprocessor preprocessor;
	Lexer lexer;
	Parser parser;
	compiler.compile();
	preprocessor.preprocess();
	lexer.tokenize();
	parser.parse();
    return 0;
}