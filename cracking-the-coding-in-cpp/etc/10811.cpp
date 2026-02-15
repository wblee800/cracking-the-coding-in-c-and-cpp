// 백준 온라인 저지 10811번 https://www.acmicpc.net/problem/10811
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vec;
	int N, M;
	int startNumber, endNumber;

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		vec.push_back(i + 1);
	}

	vector<int>::iterator itr = vec.begin();
	for (int i = 0; i < M; i++)
	{
		cin >> startNumber >> endNumber;
		startNumber -= 1;
		/*endNumber -= 1;*/
		
		reverse(itr + startNumber, itr + endNumber);
	}

	for (int i : vec)
	{
		cout << i << " ";
	}
}
