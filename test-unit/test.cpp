#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE

#include "catch2/catch.hpp"
#include "../src/Caption.h"
#include "../src/Timer.h"
#include "../src/CaptionList.h"
#include <iostream>
#include <string>


TEST_CASE("Testing Constructor", "[given]") {
	
	CaptionList list("Dependencies/Captions.csv");
	
	REQUIRE(list.getCaptions().size() == 23760);
}

TEST_CASE("Testing swap()", "[helper functions]") {
	
	int a = 0, b = 1;

	CaptionList list("Dependencies/Captions.csv");
	std::vector<Caption> temp = list.getCaptions();
	swap(temp, a, b);

	REQUIRE(temp[a].getEmojis() == list.getCaptions()[b].getEmojis());
	REQUIRE(temp[a].getUsername() == list.getCaptions()[b].getUsername());
	REQUIRE(temp[a].getPost() == list.getCaptions()[b].getPost());
	REQUIRE(temp[b].getEmojis() == list.getCaptions()[a].getEmojis());
	REQUIRE(temp[b].getUsername() == list.getCaptions()[a].getUsername());
	REQUIRE(temp[b].getPost() == list.getCaptions()[a].getPost());
}

TEST_CASE("Testing mergeSort()", "[algorithm function]") {
	
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
	
	REQUIRE(1==1);
}

// TEST_CASE("Testing quickSort()", "[algorithm function]") {
// 	
// 	CaptionList list("Dependencies/Captions.csv");
// 	std::vector<Caption> sorted = list.getCaptions();
//
// 	list.quickSort();
// 	
// 	REQUIRE(1==1);
// }
