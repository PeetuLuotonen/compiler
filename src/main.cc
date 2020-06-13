#define _CRTDBG_MAP_ALLOC
#define DEBUG
#ifdef DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // DEBUG



#include "../headers/compiler.h"
#include <crtdbg.h>


using namespace std;
using namespace compiler;

int main() {
	// test source file
	string sourceFile = "testSourceFile.txt";
	Compiler compiler;
	compiler.compile(sourceFile);
    cin.get();
	_CrtDumpMemoryLeaks();
    return 0;
}