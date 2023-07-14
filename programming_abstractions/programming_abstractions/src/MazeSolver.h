#pragma once
#include <string>
#include <vector>

namespace MazeSolver
{
	
	struct MazePoint
	{
		int x;
		int y;

		MazePoint(int x, int y)
		{
			this->x = x;
			this->y = y;
		}
	};

	typedef std::vector<std::string> StringVector;

	typedef std::vector<bool> BoolVector;
	typedef std::vector<BoolVector> BoolVector2D;
	inline bool mazeSolverHelper(StringVector& maze, char wall, MazePoint curr, MazePoint end, bool** seen, std::vector<MazePoint>& path)
	{
		//Base cases:
		//Off the wall
		if (curr.x < 0 || curr.x >= maze.size() || curr.y < 0 || curr.y >= maze[0].size())
		{
			return false;
		}
		//On wall
		if (maze[curr.x][curr.y] == wall)
		{
			return false;
		}
		//At end
		if (curr.x == end.x && curr.y == end.y)
		{
			//Add last node
			path.emplace_back(end);
			return true;
		}
		//Visited
		if (seen[curr.x][curr.y])
		{
			return false;
		}

		//pre recurse: choose
		seen[curr.x][curr.y] = true;
		path.emplace_back(curr);
		//recurse
		//walk up
		if (mazeSolverHelper(maze, wall, MazePoint(curr.x - 1, curr.y), end, seen, path))
			return true;
		//walk right
		if (mazeSolverHelper(maze, wall, MazePoint(curr.x, curr.y + 1), end, seen, path))
			return true;
		//walk down
		if (mazeSolverHelper(maze, wall, MazePoint(curr.x + 1, curr.y), end, seen, path))
			return true;
		//walk left
		if (mazeSolverHelper(maze, wall, MazePoint(curr.x, curr.y - 1), end, seen, path))
			return true;
		//post recurse: un choose
		path.pop_back();

		return false;
	}

	inline std::vector<MazePoint> mazeSolver(StringVector& maze, char wall, MazePoint start, MazePoint end)
	{
		BoolVector2D seen = {
			{false,false,false,false,false,false},
			{false,false,false,false,false,false},
			{false,false,false,false,false,false},
		};

		//Testing 2d array raw
		bool** seenRaw = new bool* [3];
		for (int i = 0; i < 3; i++)
		{
			seenRaw[i] = new bool[6];
			for (int j = 0; j < 6; j++)
			{
				seenRaw[i][j] = false;
			}
		}


		std::vector<MazePoint> path = {};
		mazeSolverHelper(maze, wall, start, end, seenRaw, path);

		//Delete arr
		for (int i = 0; i < 3; i++)
		{
			delete[] seenRaw[i];
		}
		delete[] seenRaw;
		return path;
	}
}
