#pragma once
#include <iostream>
#include <string>
#include "preprocessor.h"
#include "lexer.h"
#include "parser.h"

namespace compiler {
	class Compiler {
	private:
		Preprocessor preprocessor;
		Parser parser;
	public:
		void compile(std::string sourceFile);
	};
}