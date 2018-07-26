#include "MatrixHierarchy_ProgramApp.h"

int main() {
	
	// allocation
	auto app = new MatrixHierarchy_ProgramApp();

	// initialise and loop
	app->run("AIE", 1280, 720, false);

	// deallocation
	delete app;

	return 0;
}