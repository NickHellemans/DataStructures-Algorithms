#pragma once
#include <vector>

class Search
{
public:

	static bool linearSearch(std::vector<int>& vec, int numToFind)
	{
		for(int i = 0; i < vec.size(); i++)
		{
			if(vec[i] == numToFind)
			{
				return true;
			}
		}

		return false;
	}

	//Only usable in sorted list
	static bool binarySearchVector(std::vector<int>& vec, int numToFind) {
		int low = 0;
		int high = vec.size() - 1;

		while (low <= high) {
			const int mid = low + (high - low) / 2; // to avoid overflow
			if (vec[mid] > numToFind) {
				high = mid - 1;
			}
			else if (vec[mid] < numToFind) {
				low = mid + 1;
			}
			else {
				return true;
			}
		}
		return false;
	}

	static int twoCrystalBalls(std::vector<bool>& vec)
	{
		/*
		 * Given an array of false and trues that denote from which point a balls breaks when dropping it from that floor
		 * [f, f, f, t, t, t] => breaks on 4th level (index 3)
		 * How to find level on which it breaks given 2 balls
		 * - Just linearly go through every level until it breaks => O(N)
		 * - Jump by x amount until breaks => go back to last point and linearly search O(N)
		 * - Jump by sqrt(n) each time => sqrt(n) jumps + sqrt(n) search ==> O(sqrt(n))
		 */

		const int jumpAmount = (int) sqrt(vec.size());
		int i = jumpAmount;
		for (; i < vec.size(); i += jumpAmount)
		{
			if(vec[i] == true)
			{
				break;
			}
		}

		i -= jumpAmount;
		for (int j = 0; j < jumpAmount; j++, i++)
		{
			if (vec[i] == true)
			{
				return i;
			}
		}
		return -1;
	}
};
