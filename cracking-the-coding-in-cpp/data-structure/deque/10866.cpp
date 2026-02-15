// 백준 온라인 저지 10866번 https://www.acmicpc.net/problem/10866
// 제한 시간 : 0.5초
// 실행 시간 : 4ms

// 핵심 : front와 back 둘 다 push와 pop을 할 수 있다.

// 문제점 1 : push_front X를 입력 시, front에 값을 push하고, 원래 있던 값들은 한 칸씩 뒤로 이동해야 하는데, 이동하지 않는다.
// 해결 1 : 한 칸씩 뒤로 미룰 때, 값을 입력하지 않은 배열의 영역에 값을 넣으려고 하면 발생하는 문제였기에 배열을 선언과 동시에 모든 인덱스의 값을 0으로 초기화했다.

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	cin.ignore();

	int deque[10000] = { 0, };
	int dequeFrontPtr = 0;
	int dequeBackPtr = -1;
	int X;
	string dequeOperation;

	for (int i = 0; i < N; i++)
	{
		cin >> dequeOperation;

		if (dequeOperation == "push_front")
		{
			cin >> X;
			dequeBackPtr++;

			deque[dequeBackPtr] = -999;
			for (int i = dequeBackPtr; i > 0; i--)
			{
				deque[i] = deque[i - 1];
			}
			deque[dequeFrontPtr] = X;
			

		}
		else if (dequeOperation == "push_back")
		{
			cin >> X;

			dequeBackPtr++;
			deque[dequeBackPtr] = X;
		}
		else if (dequeOperation == "pop_front")
		{
			if (dequeBackPtr == -1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deque[dequeFrontPtr] << "\n";
				for (int i = 0; i < dequeBackPtr; i++)
				{
					deque[i] = deque[i + 1];
				}
				dequeBackPtr--;
			}
		}
		else if (dequeOperation == "pop_back")
		{
			if (dequeBackPtr == -1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deque[dequeBackPtr] << "\n";
				deque[dequeBackPtr] = '\n';
				dequeBackPtr--;
			}
		}
		else if (dequeOperation == "size")
		{
			cout << dequeBackPtr + 1 << "\n";
		}
		else if (dequeOperation == "empty")
		{
			if (dequeBackPtr == -1)
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
		else if (dequeOperation == "front")
		{
			if (dequeBackPtr == -1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deque[dequeFrontPtr] << "\n";
			}
		}
		else if (dequeOperation == "back")
		{
			if (dequeBackPtr == -1)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << deque[dequeBackPtr] << "\n";
			}
		}
	}
}
