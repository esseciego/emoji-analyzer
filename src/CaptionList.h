#pragma once
#include <vector>
#include "Caption.h"

class CaptionList {
	
	private:
	
	std::vector<Caption> captions;
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

	// Return the time it took for the last used sorting algorithm
	// to run.
	float getTime();
};

void mergeSortAlgorithm(std::vector<Caption> captions, int left, int right);
void merge(std::vector<Caption> captions, int left, int mid, int right);
void quickSortAlgorithm(std::vector<Caption> captions, int low, int high);
int partition(std::vector<Caption> captions, int low, int high);
void swap(std::vector<Caption> &captions, int a, int b);
