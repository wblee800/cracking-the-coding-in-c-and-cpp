// 백준 온라인 저지 11725번 https://www.acmicpc.net/problem/11725
// 제한 시간 : 1초
// 실행 시간 : 52ms

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void dfs(vector<vector<int> >& connected, vector<int>& parent, int no)
{
    for (int i = 0; i < connected[no].size(); i++)
    {
        if (parent[connected[no][i]] == 0)
        {
            parent[connected[no][i]] = no;
            dfs(connected, parent, connected[no][i]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, u, v;

    cin >> N;

    vector<vector<int> > connected(N + 1, vector <int>());
    vector<int> parent(N + 1, 0);

    for (int i = 0; i < N - 1; i++)
    {
        cin >> u >> v;
        connected[u].push_back(v);
        connected[v].push_back(u);
    }

    dfs(connected, parent, 1);

    vector<int>::iterator it;
    for (it = parent.begin() + 2; it < parent.end(); it++)
    {
        cout << *it << '\n';
    }

    return 0;
}