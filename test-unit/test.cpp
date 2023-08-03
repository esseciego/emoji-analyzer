#include "../src/Caption.h"
#include "../src/Timer.h"
#include "../src/CaptionList.h"
#include <iostream>
#include <string>

int main() {
	
	std::string file = "Dependencies/Captions.csv";
	CaptionList list(file);
	

	// std::cout << "Testing mergeSort() function..." << std::endl;
	// list.mergeSort();
	// std::cout << "Time: " << list.getTime() << " ms" << std::endl;


	std::cout << "Testing quickSort() function..." << std::endl;
	list.quickSort();
	std::cout << "Time: " << list.getTime() << " ms" << std::endl;
}
