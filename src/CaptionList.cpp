#include "CaptionList.h"
#include "Caption.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "Timer.h"



/**************************************************************************************************/
/************************ CaptionList Member Functions *****************************/

// Parametrized CaptionList constructor
CaptionList::CaptionList(std::string filename) {
	
	std::fstream file(filename, std::fstream::in);
	std::cout << "Filename: " << filename << std::endl;

	if (!file.is_open()) {
		std::cout << "Captions file could not be opened." << std::endl;
	}
	
	int postIndx = 0, userIndx= 1, emojisIndx = 5;

	std::vector<std::string> row;
	std::string line, cell, temp;

	std::getline(file, line);
	std::cout << "The columns are: " << line << std::endl;

	while (file >> temp) {
		
		row.clear();
		std::getline(file, line);
		std::cout << line << std::endl;			// FOR TESTING ONLY
		std::stringstream ss(line);

		while (std::getline(ss, cell, ',')) {
			row.push_back(cell);
		}
		
		// Get emoji data
		std::vector<std::string> emojis;
		for (int i = emojisIndx; i < row.size(); i++) {
			emojis.push_back(row.at(i));
		}

		// Create new caption
		std::cout << "New Caption" << std::endl;
		std::cout << "userIndx: " << row.at(userIndx) << std::endl;	// FOR TESTING ONLY
		std::cout << "postIndx: " << row.at(postIndx) << std::endl;	// FOR TESTING ONLY
		Caption newCaption(emojis, row.at(userIndx), row.at(postIndx));
		std::cout << "Caption made" << std::endl;
		captions.push_back(newCaption);

		std::cout << "Caption user: " << newCaption.getUsername() << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;
	}
	
	file.close();
}

// Sort the captions vector using MergeSort algorithm
void CaptionList::mergeSort() {
	
	Timer timer;
	timer.start();
	mergeSortAlgorithm(captions, 0, 0);
	time = timer.stop();
}

// Sort the captions vector using QuickSort algorithm
void CaptionList::quickSort() {
	
	Timer timer;
	timer.start();
	quickSortAlgorithm(captions, 0, 0);
	time = timer.stop();
}

// Return the captions vector
std::vector<Caption> CaptionList::getCaptions() {
	return captions;
}

// Return the time it took for the last used sorting algorithm
// to run.
float CaptionList::getTime() {
	return time;
}



/**************************************************************************************************/
/************************ CaptionList Helper Functions *****************************/
void mergeSortAlgorithm(std::vector<Caption> captions, int left, int right) {
	
	if (left < right) {
		
		int mid = left + (right - left) / 2;
		mergeSortAlgorithm(captions, left, mid);
		mergeSortAlgorithm(captions, mid + 1, right);

		merge(captions, left, mid, right);
	}


}

void merge(std::vector<Caption> captions, int left, int mid, int right) {

	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<Caption> X, Y;

	for (int i = 0; i < n1; i++) {
		X.push_back(captions[left+1]);
	}
	for (int j = 0; j < n2; j++) {
		Y.push_back(captions[mid + 1 + j]);
	}

	int i, j, k;
	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2) {

		if (X[i].getNumEmojis() <= Y[j].getNumEmojis()) {

			captions[k] = X[k];
			i++;
		}
		else {
			captions[k] = Y[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		
		captions[k] = X[i];
		i++;
		k++;
	}

	while (j < n2) {
		
		captions[k] = Y[j];
		j++;
		k++;
	}
}

void quickSortAlgorithm(std::vector<Caption> captions, int low, int high) {
	
	if (low < high) {
		int pivot = partition(captions, low, high);
		quickSortAlgorithm(captions, low, pivot - 1);
		quickSortAlgorithm(captions, pivot + 1, high);
	}
}

int partition(std::vector<Caption> captions, int low, int high) {

	Caption pivot = captions[low];
	int up = low, down = high;

	while (up < down) {
		
		for (int j = up; j < high; j++) {
			
			if (captions[up].getNumEmojis() > pivot.getNumEmojis()) {
				break;
			}
			up++;
		}
		for (int j = high; j > low; j--) {

			if (captions[down].getNumEmojis() < pivot.getNumEmojis()) {
				break;
			}
			down--;
		}
		if (up < down) {
			swap(&captions[up], &captions[down]);
		}

	}
	swap(&captions[up], &captions[down]);
	return down;
}


void swap(Caption* a, Caption* b) {
	
	Caption temp(a->getEmojis(), a->getUsername(), a->getPost());

	a->setEmojis(b->getEmojis());
	a->setUsername(b->getUsername());
	a->setPost(b->getPost());
	
	b->setEmojis(temp.getEmojis());
	b->setUsername(temp.getUsername());
	b->setPost(temp.getPost());
}
