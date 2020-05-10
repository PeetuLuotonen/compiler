#include "../headers/compiler.h"

using namespace std;
using namespace compiler;

int main() {
	// test source file
	string sourceFile = "testSourceFile.txt";
	Compiler compiler;
	compiler.compile(sourceFile);
    return 0;
}