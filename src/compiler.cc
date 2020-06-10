#include "../headers/compiler.h"
#include "../headers/lexer.h"

using namespace std;

namespace compiler {
	void Compiler::compile(string sourceFile) {
		string preprocessedSourceFile = preprocessor.preprocess(sourceFile);
		// test print
		cout << preprocessedSourceFile;
		Lexer lexer = Lexer(preprocessedSourceFile);
		lexer.tokenize();
		parser.parse();
	};
}