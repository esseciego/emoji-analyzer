// Project:		emoji-analyzer
// File:		src/CaptionList.cpp
// Team:		Esse Ciego
//			Justin Galin
//			Daniel Pernar
// Description:		Provides definitions for the CaptionList member functions 
//			and non-member, helper functions. Prototypes can be 
//			found in CaptionList.h.
// Last Updated On:	5 August 2023

#include "CaptionList.h"
#include "Caption.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "../../../../Downloads/daniel/src/Timer.h"
#include <utility>


/**************************************************************************************************/
/************************ CaptionList Member Functions *****************************/

// Parametrized CaptionList constructor
CaptionList::CaptionList(std::string filename) {
	
	// Open CSV file based on given filename
	std::fstream file(filename, std::fstream::in);

	// Check that the file was successfully opened
	if (!file.is_open()) {

		std::cout << "Captions file could not be opened." << std::endl;
	}
	
	int postIndx = 0, userIndx= 1, emojisIndx = 5;

	std::vector<std::string> row;
	std::string line, cell, temp;
	
	// Get rid of the column titles
	std::getline(file, line);

	while (std::getline(file, line)) {
		
		row.clear();
		std::stringstream ss(line);
		
		// Load cells into a temporary vector
		while (std::getline(ss, cell, ',')) {

			row.push_back(cell);
		}
		
		// Get emoji data
		std::vector<std::string> emojis;
		for (int i = emojisIndx; i < row.size(); i++) {

			// Remove blank cells
			if (row.at(i) != "") {

				emojis.push_back(row.at(i));
			}
		}

		// Create new caption
		Caption newCaption(emojis, row.at(userIndx), row.at(postIndx));

		// Add newCaption to captions vector
		captions.push_back(newCaption);
	}
	
	// Close CSV file
	file.close();
}

// Sort the captions vector using MergeSort algorithm
void CaptionList::mergeSort() {
	
	Timer timer;
	timer.start();
	mergeSortAlgorithm(captions, 0, captions.size()-1);
	time = timer.stop();
}

// Sort the captions vector using QuickSort algorithm
void CaptionList::quickSort() {
	
	Timer timer;
	timer.start();
	int n = captions.size() / captions[0].getEmojis().size();
	quickSortAlgorithm(captions, 0, n - 1); //captions.size()/2);
	time = timer.stop();
}

// Return the captions vector
std::vector<Caption> CaptionList::getCaptions() {
	return captions;
}

int CaptionList::getSize() {
    return captions.size();
}

// Return the time it took for the last used sorting algorithm
// to run.
float CaptionList::getTime() {
	return time;
}



/**************************************************************************************************/
/************************ CaptionList Helper Functions *****************************/
// Merge Sort functionality used to sort captions vector
// Based on code provided in Data Structures Lecture 6 - Sorting
void mergeSortAlgorithm(std::vector<Caption>& captions, int left, int right) {

	if (left < right) {
		
		int mid = left + (right - left) / 2;
		mergeSortAlgorithm(captions, left, mid);
		mergeSortAlgorithm(captions, mid + 1, right);

		merge(captions, left, mid, right);
	}


}

// Used to merge two Caption vectors in the mergeSortAlgorithm function
// Based on code provided in Data Structures Lecture 6 - Sorting
void merge(std::vector<Caption>& captions, int left, int mid, int right) {

	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<Caption> X, Y;

	for (int i = 0; i < n1; i++) {
		X.push_back(captions[left + i]);
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

			captions[k] = X[i];
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

// Quick Sort functionality used to sort captions vector
// Based on code provided in Data Structures Lecture 6 - Sorting
void quickSortAlgorithm(std::vector<Caption>& captions, int low, int high) {
	
	if (low < high) {
		int pivot = partition(captions, low, high);
		quickSortAlgorithm(captions, low, pivot - 1);
		quickSortAlgorithm(captions, pivot + 1, high);
	}
}

// Used to create the partition point in the quickSortAlgorithm funciton
// Based on code provided in Data Structures Lecture 6 - Sorting
int partition(std::vector<Caption>& captions, int low, int high) {

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
			swap(captions, up, down);
		}

	}
	swap(captions, low, down);
	return down;
}

// Swaps the position of Caption objects a and b in a provided Caption
// vector, used in quickSortAlgorithm function
void swap(std::vector<Caption>& captions, int a, int b) {

	Caption temp(captions[a].getEmojis(), captions[a].getUsername(), captions[a].getPost());

	captions[a].setEmojis(captions[b].getEmojis());
	captions[a].setUsername(captions[b].getUsername());
	captions[a].setPost(captions[b].getPost());
	captions[b].setEmojis(temp.getEmojis());
	captions[b].setUsername(temp.getUsername());
	captions[b].setPost(temp.getPost());
}
