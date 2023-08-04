#include "../src/Caption.h"
#include "../src/Timer.h"
#include "../src/CaptionList.h"
#include <iostream>
#include <string>

int main() {
	CaptionList list("Dependencies/Captions.csv");

	list.mergeSort();
	std::cout << "Time to run function: " << list.getTime() << " ms" << std::endl;
	std::vector<Caption> sorted = list.getCaptions();

	for (int i = 0; i < list.getCaptions().size(); i++) {
		for (int j = 0; j < sorted[i].getEmojis().size(); j++) {
			std::cout << sorted[i].getEmojis()[j] << " ";
		}
		std::cout << std::endl;
	}

}
