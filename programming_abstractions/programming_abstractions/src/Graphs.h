#pragma once
#include <vector>

typedef std::vector<std::vector<int>> AdjacenyMatrix;

struct Edge
{
	int to;
	int weight;
};
typedef std::vector<std::vector<Edge>> AdjacenyList;

class Graphs
{
public:
	//Path finding
	//In DFS recursion we can choose and unchoose and build path like this
	//In BFS we can not do this
	//Make us of prev arr filled with -1's = from whom i came from --> build in reverse to get path, if -1 --> not path found
	//Seen arr to mark visited nodes
	static std::vector<int> BFS(AdjacenyMatrix graph, int source, int needle)
	{
		std::vector<bool> seen(graph.size(), false);
		//We have seen source == start vertex
		seen[source] = true;
		
		std::vector<int> prev(graph.size(), -1);

		//Use vector as q
		std::vector<int> q { source };

		while(!q.empty())
		{
			int curr = q[0];
			q.erase(q.begin());

			if(curr == needle)
			{
				break;
			}

			std::vector<int> adjs = graph[curr];
			for(int i = 0; i < adjs.size(); i++)
			{
				//no edge
				if(adjs[i] == 0 || seen[i])
				{
					continue;
				}

				seen[i] = true;
				prev[i] = curr;

				q.emplace_back(i);
			}
			
		}

		//No path found
		if(prev[needle] == -1)
		{
			return {};
		}

		//build path backwards
		//Start at point we wanted to find
		int curr = needle;
		std::vector<int> out {needle};

		while(prev[curr] != -1)
		{
			out.emplace_back(prev[curr]);
			curr = prev[curr];
		}

		//out.emplace_back(source);
		std::reverse(out.begin(), out.end());

		return out;
	}

	static bool dfsHelper(AdjacenyList graph, int curr, int needle, std::vector<bool>& seen, std::vector<int>& path)
	{
		if(seen[curr])
		{
			return false;
		}

		seen[curr] = true;

		//choose
		path.emplace_back(curr);

		if (curr == needle)
		{
			return true;
		}

		std::vector<Edge> edgeList = graph[curr];
		for(int i = 0; i < edgeList.size(); i++)
		{
			Edge edge = edgeList[i];

			//If we succesfully walk this path and find needle
			if(dfsHelper(graph, edge.to, needle, seen, path))
			{
				return true;
			}
		}

		//unchoose
		path.pop_back();
		return false;
	}
	static std::vector<int> DFS(AdjacenyList graph, int source, int needle)
	{
		std::vector<bool> seen(graph.size(), false);
		std::vector<int> path;

		dfsHelper(graph, source, needle, seen, path);

		return path;
	}


	static bool hasUnivisited(const std::vector<bool>& seen, const std::vector<int>& distances)
	{
		bool has = false;

		for(int i = 0; i < seen.size(); i++)
		{
			if(!seen[i] && distances[i] < _MAX_INT_DIG)
			{
				return true;
			}
		}
		return false;
	};

	static int getLowestUnivisted(const std::vector<bool>& seen, const std::vector<int>& distances)
	{
		int idx = -1;
		int lowestDistance = _MAX_INT_DIG;

		for(int i = 0; i < seen.size(); i++)
		{
			if(seen[i])
			{
				continue;
			}
			if(lowestDistance > distances[i])
			{
				lowestDistance = distances[i];
				idx = i;
			}
		}

		return idx;
	}

	static std::vector<int> dijkstra_list(AdjacenyList graph, int source, int sink)
	{
		std::vector<bool> seen(graph.size(), false);
		std::vector<int> prev(graph.size(), -1);
		std::vector<int> distances(graph.size(), _MAX_INT_DIG);

		distances[source] = 0;

		while(hasUnivisited(seen, distances))
		{
			int curr = getLowestUnivisted(seen, distances);
			seen[curr] = true;

			std::vector<Edge> adjs = graph[curr];
			for(int i = 0; i < adjs.size(); i++)
			{
				Edge edge = adjs[i];
				if(seen[edge.to])
				{
					continue;
				}

				int dist = distances[curr] + edge.weight;

				if(dist < distances[edge.to])
				{
					distances[edge.to] = dist;
					prev[edge.to] = curr;
				}
			}
		}

		std::vector<int> out{source};
		int curr = sink;

		while(prev[curr] != -1)
		{
			out.emplace_back(curr);
			curr = prev[curr];
		}

		out.emplace_back(source);
		std::reverse(out.begin(), out.end());

		return out;
	}
};
