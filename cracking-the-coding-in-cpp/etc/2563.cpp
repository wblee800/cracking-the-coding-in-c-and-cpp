// 백준 온라인 저지 2563번 https://www.acmicpc.net/problem/2563
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int distance_of_left, distance_of_bottom;
	vector<vector<int>> colored_paper(100, vector<int>(100,0));

	int colored_paper_number;
	cin >> colored_paper_number;
	for (int i = 0; i < colored_paper_number; i++)
	{
		cin >> distance_of_left >> distance_of_bottom;
		for (int j = distance_of_bottom; j < distance_of_bottom + 10; j++)
		{
			for (int k = distance_of_left; k < distance_of_left + 10; k++)
			{
				colored_paper[j][k] = -1;
			}
		}
	}
	
	int area_of_colored_paper = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			if (colored_paper[i][j] == -1)
			{
				area_of_colored_paper++;
			}
		}
	}
	cout << area_of_colored_paper;
}
