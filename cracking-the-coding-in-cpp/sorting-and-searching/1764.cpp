// 백준 온라인 저지 1764번 https://www.acmicpc.net/problem/1764
// 제한 시간 : 2초
// 실행 시간 : 40ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int M;

	vector<string> groupN;
	vector<string> groupM;
	string name;
	
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		cin >> name;

		if (i < N)
		{
			groupN.push_back(name);
		}
		else
		{
			groupM.push_back(name);
		}
	}

	sort(groupN.begin(), groupN.end());
	sort(groupM.begin(), groupM.end());

	vector<string> groupNM;
	for (int i = 0; i < M; i++)
	{
		if (binary_search(groupN.begin(), groupN.end(), groupM[i]))
		{
			groupNM.push_back(groupM[i]);
		}
	}

	cout << groupNM.size() << "\n";
	for (string i : groupNM)
	{
		cout << i << "\n";
	}
}
