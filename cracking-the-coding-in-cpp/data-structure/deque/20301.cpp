// 백준 온라인 저지 20301번 https://www.acmicpc.net/problem/20301
// 제한 시간 : 1초
// 실행 시간 : 84ms

// 핵심 : Josephus 문제와 달리 M명의 사람이 제거될 때마다 순서를 반전시켜야 한다.

#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int K;
	int M;
	deque<int> reverseJosephus;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		reverseJosephus.push_back(i + 1);
	}

	cin >> K >> M;
	int countOrder = 1;
	int countEliminatedPeople = 0;
	while (!reverseJosephus.empty())
	{
		// M명의 사람이 제거되었다면,
		if (countEliminatedPeople == M)
		{
			countEliminatedPeople = 0;
			// 순서 뒤집기
			reverse(reverseJosephus.begin(), reverseJosephus.end());
		}
		else
		{
			// K 번째 사람이면,
			if (countOrder == K)
			{
				// 출력 후 deque에서 꺼내기
				cout << reverseJosephus.front() << "\n";
				reverseJosephus.pop_front();

				countOrder = 1;
				countEliminatedPeople++;
			}
			else
			{
				// K 번째 사람이 아니므로 뒤로 보내기
				reverseJosephus.push_back(reverseJosephus.front());
				reverseJosephus.pop_front();

				countOrder++;
			}
		}
	}
}
