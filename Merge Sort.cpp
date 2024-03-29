// Merge Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include <array>
//#include "mergesort.h"
using namespace std;

// Global types

// Global consts
const int NUM_INTS(1000);

// Global function declarations
void displayArray(string name, int array[], int numElements, bool isSorted = false);
void mergeSort(int nums[], int const numElements, int const start);
void doMerge(int nums[], int const numElements, int const start);

int main()
{
	//  Initialize variables
	static int array[NUM_INTS];
	srand(static_cast<unsigned int> (time(0)));

	cout << "Sorting int array of " << NUM_INTS << " elements." << endl;

	// Load random numbers into the array
	for (int i = 0; i < NUM_INTS; i++)
	{
		array[i] = rand();
	}
	displayArray("Before: ", array, NUM_INTS); // comment out for large data sets

	// start timing here
	time_t startTime = clock();
	mergeSort(array, NUM_INTS, 0);
	time_t endTime = clock();
	// end timing here

	displayArray("After : ", array, NUM_INTS, true);  // comment out for large data sets - 3rd parameter confirms list is sorted

	// Display the total time taken
	cout << "Sort took " << endTime - startTime << " ticks" << endl;

	return 0;
}

// Functions

// Function to display the contents of an array & optionally confirm list is sorted
void displayArray(string name, int array[], int numElements, bool isSorted)
{
	cout << name;
	for (int i = 0; i < numElements; i++)
	{
		if (isSorted && i > 0)
		{
			assert(array[i - 1] <= array[i]);
		}
		cout << array[i];
		if (i < numElements - 1)
		{
			cout << ", ";
		}
	}
	cout << endl;
}


void mergeSort(static int nums[], int const numElements, int const start) {
	if(numElements>1){//if there are more than 2 elements in the array
		int half = numElements / 2;//gets half
		mergeSort(nums, half, start);//sorts first half
		mergeSort(nums, (numElements - half), (start + half));//sorts second half
		doMerge(nums, numElements, start);
	}
}


// Fucntion to combine to the two sorted halves into a sorted list
void doMerge(static int nums[],  int const numElements, int const start) {
	//travLeft is start of left array, travRight is start of right array, traverse is for temp array
	int travLeft = start, travRight = start+ (numElements/2), traverse = start;
	//temporary array to hold sorted values from sort
	static int temp[NUM_INTS];
	//sets temp equal to original array
	for (int i = 0; i < NUM_INTS; i++) {
		temp[i] = nums[i];
	}
	//while the left pointer is inbound of left array and the right pointer is inbouds of the right and inbouds of whole array
	while ((travLeft < ((numElements / 2)+1) || travRight <((numElements + start)+1))&& traverse <(numElements+start)) {
		if (travLeft > ((numElements / 2)+start)-1) {//if left is out of bounds
			temp[traverse] = nums[travRight]; traverse++; travRight++;
		}
		else if (travRight > (numElements+start)-1) {//if right is out of bounds
			temp[traverse] = nums[travLeft]; traverse++; travLeft++;

		}
		else if (nums[travLeft] < nums[travRight]) {//if left is smaller than right
			temp[traverse] = nums[travLeft]; traverse++; travLeft++;
		}
		else {//if right is smaller than left
			temp[traverse] = nums[travRight]; traverse++; travRight++;
		}
	}
	for (int i = 0; i < NUM_INTS; i++) {
		nums[i] = temp[i];
	}
	
}