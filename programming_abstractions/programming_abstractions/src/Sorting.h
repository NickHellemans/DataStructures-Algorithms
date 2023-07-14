#pragma once
#include <vector>

class Sorting
{
public:
	static void bubbleSort(std::vector<int>& v)
	{
		for (int i = 0; i < v.size(); i++)
		{
			//Up to size - 1 (do not want to buffer overflow) - i (already sorted elements)
			for (int j = 0; j < v.size() - 1 - i; j++)
			{
				if (v[j] > v[j + 1])
				{
					swap(v, j, j + 1);
				}
			}
		}
	}
	static void selectionSort(std::vector<int>& v)
	{
		for (int i = 0; i < (int)v.size(); i++)
		{
			int smallestIndex = i;
			for (int j = i; j < (int)v.size(); i++)
			{
				if (v[j] < v[i])
				{
					smallestIndex = j;
				}
			}
			swap(v, i, smallestIndex);
		}
	}

	static void swap(std::vector<int>& v, int index, int smallestIndex)
	{
		int tmp = v[index];
		v[index] = v[smallestIndex];
		v[smallestIndex] = tmp;
	}

	static void insertionSort(std::vector<int>& v)
	{
		for (int i = 1; i < (int)v.size(); i++)
		{
			int tmp = v[i];
			int j = i;

			while (j >= 1 && v[j - 1] > tmp)
			{
				v[j] = v[j - 1];
				j--;
			}
			v[j] = tmp;
		}
	}

	static void mergeSort(std::vector<int>& v)
	{
		if (v.size() <= 1)
		{
			return;
		}

		//Divide
		std::vector<int> left;
		std::vector<int> right;
		for (int i = 0; i < v.size(); i++) {
			if (i < v.size() / 2) {
				left.emplace_back(v[i]);
			}
			else {
				right.emplace_back(v[i]);
			}
		}

		//Sort
		mergeSort(left);
		mergeSort(right);

		//Merge
		int index1 = 0;
		int index2 = 0;

		for (int i = 0; i < v.size(); i++)
		{
			if (index2 >= right.size() || (index1 < v.size() && left[index1] < right[index2]))
			{
				v[i] = left[index1];
				index1++;
			}
			else
			{
				v[i] = right[index2];
				index2++;
			}
		}
	}

	// Merges the left/right elements into a sorted result.
	// Precondition: left/right are sorted, and vec is empty
	static void merge(std::vector<int>& vec, std::vector<int>& v1, std::vector<int>& v2) {
		int n1 = v1.size();
		int n2 = v2.size();
		int p1 = 0;
		int p2 = 0;
		while (p1 < n1 && p2 < n2) {
			if (v1[p1] <= v2[p2]) {
				vec.emplace_back(v1[p1++]);
			}
			else {
				vec.emplace_back(v2[p2++]);
			}
		}
		while (p1 < n1) {
			vec.emplace_back(v1[p1++]);
		}
		while (p2 < n2) {
			vec.emplace_back(v2[p2++]);
		}
	}


	static void mergeSort2(std::vector<int>& vec) {
		int n = vec.size();
		if (n <= 1) return;
		std::vector<int> v1;
		std::vector<int> v2;
		for (int i = 0; i < n; i++) {
			if (i < n / 2) {
				v1.emplace_back(vec[i]);
			}
			else {
				v2.emplace_back(vec[i]);
			}
		}
		mergeSort2(v1);
		mergeSort2(v2);
		vec.clear();
		merge(vec, v1, v2);
	}

	static std::vector<int> naiveQuickSort(std::vector<int> v) { // not passed by reference!
		// base case: list of 0 or 1
		if (v.size() < 2) {
			return v;
		}
		int pivot = v[0];    // choose pivot to be left-most element

		// create two new vectors to partition into
		std::vector<int> left, right;

		// put all elements <= pivot into left, and all elements > pivot into right
		for (int i = 1; i < v.size(); i++) {
			if (v[i] <= pivot) {
				left.emplace_back(v[i]);
			}
			else {
				right.emplace_back(v[i]);
			}
		}
		left = naiveQuickSort(left); // recursively handle the left
		right = naiveQuickSort(right); // recursively handle the right

		left.emplace_back(pivot); // put the pivot at the end of the left

		return left; //+ right; // return the combination of left and right
	}


	static void quicksort(std::vector<int>& vec) {
		quicksort(vec, 0, vec.size() - 1);
	}

	// helper function to pass in start and finish
	static void quicksort(std::vector<int>& vec, int start, int finish) {
		if (start >= finish) return;
		int boundary = partition(vec, start, finish);
		quicksort(vec, start, boundary - 1);
		quicksort(vec, boundary + 1, finish);
	}

	static int partition(std::vector<int>& vec, int start, int finish) {
		int pivot = vec[start];
		int lh = start + 1;
		int rh = finish;

		while (true) {
			while (lh < rh && vec[rh] >= pivot) rh--;
			while (lh < rh && vec[lh] < pivot) lh++;
			if (lh == rh) break;

			// swap
			int tmp = vec[lh];
			vec[lh] = vec[rh];
			vec[rh] = tmp;
		}

		if (vec[lh] >= pivot) return start;
		vec[start] = vec[lh];
		vec[lh] = pivot;
		return lh;
	}

	int partition2(std::vector<int>& vec, int start, int finish)
	{
		const int pivot = vec[finish];
		int idx = start - 1;
		for (int i = start; i < finish; i++)
		{
			if(vec[i] <= pivot)
			{
				idx++;
				const int tmp = vec[i];
				vec[i] = vec[idx];
				vec[idx] = tmp;
			}
		}

		idx++;
		vec[finish] = vec[idx];
		vec[idx] = pivot;

		return idx;
	}



};

