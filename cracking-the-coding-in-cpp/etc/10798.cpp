// 백준 온라인 저지 10798번 https://www.acmicpc.net/problem/10798
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <string>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string array[5][15] = {"-1", };
	string inputletters;

	for (int i = 0; i < 5; i++)
	{
		cin >> inputletters;

		for (int j = 0; j < inputletters.size(); j++)
		{
			array[i][j] = inputletters[j];
		}
	}

	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (array[j][i] == "-1")
			{
				continue;
			}
			else
			{
				cout << array[j][i];
			}
		}
	}
}
