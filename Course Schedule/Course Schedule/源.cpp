#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//�������� BFS  Topological sort with BFS C++
//��������һ����ȫ��ͨͼ�����Ϊ0�Ķ������ν�����У�Ȼ�����γ��ӣ�����Ӧ�ı䣨��ɾ����Ӧ�ߣ���������ж���Ķ�Ϊ0�����û��
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
	//�����Ϊ0�ĵ����
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
		if (inDegree[i]>0)  //�������������ʣ�½ڵ�
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