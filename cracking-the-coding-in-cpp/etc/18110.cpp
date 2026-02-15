// 백준 온라인 저지 18110번 https://www.acmicpc.net/problem/18110
// 제한 시간 : 1초
// 실행 시간 : 32ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	if (n == 0)
	{
		cout << 0;
		return 0;
	}

	vector<int> vec(n);
	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	float avg = 0;
	if (n * 0.15 - (int)(n * 0.15) >= 0.5)
	{
		for (int i = (int)(n * 0.15) + 1; i < n - ((int)(n * 0.15) + 1); i++)
		{
			avg += vec[i];
		}
		avg = avg / (n - (2 * ((int)(n * 0.15) + 1)));
	}
	else
	{
		for (int i = (int)(n * 0.15); i < n - (int)(n * 0.15); i++)
		{
			avg += vec[i];
		}
		avg = avg / (n - 2 * (int)(n * 0.15));
	}

	if (avg - (int)avg >= 0.5)
	{
		cout << (int)avg + 1;
	}
	else
	{
		cout << (int)avg;
	}
}
