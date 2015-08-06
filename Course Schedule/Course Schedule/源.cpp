#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//拓扑排序 BFS  Topological sort with BFS C++
//分析：不一定是全连通图；入度为0的顶点依次进入队列，然后依次出队，度相应改变（即删除相应边），最后所有顶点的度为0则表明没环
void createGraph(int numCourses,vector<vector<int>>& graph,vector<int>& inDegree,vector<pair<int,int>> prerequisites)
{
	for (size_t i = 0; i < prerequisites.size(); i++)
	{
		int first = prerequisites[i].first;
		int second = prerequisites[i].second;
		graph[second].push_back(first);
		++inDegree[first];
	}
}


bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) 
{
	if (prerequisites.size()<1)
	{
		return true;
	}
	vector<int> inDegree(numCourses, 0);
	vector<vector<int>> graph(numCourses, vector<int>());
	createGraph(numCourses, graph, inDegree, prerequisites);
	queue<int> q;
	//把入度为0的点进队
	for (size_t i = 0; i < numCourses; i++)
	{
		if (inDegree[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int vertex = q.front();
		q.pop();
		for (size_t i = 0; i < graph[vertex].size(); i++)
		{
			int neighbor = graph[vertex][i];
			--inDegree[neighbor];
			if (inDegree[neighbor] == 0)
			{
				q.push(neighbor);
			}
		}
	}
	for (size_t i = 0; i < numCourses; i++)
	{
		if (inDegree[i]>0)  //表明拓扑排序后还剩下节点
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n = 3;
	//vector<pair<int, int>> prerequisites = { make_pair(1, 0), make_pair(0, 1), make_pair(3, 2), make_pair(2, 1) };   
	vector<pair<int, int>> prerequisites = { make_pair(2, 1),make_pair(1,0) };
	bool result = canFinish(n,prerequisites);
	if (result)
	{
		cout << "possible" << endl;
	}
	else
	{
		cout << "impossible" << endl;
	}
	system("pause");
	return 0;
}