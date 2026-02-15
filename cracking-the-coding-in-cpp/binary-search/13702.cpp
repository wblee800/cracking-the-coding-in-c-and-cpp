// 백준 온라인 저지 13702번 https://www.acmicpc.net/problem/13702
// 제한 시간 : 1초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int BinarySearch(vector<int>& capacityOfMakgeolli, int maxCapacity, int K)
{
	int answer = 0;
	sort(capacityOfMakgeolli.begin(), capacityOfMakgeolli.end());

	size_t start = 0, end = (pow(2, 31));

	vector<int> originalCapacityOfMakgeolli = capacityOfMakgeolli;
	int cntFriends = 0;
	while (start <= end)
	{
		size_t mid = (start + end) / 2;
		cntFriends = 0;

		for (int j = 0; j < capacityOfMakgeolli.size(); j++)
		{
			cntFriends += max((size_t)0, capacityOfMakgeolli[j] / mid);
		}

		// 친구들이 모두 mid만큼 먹었다면,
		if (cntFriends >= K)
		{
			answer = mid;
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}

		capacityOfMakgeolli = originalCapacityOfMakgeolli;
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 은상이가 주문한 막걸리 주전자의 개수(N <= 10,000)
	int N;
	// 은상이를 포함한 친구들의 수(K <= 1,000,000)
	int K;

	cin >> N >> K;

	// 막걸리 용량 입력(0 <= 막걸리 용량 <= 2^31 - 1)
	vector<int> capacityOfMakgeolli(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> capacityOfMakgeolli[i];
	}

	int maxCapacity = -1;
	maxCapacity = BinarySearch(capacityOfMakgeolli, maxCapacity, K);

	cout << maxCapacity;

	return 0;
}