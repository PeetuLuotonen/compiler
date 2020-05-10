#include "../headers/compiler.h"

using namespace std;

namespace compiler {
	void Compiler::compile(string sourceFile) {
		string preprocessedSourceFile = preprocessor.preprocess(sourceFile);
		// test print
		cout << preprocessedSourceFile;
		lexer.tokenize();
		parser.parse();
	};
}