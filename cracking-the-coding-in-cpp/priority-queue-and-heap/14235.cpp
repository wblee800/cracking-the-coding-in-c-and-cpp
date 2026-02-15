// 백준 온라인 저지 14235번 https://www.acmicpc.net/problem/14235
// 제한 시간 : 2초
// 실행 시간 : 24ms

#include <iostream>
#include <vector>
using namespace std;

void Swap(vector<int>& gifts, int x, int y)
{
	int temp = gifts[x];
	gifts[x] = gifts[y];
	gifts[y] = temp;
}

void Push(vector<int>& gifts, int x)
{
	gifts.push_back(x);

	int heapSize = gifts.size() - 1;
	int child = heapSize;
	int parent = child / 2;

	while (child > 1 && gifts[child] > gifts[parent])
	{
		Swap(gifts, child, parent);
		child = parent;
		parent = child / 2;
	}
}

int Pop(vector<int>& gifts)
{
	int root = gifts[1];

	int heapSize = gifts.size() - 1;
	Swap(gifts, 1, heapSize);
	gifts.pop_back();
	heapSize--;

	int parent = 1;
	int child = parent * 2;

	if (child + 1 <= heapSize)
	{
		child = (gifts[child] > gifts[child + 1]) ? child : child + 1;
	}

	while (child <= heapSize && gifts[child] > gifts[parent])
	{
		Swap(gifts, child, parent);
		parent = child;
		child = parent * 2;

		if (child + 1 <= heapSize)
		{
			child = (gifts[child] > gifts[child + 1]) ? child : child + 1;
		}
	}

	return root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n; // 거점지 방문 횟수(1 ≤ n ≤ 5,000)
    int a; // 충전할 선물 개수(1 ≤ a ≤ 100)

	int gift; // 선물들의 가치(0 ≤ gift < 100,000)
	vector<int> gifts(1, 0); // 선물들의 가치를 담는 배열, 최대 크기 n(5,000) * a(100)

	cin >> n;
	for (int i = 0; i < n; i++)
	{				
		cin >> a;

		if (!a)
		{
			if (gifts.size() == 1)
			{
				cout << -1 << '\n';
			}
			else
			{
				// 가장 큰 수 출력 + 가장 큰 수 제거
				cout << Pop(gifts) << '\n';
			}
		}
		else
		{
			for (int j = 0; j < a; j++)
			{
				// 선물들의 가치 입력
				cin >> gift;

				// gifts에 대입
				Push(gifts, gift);
			}
		}
	}
}
