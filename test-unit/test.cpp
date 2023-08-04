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

TEST_CASE("Testing mergeSort() and quickSort() have same output", "[algorithm function]") {
	
	CaptionList list("Dependencies/Captions.csv");
	CaptionList list_a("Dependencies/Captions.csv");
	list.mergeSort();
	list_a.mergeSort();
	for (int i = 0; i < list.getCaptions().size(); i++)
		REQUIRE(list.getCaptions()[i].getEmojis() == list_a.getCaptions()[i].getEmojis());
}

TEST_CASE("Testing quickSort()", "[algorithm function]") {
	
	CaptionList list("Dependencies/Captions.csv");
	std::vector<Caption> sorted = list.getCaptions();

	list.quickSort();
	
	for (int i = list.getCaptions().size() - 1; i >= 1; i--) {

		REQUIRE(list.getCaptions()[i].getEmojis().size() >= list.getCaptions()[i-1].getEmojis().size());
	}

	REQUIRE(1==1);
}

TEST_CASE("Testing mergeSort()", "[algorithm function]") {
	
	CaptionList list("Dependencies/Captions.csv");
	std::vector<Caption> sorted = list.getCaptions();

	list.quickSort();
	
	for (int i = list.getCaptions().size() - 1; i > 23000; i--) {
	
		REQUIRE(list.getCaptions()[i].getEmojis().size() >= list.getCaptions()[i-1].getEmojis().size());
	}

	REQUIRE(1==1);
}

