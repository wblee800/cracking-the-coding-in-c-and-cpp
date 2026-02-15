// 백준 온라인 저지 1874번 https://www.acmicpc.net/problem/1874
// 제한 시간 : 2초
// 실행 시간 : 28ms

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int num;
	int maxPop = 0;
	stack<int> stackSequence;
	vector<string> pushOrPop;

	for (int i = 0; i < n; i++)
	{
		cin >> num;

		while (true)
		{
			// stack이 비어있으면,
			if (stackSequence.empty())
			{
				// pop된 값 중 최대 값부터 입력값만큼
				for (int i = maxPop; i < num; i++)
				{
					stackSequence.push(i + 1);
					pushOrPop.push_back("+");
				}

				if (stackSequence.top() > maxPop)
				{
					maxPop = stackSequence.top();
				}

				stackSequence.pop();
				pushOrPop.push_back("-");

				break;
			}
			// 현재 입력값(num)이 stack top의 값과 같으면,
			else if (num == stackSequence.top())
			{
				if (stackSequence.top() > maxPop)
				{
					maxPop = stackSequence.top();
				}
				
				stackSequence.pop();
				pushOrPop.push_back("-");
				break;
			}
			// 현재 입력값(num)이 stack top의 값보다 크면,
			else if (num > stackSequence.top())
			{
				stackSequence.push(++maxPop);
				pushOrPop.push_back("+");
			}
			// 현재 입력값(num)이 stack top의 값보다 작으면,
			else if (num < stackSequence.top())
			{
				cout << "NO";
				pushOrPop.push_back("NO");
				break;
			}
		}

		if (pushOrPop.back() == "NO")
		{
			break;
		}
	}

	if (pushOrPop.back() != "NO")
	{
		for (string i : pushOrPop)
		{
			cout << i << '\n';
		}
	}
}
