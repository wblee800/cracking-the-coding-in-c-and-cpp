// 백준 온라인 저지 1920번 https://www.acmicpc.net/problem/1920
// 제한 시간 : 1초
// 실행 시간 : 52ms

#include <iostream>
#include <algorithm>
using namespace std;

bool BinarySearch(int* arrN, int left, int right, int mI);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num;
	int N;
	cin >> N;
	int* arrayN = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> num;
		arrayN[i] = num;
	}

	int M;
	cin >> M;
	int* arrayM = new int[M];
	for (int i = 0; i < M; i++)
	{
		cin >> num;
		arrayM[i] = num;
	}

	sort(arrayN, arrayN + N);

	for (int i = 0; i < M; i++)
	{
		cout << BinarySearch(arrayN, 0, N - 1, arrayM[i]) << '\n';
	}

	delete[] arrayN;
	delete[] arrayM;
}

bool BinarySearch(int* arrN, int left, int right, int mI)
{
	int mid = (left + right) / 2;

	// ¿À¸§Â÷¼ø Á¤·ÄµÈ arrayNÀÇ ¿ø¼ÒµéÀ» ¹ÝÀ¸·Î ³ª´² mI°¡ Àý¹Ý °ªº¸´Ù ÀÛÀºÁö Å«Áö È®ÀÎ
	if (left != right)
	{
		// Áß°£¿¡ À§Ä¡ÇÑ °ª°ú °°À¸¸é,
		if (mI == arrN[mid])
		{
			return 1;
		}
		// Áß°£¿¡ À§Ä¡ÇÑ °ªº¸´Ù ÀÛÀ¸¸é,
		else if (mI < arrN[mid])
		{
			// ¿ÞÂÊ¿¡¼­ ÀÌºÐ Å½»ö
			return BinarySearch(arrN, left, mid, mI);
		}
		// Áß°£¿¡ À§Ä¡ÇÑ °ªº¸´Ù Å©¸é,
		else if (mI > arrN[mid])
		{
			// ¿À¸¥ÂÊ¿¡¼­ ÀÌºÐ Å½»ö
			return BinarySearch(arrN, mid + 1, right, mI);
		}
	}
	// left¿Í right °ªÀÌ °°À¸¸é,
	else
	{
		// Áß°£¿¡ À§Ä¡ÇÑ °ª°ú °°À¸¸é,
		if (mI == arrN[mid])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
}