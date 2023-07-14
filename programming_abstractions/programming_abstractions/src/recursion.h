#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <random>

namespace recursion
{

	inline int power_recursive(int x, int n)
	{
		if (n <= 0) return 1;
		return x * power_recursive(x, n - 1);
	}

	inline int factorial_non_recursive(int n)
	{
		int total = 1;

		for (int i = 1; i <= n; i++)
		{
			total *= i;
		}

		return total;
	}

	inline int factorial_recursive(int n)
	{
		if (n == 0 || n == 1) return 1;
		return n * factorial_recursive(n - 1);
	}

	inline bool is_palindrome_recursive(const std::string& str)
	{
		//Base case
		if (str.empty() || str.length() == 1) return true;
		//Recursive
		char first = str[0];
		char last = str[str.length() - 1];
		std::string middle = str.substr(1, str.length() - 2);

		return (first == last && is_palindrome_recursive(middle));

	}

	inline bool isPalindromeRecursive2(std::string s) {
		if (s.length() <= 1) {
			// base case: 0- and 1-length strings are always palindromes
			return true;
		}
		else if (s[0] != s[s.length() - 1]) {
			// base case: first and last characters differ
			return false;
		}
		else {
			// recursive case
			std::string middle = s.substr(1, s.length() - 2);
			return isPalindromeRecursive2(middle);
		}
	}

	inline void print_all_binary_helper(int digits, const std::string& str)
	{
		if (digits == 0)
			std::cout << str << std::endl;
		else
		{
			print_all_binary_helper(digits - 1, str + "0");
			print_all_binary_helper(digits - 1, str + "1");
		}
	}

	//Print all possible binary numbers with n-digits
	inline void print_all_binary(int digits)
	{
		print_all_binary_helper(digits, "");
	}

	//Prints all possible combinations for n-dice to roll so their sum == target
	inline void diceSumHelper(int dice, int target, std::vector<int>& chosen)
	{
		if (dice == 0)
		{
			if (target == 0) { //not ideal performance wise, still exhaustive search, just not printed

				for (auto choice : chosen)
				{
					std::cout << choice << " ";
				}
				std::cout << std::endl;
			}
		}
		else if (target >= dice * 1 && target <= dice * 6)
		{
			//Handle 1 die (1-6 decisions)
			for (int i = 1; i <= 6; i++)
			{
				//choose i as possible choice (store it in vector)
				chosen.push_back(i);
				//explore remaining decisions

				diceSumHelper(dice - 1, target - i, chosen);
				//un-choose i
				chosen.pop_back();
			}
		}
	}

	inline void diceSum(int dice, int target)
	{
		std::vector<int> v;
		diceSumHelper(dice, target, v);
	}

	//Print all permutations for given vector

	inline void permuteHelper(std::vector<std::string>& v, std::vector<std::string>& chosen)
	{
		if (v.empty())
		{
			//base case
			//Every decision has been made for 1 choice - print it
			for (auto element : chosen)
			{
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}
		else
		{


			//for each choice
			for (int i = 0; i < v.size(); i++)
			{
				//choose
				std::string s = v[i];
				chosen.push_back(s);
				v.erase(v.begin() + i); //remove chosen from possible decision for recursive call

				//explore
				permuteHelper(v, chosen);

				//un-choose
				chosen.pop_back();
				v.insert(v.begin() + i, s);

			}
		}
	}

	inline void permute(std::vector<std::string>& v)
	{
		std::vector<std::string> chosen;
		permuteHelper(v, chosen);
	}

	inline void permute_string(std::string soFar, std::string rest) {
		if (rest.empty()) {
			std::cout << soFar << std::endl;
			return;
		}

		for (int i = 0; i < (int)rest.length(); i++) {
			// remove character we are on from rest
			const std::string remaining = rest.substr(0, i) + rest.substr(i + 1);
			permute_string(soFar + rest[i], remaining);
		}
	}


	inline int sumOfSquare(int  n)
	{
		if (n == 0) return 0;
		return n * n + sumOfSquare(n - 1);
	}

	//Print sublists of list
	inline void sublistsHelper(std::vector<std::string>& v, std::vector <std::string>& chosen)
	{
		if (v.empty())
		{
			for (auto& i : chosen)
			{
				std::cout << i << " ";
			}
			std::cout << std::endl;
		}
		else
		{
			//Handle 1 string in list
			std::string s = v[0];
			v.erase(v.begin());
			//for each possible choice

			//choose and explore without s, ... try with s
			sublistsHelper(v, chosen);

			//choose and explore with s
			chosen.push_back(s);

			sublistsHelper(v, chosen);

			//un-choose
			v.insert(v.begin(), s);
			chosen.pop_back();
		}
	}
	inline void sublists(std::vector<std::string>& v)
	{
		std::vector<std::string> chosen;
		sublistsHelper(v, chosen);
	}

	inline std::string randomShuffle(std::string deck)
	{
		if (deck.empty())
			return deck;

		int i = rand() % deck.length();

		return deck[i] + randomShuffle(deck.substr(0, i) + deck.substr(i + 1));
	}


}