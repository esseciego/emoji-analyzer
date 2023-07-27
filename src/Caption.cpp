#include "Caption.h"


void mergeSort(std::vector<Caption> captions, int left, int right) {
	
	if (left < right) {
		
		int mid = left + (right - left) / 2;
		mergeSort(captions, left, mid);
		mergeSort(captions, mid + 1, right);

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

void quickSort(std::vector<Caption> captions, int low, int high) {
	
	if (low < high) {
		int pivot = partition(captions, low, high);
		quickSort(captions, low, pivot - 1);
		quickSort(captions, pivot + 1, high);
	}
}

int partition(std::vector<Caption> captions, int low, int high
