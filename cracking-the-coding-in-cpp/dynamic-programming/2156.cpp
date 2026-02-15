// 백준 온라인 저지 2156번 https://www.acmicpc.net/problem/2156
// 제한 시간 : 2초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 포도주 잔의 개수
	int n;
	cin >> n;

	// 포도주의 양을 담는 배열
	vector<int> theNumOfWine(n);
	for (int i = 0; i < n; i++)
	{
		cin >> theNumOfWine[i];
	}
	
	// 마지막 앞의 포도주와 마지막 포도주를 마시거나 안 마시는 모든 경우
	vector<int> wine00(2, 0);
	vector<int> wine01(2, 0);
	vector<int> wine10(2, 0);
	vector<int> wine11(2, 0);

	if (n == 1)
	{
		cout << theNumOfWine[0];
		return 0;
	}
	else if (n == 2)
	{
		cout << theNumOfWine[0] + theNumOfWine[1];
		return 0;
	}


	wine00[0] = 0;
	wine00[1] = theNumOfWine[0];

	wine01[0] = theNumOfWine[1];
	wine01[1] = theNumOfWine[0] + theNumOfWine[2];

	wine10[0] = theNumOfWine[0];
	wine10[1] = theNumOfWine[0] + theNumOfWine[1];

	wine11[0] = theNumOfWine[0] + theNumOfWine[1];
	wine11[1] = theNumOfWine[1] + theNumOfWine[2];

	for (int i = 3; i < n; i++)
	{
		wine00[0] = wine00[1];
		wine00[1] = max(wine00[1], wine10[1]);

		wine01[0] = wine01[1];
		wine01[1] = max(wine00[0], wine10[1]) + theNumOfWine[i];

		wine10[0] = wine10[1];
		wine10[1] = max(wine01[0], wine11[1]);

		wine11[0] = wine11[1];
		wine11[1] = wine01[0] + theNumOfWine[i];
	}

	cout << max(max(wine00[1], wine01[1]), max(wine10[1], wine11[1]));
}
