// 백준 온라인 저지 1260번 https://www.acmicpc.net/problem/1260
// 제한 시간 : 2초
// 실행 시간 : 0ms

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int> >& link, vector<int>& visit, int V)
{
	int connectedNode;

	for (int i = 0; i < link[V].size(); i++)
	{
		connectedNode = link[V][i];

		if (visit[connectedNode] == 0)
		{
			cout << ' ' << connectedNode;
			visit[connectedNode] = 1;
			dfs(link, visit, connectedNode);
		}
	}
}

void bfs(vector<vector<int> >& link, vector<int>& visit, int V)
{
	queue<int> q;
	q.push(V);
	visit[V] = 1;

	while (!q.empty())
	{
		int now = q.front();
		cout << now << ' ';
		q.pop();

		for (int next : link[now])
		{
			if (visit[next] == 0)
			{
				q.push(next);
				visit[next] = 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, V, u, v;

	cin >> N >> M >> V;

	vector<vector<int> > link(N + 1, vector <int>());
	vector<int> visit_using_dfs(N + 1, 0);
	vector<int> visit_using_bfs(N + 1, 0);

	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		link[u].push_back(v);
		link[v].push_back(u);
	}

	for (int i = 1; i < N + 1; i++)
	{
		sort(link[i].begin(), link[i].end());
	}

	visit_using_dfs[V] = 1;
	cout << V;
	dfs(link, visit_using_dfs, V);

	cout << '\n';

	bfs(link, visit_using_bfs, V);

	return 0;
}