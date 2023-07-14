#pragma once
#include <iostream>
#include "ArrayStack.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "RingBufferQueue.h"
#include "SetBST.h"
#include "HashSet.h"
#include "LinkedList.h"
#include "MinHeap.h"
#include "Sorting.h"
#include "LRU.h"
#include "recursion.h"
#include "MazeSolver.h"
#include "Graphs.h"

namespace Examples
{
	inline void stack_example()
	{
		std::cout << "Testing the stack array and linked list!" << std::endl;
		std::cout << "ArrayStack" << std::endl;

		ArrayStack arrayStack;
		arrayStack.push(5);
		arrayStack.push(8);
		arrayStack.push(22);
		arrayStack.push(56);
		arrayStack.push(15);

		std::cout << "Stack = ";
		std::cout << arrayStack << std::endl;

		std::cout << "Peek" << std::endl;
		std::cout << arrayStack.peek() << std::endl;

		std::cout << "Pop 2 elements" << std::endl;
		std::cout << "Pop: " << arrayStack.pop() << std::endl;
		std::cout << "Pop: " << arrayStack.pop() << std::endl;
		std::cout << "Stack = ";
		std::cout << arrayStack << std::endl;
		std::cout << "Size: " << arrayStack.getSize() << std::endl;

		std::cout << "Test resize: adding > 10 elements" << std::endl;
		for(int i = 0; i < 10; i++)
		{
			arrayStack.push(i);
		}

		std::cout << "Stack = ";
		std::cout << arrayStack << std::endl;

		std::cout << std::endl;
		std::cout << "LinkedStack" << std::endl;


		LinkedStack linkedStack;

		linkedStack.push(5);
		linkedStack.push(8);
		linkedStack.push(22);
		linkedStack.push(56);
		linkedStack.push(15);

		std::cout << "Stack = ";
		std::cout << linkedStack << std::endl;

		std::cout << "Peek" << std::endl;
		std::cout << linkedStack.peek() << std::endl;

		std::cout << "Pop 2 elements and add 1" << std::endl;
		std::cout << "Pop: " << linkedStack.pop() << std::endl;
		std::cout << "Pop: " << linkedStack.pop() << std::endl;
		linkedStack.push(100);
		std::cout << "Stack = ";
		std::cout << linkedStack << std::endl;
		std::cout << "Size: " << linkedStack.getSize() << std::endl;

	}

	inline void queue_example()
	{
		std::cout << "Ringbuffer and Linked Queue example" << std::endl;
		std::cout << "Ringbuffer" << std::endl;
		RingBufferQueue rbQueue;
		std::cout << "Adding 11 elements" << std::endl;

		for(int i = 0; i < 11; i++)
		{
			rbQueue.enqueue(i);
		}

		std::cout << "Queue = ";
		std::cout << rbQueue << std::endl;

		std::cout << "Peek: " << rbQueue.peek() << std::endl;
		std::cout << "Dequeue 5 elements: " << std::endl;
		for(int i = 0; i < 5; i++)
		{
			std::cout << "Dequeue: " << rbQueue.dequeue() << std::endl;
		}

		std::cout << "Queue 11 elements: " << std::endl;
		for (int i = 0; i < 5; i++)
		{
			rbQueue.enqueue(i);
		}
		std::cout << "Queue = ";
		std::cout << rbQueue << std::endl;

		std::cout << std::endl;
		std::cout << "Linked Queue" << std::endl;
		LinkedQueue linkedQueue;
		std::cout << "Adding 11 elements" << std::endl;

		for (int i = 0; i < 11; i++)
		{
			linkedQueue.enqueue(i);
		}

		std::cout << "Queue = ";
		std::cout << linkedQueue << std::endl;

		std::cout << "Peek: " << linkedQueue.peek() << std::endl;
		std::cout << "Dequeue 5 elements: " << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Dequeue: " << linkedQueue.dequeue() << std::endl;
		}

		std::cout << "Queue 11 elements: " << std::endl;
		for (int i = 0; i < 5; i++)
		{
			linkedQueue.enqueue(i);
		}
		std::cout << "Queue = ";
		std::cout << linkedQueue << std::endl;
	}

	inline void set_example()
	{
		std::cout << "BST Set and HashSet example" << std::endl;
		std::cout << "BST Set" << std::endl;
		std::cout << "Add 11 elements" << std::endl;

		SetBST setBST;

		setBST.add(50);
		setBST.add(120);
		setBST.add(11);
		setBST.add(9);
		setBST.add(44);
		setBST.add(101);
		setBST.add(144);
		setBST.add(88);
		setBST.add(35);
		setBST.add(66);
		setBST.add(14);

		std::cout << "Set traversal: " << setBST << std::endl;

		std::cout << "Max: " << setBST.findMax() << std::endl;
		std::cout << "Min: " << setBST.findMin() << std::endl;
		std::cout << "Remove 9 and 50 " << std::endl;
		setBST.remove(9);
		setBST.remove(50);
		std::cout << "Set traversal: " << setBST << std::endl;
		std::cout << "Set size after remove " << setBST.getSize() << std::endl;
		std::cout << "Set contains 120? " << setBST.contains(120) << std::endl;
		std::cout << "Set contains 130? " << setBST.contains(130) << std::endl;

		std::cout << std::endl;
		std::cout << "Hash Set" << std::endl;
		std::cout << "Add 11 elements" << std::endl;

		HashSet hashSet;

		hashSet.add(50);
		hashSet.add(120);
		hashSet.add(11);
		hashSet.add(9);
		hashSet.add(44);
		hashSet.add(101);
		hashSet.add(144);
		hashSet.add(88);
		hashSet.add(35);
		hashSet.add(66);
		hashSet.add(14);

		std::cout << "Set: " << hashSet << std::endl;
		std::cout << "Set contains 9? " << hashSet.contains(9) << std::endl;
		std::cout << "Set contains 50? " << hashSet.contains(50) << std::endl;

		std::cout << "Remove 9, 50 and 1000 (not in set) " << std::endl;
		hashSet.remove(9);
		hashSet.remove(50);
		hashSet.remove(1000);
		std::cout << "Set: " << hashSet << std::endl;
		std::cout << "Set size after remove " << hashSet.size() << std::endl;
		std::cout << "Adding 17 elements to test rehash " << std::endl;
		for (int i = 0; i < 17; i++)
		{
			hashSet.add(i);
		}

		std::cout << "Set size after remove " << hashSet.size() << std::endl;
		std::cout << "Set: " << hashSet << std::endl;
	}
	inline void linked_list_example()
	{
		std::cout << "Linked List example" << std::endl;
		std::cout << "Add 11 elements" << std::endl;

		LinkedList linkedList;

		for (int i = 0; i < 11; i++)
		{
			linkedList.add(i);
		}
		std::cout << "List = " << linkedList << std::endl;
		std::cout << "List sorted? " << linkedList.isSorted() << std::endl;
		linkedList.addFront(100);
		std::cout << "Add 100 to front: " << linkedList << std::endl;
		std::cout << "List sorted? " << linkedList.isSorted() << std::endl;
		std::cout << "Get 3rd item = " << linkedList.get(3) << std::endl;
		linkedList.insert(3, 200);
		std::cout << "Insert 200 at index 3 = " << linkedList << std::endl;
		linkedList.removeFront();
		std::cout << "Remove front = " << linkedList << std::endl;
		linkedList.removeBack();
		std::cout << "Remove back = " << linkedList << std::endl;
		linkedList.remove(3);
		std::cout << "Remove index 3 = " << linkedList << std::endl;
	}
	inline void heap_test()
	{
		std::cout << "Heap example" << std::endl;
		std::cout << "Add 10 elements" << std::endl;

		MinHeap heap;

		heap.insert(5);
		heap.insert(105);
		heap.insert(500);
		heap.insert(1);
		heap.insert(34);
		heap.insert(57);
		heap.insert(83);
		heap.insert(77);
		heap.insert(102);
		heap.insert(203);

		std::cout << "Heap: " << heap << std::endl;
		std::cout << "Pop element: " << heap.pop() << std::endl;
		std::cout << "Pop element: " << heap.pop() << std::endl;
		std::cout << "Heap: " << heap << std::endl;
		heap.insert(0);
		heap.insert(1000);
		heap.insert(2000);
		std::cout << "Insert 0, 1000, 2000: " << heap << std::endl;
		std::cout << "Heap: " << heap << std::endl;

		std::cout << "Pop until empty: " << std::endl;
		for(int i = 0; i < 11; i++)
		{
			std::cout << "Pop element: " << heap.pop() << std::endl;
		}
	}
	inline void sort_example()
	{
		std::cout << "Sorting example" << std::endl;

		std::vector<int> list{100, 55, 99, 1000, 104, 55, 7, 1, 88, 92, 12, 17, 8, 0, 400, 323, 230, 570};

		for(int n : list)
		{
			std::cout << n << " ";
		}
		std::cout << std::endl;

		std::cout << "Bubble sort" << std::endl;
		Sorting::bubbleSort(list);
		for (int n : list)
		{
			std::cout << n << " ";
		}
		std::cout << std::endl;

		std::vector<int> list1{ 100, 55, 99, 1000, 104, 55, 7, 1, 88, 92, 12, 17, 8, 0, 400, 323, 230, 570 };
		std::cout << "Insertion sort" << std::endl;
		Sorting::insertionSort(list1);
		for (int n : list1)
		{
			std::cout << n << " ";
		}
		std::cout << std::endl;

		std::vector<int> list2{ 100, 55, 99, 1000, 104, 55, 7, 1, 88, 92, 12, 17, 8, 0, 400, 323, 230, 570 };
		std::cout << "Merge sort" << std::endl;
		Sorting::mergeSort2(list2);
		for (int n : list2)
		{
			std::cout << n << " ";
		}
		std::cout << std::endl;

		std::vector<int> list3{ 100, 55, 99, 1000, 104, 55, 7, 1, 88, 92, 12, 17, 8, 0, 400, 323, 230, 570 };
		std::cout << "Quick sort" << std::endl;
		Sorting::quicksort(list3);
		for (int n : list3)
		{
			std::cout << n << " ";
		}
		std::cout << std::endl;
	}
	inline void lru_example()
	{
		std::cout << "LRU Cache example" << std::endl;

		LRU<int, int> cache(10);
		std::cout << "Add 10 elements to cache" << std::endl;

		cache.update(1, 1);
		cache.update(2, 2);
		cache.update(3, 3);
		cache.update(4, 4);
		cache.update(5, 5);
		cache.update(6, 6);
		cache.update(7, 7);
		cache.update(8, 8);
		cache.update(9, 9);
		cache.update(10, 10);

		std::cout << "Cache: " << cache << std::endl;
		cache.get(6);
		cache.get(3);
		cache.get(1);

		std::cout << "Get 3, 6, 1: " << cache << std::endl;

		cache.update(11, 11);
		cache.update(12, 12);
		cache.update(13, 13);

		std::cout << "Insert 11, 12, 13: " << cache << std::endl;
	}
	inline void recursion_example()
	{
		std::cout << recursion::factorial_non_recursive(5) << std::endl;
		std::cout << recursion::factorial_recursive(5) << std::endl;
		std::cout << recursion::is_palindrome_recursive("racecar") << std::endl;
		std::cout << recursion::is_palindrome_recursive("racecarr") << std::endl;
		recursion::print_all_binary(3);
		std::cout << "-----------------" << std::endl;
		recursion::diceSum(3, 7);
		std::cout << "-----------------" << std::endl;
		std::vector<std::string> name = { "N", "i", "c", "k" };
		recursion::permute(name);
		std::cout << "-----------------" << std::endl;
		std::cout << recursion::sumOfSquare(3) << std::endl;
		std::cout << "-----------------" << std::endl;
		std::vector<std::string> names = { "Jane", "Bob", "Matt", "Sara" };
		recursion::sublists(names);
		std::cout << "-----------------" << std::endl;
	}
	inline void maze_example()
	{
		//Test
		MazeSolver::StringVector maze =
		{
			"#####E#",
			"#     #",
			"#S    #",
		};
		MazeSolver::MazePoint start = MazeSolver::MazePoint(2, 1);
		MazeSolver::MazePoint end = MazeSolver::MazePoint(0, 5);

		constexpr char wall = '#';
		std::vector<MazeSolver::MazePoint> path = mazeSolver(maze, wall, start, end);

		std::cout << "Followed path for : " << maze[start.x][start.y] << " to " << maze[end.x][end.y] << std::endl;
		for (auto p : path)
		{
			std::cout << "x: " << p.x << ", y: " << p.y << std::endl;
		}

	}
	inline void graph_example()
	{
		std::cout << "Finding path in graph with BFS, DFS and Dijksta" << std::endl;
		std::cout << "BFS" << std::endl;
		AdjacenyMatrix adjMat
		{
			{0, 1, 1, 1, 0},
			{0, 0, 0, 0, 0},
			{0, 0, 0, 1, 0},
			{0, 0, 0, 0, 1},
			{0, 0, 0, 0, 0},
		};

		std::vector<int> path = Graphs::BFS(adjMat, 0, 4);
		std::cout << "Path: [ ";
		for(int i = 0; i < path.size(); i++)
		{
			std::cout << path[i] << " ";
		}
		std::cout << "]" << std::endl;

		std::cout << "DFS" << std::endl;
		std::vector<Edge> zeroVertex {{1,1 }, { 2,1 }, { 3,1 } };
		std::vector<Edge> oneVertex {};
		std::vector<Edge> twoVertex{{3,1 }};
		std::vector<Edge> threeVertex{{4,1 }};
		std::vector<Edge> fourVertex {};
		AdjacenyList adjList
		{
			zeroVertex,
			oneVertex,
			twoVertex,
			threeVertex,
			fourVertex,

		};

		std::vector<int> path1 = Graphs::DFS(adjList, 0, 4);
		std::cout << "Path: [ ";
		for (int i = 0; i < path1.size(); i++)
		{
			std::cout << path1[i] << " ";
		}
		std::cout << "]" << std::endl;
	}
}

