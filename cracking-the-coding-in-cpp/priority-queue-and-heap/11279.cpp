// 백준 온라인 저지 11279번 https://www.acmicpc.net/problem/11279
// 제한 시간 : 1초 (추가 시간 없음)
// 실행 시간 : 16ms

#include <iostream>
#include <vector>
using namespace std;

void Swap(vector<int>& maxHeap, int x, int y)
{
	int temp = maxHeap[x];
	maxHeap[x] = maxHeap[y];
	maxHeap[y] = temp;
}

// 배열의 끝에 push를 하고 parent보다 값이 같거나 작을 때까지 비교한다.
void Push(vector<int>& maxHeap, int x)
{
	maxHeap.push_back(x);

	int child = maxHeap.size() - 1;
	int parent = child / 2;

	while (child > 1 && maxHeap[child] > maxHeap[parent])
	{
		Swap(maxHeap, child, parent);
		child = parent;
		parent = child / 2;
	}
}

// root를 pop하고 맨 끝 노드를 root로 올려 child보다 같거나 클 때까지 비교한다.
int Pop(vector<int>& maxHeap)
{
	int root = maxHeap[1];
	int heapSize = maxHeap.size() - 1;

	Swap(maxHeap, 1, heapSize);
	maxHeap.pop_back();
	heapSize--;

	int parent = 1;
	int child = parent * 2;

	// 자식 중 더 큰 수를 가진 자식 선택
	if (child + 1 <= heapSize)
	{
		child = (maxHeap[child] > maxHeap[child + 1]) ? child : child + 1;
	}

	while (child <= heapSize && maxHeap[child] > maxHeap[parent])
	{	
		Swap(maxHeap, child, parent);
		parent = child;
		child = parent * 2;

		if (child + 1 <= heapSize)
		{
			child = (maxHeap[child] > maxHeap[child + 1]) ? child : child + 1;
		}
	}

	return root;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> maxHeap(1, 0);

	int N; // (1 ≤ N ≤ 100,000)
	int x; // 연산에 대한 정보 (0 ≤ x < 2^31)

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> x;
		
		// x가 자연수이면,
		if (x > 0)
		{
			// 힙에 x 대입
			Push(maxHeap, x);
		}
		else if (!x)
		{
			if (maxHeap.size() == 1)
			{
				cout << 0 << '\n';
				continue;
			}

			// 힙에서 가장 큰 값 출력
			cout << Pop(maxHeap) << '\n';
		}
	}
}