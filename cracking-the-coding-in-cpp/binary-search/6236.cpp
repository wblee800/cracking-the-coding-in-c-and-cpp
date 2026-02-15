// 백준 온라인 저지 6236번 https://www.acmicpc.net/problem/6236
// 제한 시간 : 1초
// 실행 시간 : ms

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int BinarySearch(vector<int>& atm, int M)
{
	int ans = 0;
	sort(atm.begin(), atm.end());

	int start = 1;
	// 하루 이용 최대 금액
	int end = 10000 * 100000 + 1;

	int cntWithdrawal = 0;
	// 현재 내 돈의 총합
	int sumOfMoney = 0;
	bool isPayable = true;
	while (start <= end)
	{
		// 인출 금액 K = mid
		size_t K = (start + end) / 2;

		isPayable = true;
		sumOfMoney = 0;
		cntWithdrawal = 0;

		// 매일 인출
		for (int i = 0; i < atm.size(); i++)
		{
			// 인출해야 하는 금액보다 가지고 있는 금액이 크거나 같으면,
			if (atm[i] <= sumOfMoney)
			{
				sumOfMoney -= atm[i];
			}
			// 인출해야 하는 금액보다 가지고 있는 금액이 작으면,
			else
			{
				// 인출
				sumOfMoney = K;

				// 인출 횟수 카운팅
				cntWithdrawal++;

				// 인출한 금액 K가 atm[i]보다 작으면
				if (K < atm[i])
				{
					isPayable = false;

					// 오늘 사용할 금액이 부족
					break;
				}
				// 인출한 금액이 오늘 사용할 금액보다 같거나 많으면,
				else
				{
					// 통장에 다시 집어넣고, 다시 K원 인출
					sumOfMoney -= atm[i];
				}
			}
		}

		// 인출 제한 횟수 M보다 기간 내 인출한 횟수보다 크면,
		if (M < cntWithdrawal || !isPayable)
		{
			start = K + 1;
		}
		else
		{
			ans = K;
			end = K - 1;
		}
	}

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// N일, 인출 제한 횟수 M번 (1 ≤ N ≤ 100,000, 1 ≤ M ≤ N)
	int N, M;
	cin >> N >> M;

	vector<int> atm(N, 0);
	for (size_t i = 0; i < atm.size(); i++)
	{
		cin >> atm[i];
	}

	int K = BinarySearch(atm, M);
	cout << K;

	return 0;
}