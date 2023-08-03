#include "../src/Caption.h"
#include "../src/Timer.h"
#include "../src/CaptionList.h"
#include <iostream>
#include <string>

int main() {
	
	std::string file = "Dependencies/Captions.csv";
	CaptionList list(file);
	// CaptionList list("Test.csv");
	

	// std::vector<Caption> captions = list.getCaptions();
	// std::cout << "getCaptions() did not segfault" << std::endl;
	//
	//
	// std::vector<Caption>::iterator iter = captions.begin();
	// for (; iter != captions.end(); iter++) {
	// 	std::cout << iter->getUsername() << std::endl;
	// }
	// std::cout << "printing captions did not segfault" << std::endl;
}
