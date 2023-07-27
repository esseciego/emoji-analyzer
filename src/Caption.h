#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

class Caption {
	
	private:

	std::vector<std::string> emojis;
	std::string username;
	std::string post;


	public:

	Caption();
	std::vector<std::string> getEmojis() { return emojis; }
	int getNumEmojis() { return emojis.size(); }
	std::string getUsername() { return username; }
	std::string getPost() { return post; }

	
	
};


std::vector<Caption> LoadCaptions(std::fstream& file);
void mergeSort(std::vector<Caption> captions, int left, int right);
void merge(std::vector<Caption> captions, int left, int mid, int right);
void quickSort(std::vector<Caption> captions, int low, int high);
