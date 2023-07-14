#include <iostream>
#include <vector>
#include "Examples.h"


int main()
{
	constexpr int exampleSize = 10;
	const std::string examples[exampleSize] = {"Stack", "Queue", "Set", "Linked List", "Heap", "Sorting", "LRU", "Recursion", "Maze", "Graph Path finding"};
	int choice = 1;
	while(choice != 0)
	{
		std::cout << "CHOOSE AN EXAMPLE (0 to stop): " << std::endl;
		for (int i = 0; i < exampleSize; i++)
		{
			std::cout << i + 1 << ". " << examples[i] << std::endl;
		}
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			Examples::stack_example();
			break;
		case 2:
			Examples::queue_example();
			break;
		case 3:
			Examples::set_example();
			break;

		case 4:
			Examples::linked_list_example();
			break;
		case 5:
			Examples::heap_test();
			break;
		case 6:
			Examples::sort_example();
			break;
		case 7:
			Examples::lru_example();
			break;
		case 8:
			Examples::recursion_example();
			break;
		case 9:
			Examples::maze_example();
			break;
		case 10:
			Examples::graph_example();
			break;
		default:
			std::cout << "Not a valid option" << std::endl;
			break;
		}
	}

	return 0;
}




