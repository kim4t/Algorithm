class Solution
{
	unordered_set<int> visited;
public:
	int countComponents(int n, vector<vector<int>> edges)
	{
		vector<vector<int>> vertices(n);
		for (vector<int>& edge : edges)
		{
			vertices[edge[0]].push_back(edge[1]);
			vertices[edge[1]].push_back(edge[0]);
		}

		int res = 0;
		for (int i = 0; i < n; i++)
		{
			if (visited.find(i) == visited.end())
			{
				res++;
				DFS(vertices, res, i);
			}
		}
		
		return res;
	}

	void DFS(vector<vector<int>>& vertices, int& res, int index)
	{
		visited.emplace(index);
		for (int& e : vertices[index])
		{
			if (visited.find(e) == visited.end())
				DFS(vertices, res, e);
		}
	}
	
};
