// 백준 온라인 저지 2965번 https://www.acmicpc.net/problem/2965
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 초기 위치 입력
	int left, mid, right;
	cin >> left >> mid >> right;
	
	// 캥거루의 최대 움직임 횟수
	int maxMovement = 0;
	// left, mid, right 값이 공차가 1인 등차수열이 될 때까지 반복
	while (mid - left != 1 || right - mid != 1)
	{
		// left와 mid 사이의 거리가 mid와 right 사이의 거리보다 크다면,
		if (mid - left > right - mid)
		{
			right = mid;
			mid -= 1;
		}
		// mid와 right 사이의 거리가 left와 mid 사이의 거리보다 크다면,
		else if (mid - left < right - mid)
		{
			left = mid;
			mid += 1;
		}
		// 거리가 같다면,
		else if (mid - left == right - mid)
		{
			// right = mid; 거리가 같으므로 어떤 곳으로 이동하든 상관 x
			left = mid;
			mid += 1;
		}
		maxMovement++;
	}
	cout << maxMovement;
}
