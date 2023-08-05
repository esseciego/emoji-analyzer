// Project:		emoji-analyzer
// File:		src/CaptionList.h
// Team:		Esse Ciego
//			Justin Galin
//			Daniel Pernar
// Description:		This file provides the CaptionList class prototype as well as 
//			function prototypes used to sort the Caption container based
//			on the size of the Caption object's emojis vector.
// Last Updated On:	5 August 2023

#pragma once
#include <vector>
#include "Caption.h"

class CaptionList {
	
	private:
	
	// Container to store Caption objects
	std::vector<Caption> captions;

	// Stores the time it takes for mergeSort() or 
	// quickSort() to finish sorting the captions
	// vector. Value is updated after every function
	// call.
	float time = 0.0f;


	public:

	// Parametrized CaptionList constructor
	CaptionList(std::string filename);

	// Sort the captions vector using MergeSort algorithm
	void mergeSort();

	// Sort the captions vector using QuickSort algorithm
	void quickSort();
	
	// Return the captions vector
	std::vector<Caption> getCaptions();

    // Return captions size
    int getSize();

	// Return the time it took for the last used sorting algorithm
	// to run.
	float getTime();
};

// Merge Sort functionality used to sort captions vector
void mergeSortAlgorithm(std::vector<Caption>& captions, int left, int right);

// Used to merge two Caption vectors in the mergeSortAlgorithm function
void merge(std::vector<Caption>& captions, int left, int mid, int right);

// Quick Sort functionality used to sort captions vector
void quickSortAlgorithm(std::vector<Caption>& captions, int low, int high);

// Used to create the partition point in the quickSortAlgorithm funciton
int partition(std::vector<Caption>& captions, int low, int high);

// Swaps the position of Caption objects a and b in a provided Caption
// vector, used in quickSortAlgorithm function
void swap(std::vector<Caption>& captions, int a, int b);
