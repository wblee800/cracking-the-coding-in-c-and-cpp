// 백준 온라인 저지 18111번 https://www.acmicpc.net/problem/18111
// 제한 시간 : 1초 (추가 시간 없음)
// 실행 시간 : 516ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// (1 ≤ M, N ≤ 500, 0 ≤ B ≤ 6.4 × 107)
	int N, M, B;
	cin >> N >> M >> B;

	vector<vector<int>> ground(N, vector<int>(M));
	for (size_t y = 0; y < N; y++)
	{
		for (size_t x = 0; x < M; x++)
		{
			cin >> ground[y][x];
		}
	}

	// 블록을 쌓거나, 제거하는 시간
	vector<int> timeLoadedOrDeletedBlock(257, 0);

	// 당장에 인벤토리에 블록이 없어 블록을 쌓지 못한 곳의 인덱스 위치
	typedef pair<int, int> p;

	for (size_t hToMake = 0; hToMake <= 256; hToMake++)
	{
		int nowB = B;
		vector<p> cannotBuiltPosition;

		for (size_t y = 0; y < N; y++)
		{
			for (size_t x = 0; x < M; x++)
			{
				// 현재 땅의 높이가 만들려는 높이보다 높으면,
				if (ground[y][x] > hToMake)
				{
					// 한 블럭당 제거 시간 2초 추가
					timeLoadedOrDeletedBlock[hToMake] += (ground[y][x] - hToMake) * 2;
					// 제거한 블록만큼 인벤토리에 블록 저장
					nowB += (ground[y][x] - hToMake);
				}
				// 현재 땅의 높이가 만들려는 높이보다 낮으면,
				else if (ground[y][x] < hToMake)
				{
					// 현재 인벤토리에 있는 블록의 개수가 쌓아야 하는 블록의 개수보다 많으면,
					if (nowB >= (hToMake - ground[y][x]))
					{
						// 한 블럭당 쌓는 시간 1초 추가
						timeLoadedOrDeletedBlock[hToMake] += (hToMake - ground[y][x]) * 1;
						// 쌓은 블록만큼 인벤토리에서 제거
						nowB -= (hToMake - ground[y][x]);
					}
					// 현재 인벤토리에 있는 블록의 개수가 쌓아야 하는 블록의 개수보다 적으면,
					else
					{
						// 인벤토리에 블록이 없어 블록을 쌓지 못한 곳의 인덱스 저장
						cannotBuiltPosition.push_back(make_pair(y, x));
					}
				}
			}
		}

		// 모든 땅을 순회한 후, 인벤토리에 담긴 블록의 개수와 블록을 쌓지 못한 곳에 쌓아야 하는 블록의 개수를 비교
		int tempY, tempX;
		for (size_t i = 0; i < cannotBuiltPosition.size(); i++)
		{
			tempY = cannotBuiltPosition[i].first;
			tempX = cannotBuiltPosition[i].second;
			
			// 현재 인벤토리에 있는 블록의 개수가 쌓아야 하는 블록의 개수보다 많으면,
			if (0 < nowB && (hToMake - ground[tempY][tempX]) <= nowB)
			{
				// 한 블럭당 쌓는 시간 1초 추가
				timeLoadedOrDeletedBlock[hToMake] += (hToMake - ground[tempY][tempX]) * 1;
				// 쌓은 블록만큼 인벤토리에서 제거
				nowB -= (hToMake - ground[tempY][tempX]);
			}
			// 모든 땅을 순회해 얻은 인벤토리의 블록 개수가 부족하다면,
			else
			{
				// 해당 hToMake로 높이를 맞출 수 없으므로 높이를 맞추는 경우와 구분짓기 위해 -1로 값 변경
				timeLoadedOrDeletedBlock[hToMake] = -1;
				break;
			}
		}
	}

	int minTime = timeLoadedOrDeletedBlock[0];
	int maxHOfMinTime;
	for (int i = 0; i <= 256; i++)
	{
		if (0 <= timeLoadedOrDeletedBlock[i] && timeLoadedOrDeletedBlock[i] <= minTime)
		{
			minTime = timeLoadedOrDeletedBlock[i];
			maxHOfMinTime = i;
		}
	}

	cout << timeLoadedOrDeletedBlock[maxHOfMinTime] << ' ' << maxHOfMinTime;
}