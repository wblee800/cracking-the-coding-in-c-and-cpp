// 백준 온라인 저지 1138번 https://www.acmicpc.net/problem/1138
// 제한 시간 : 2초
// 실행 시간 : 0ms

#include <iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numOfPeople;
	cin >> numOfPeople;

	int leftPeople;
	vector<int> line(numOfPeople, 0);
	for (int i = 0; i < numOfPeople; i++)
	{
		cin >> leftPeople;

		// 왼쪽에 leftPeople만큼의 공간을 남기고 값 할당
		int cnt = 0;
		int j;
		for (j = 0; cnt != (leftPeople + 1); j++)
		{
			if (line[j] == 0)
			{
				cnt++;
			}
		}
		line[j - 1] = i + 1;
	}

	for (int i = 0; i < numOfPeople; i++)
	{
		cout << line[i] << ' ';
	}
}