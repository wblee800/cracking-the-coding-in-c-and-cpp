// 백준 온라인 저지 2477번 https://www.acmicpc.net/problem/2477
// 제한 시간 : 1초
// 실행 시간 : 0ms

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// The number of oriental melons
	int K;
	cin >> K;

	int direction[6];
	int length[6];

	// The size of a field of oriental melon
	int sizeOfField = 0;

	for (size_t i = 0; i < 6; i++)
	{
		cin >> direction[i] >> length[i];
	}

	switch (direction[0])
	{
	// Start 1
	case 1:
		// Next 3
		if (direction[1] == 3)
		{	
			// 131423
			sizeOfField = (length[3] * length[4]) - (length[0] * length[1]);
		}
		// Next 4
		else
		{
			// Next 1
			if (direction[2] == 1)
			{
				// 141423
				sizeOfField = (length[4] * length[5]) - (length[1] * length[2]);
			}
			// Next 2
			else
			{
				// Next 4
				if (direction[3] == 4)
				{
					// 142423
					sizeOfField = (length[0] * length[5]) - (length[2] * length[3]);
				}
				// Next 3
				else
				{
					// Next 2
					if (direction[4] == 2)
					{
						// 142323
						sizeOfField = (length[0] * length[1]) - (length[3] * length[4]);
					}
					// Next 1
					else
					{
						// Next 3
						if (direction[5] == 3)
						{
							// 142313
							sizeOfField = (length[1] * length[2]) - (length[4] * length[5]);
						}
						// Next 4
						else
						{
							// 142314
							sizeOfField = (length[2] * length[3]) - (length[0] * length[5]);
						}
					}
				}
			}
		}
		break;
	// Start 2
	case 2:
		// Next 4
		if (direction[1] == 4)
		{
			// 242314
			sizeOfField = (length[3] * length[4]) - (length[0] * length[1]);
		}
		// Next 3
		else
		{
			// Next 2
			if (direction[2] == 2)
			{
				// 232314
				sizeOfField = (length[4] * length[5]) - (length[1] * length[2]);
			}
			// Next 1
			else
			{
				// Next 3
				if (direction[3] == 3)
				{
					// 231314
					sizeOfField = (length[0] * length[5]) - (length[2] * length[3]);
				}
				// Next 4
				else
				{
					// Next 1
					if (direction[4] == 1)
					{
						// 231414
						sizeOfField = (length[0] * length[1]) - (length[3] * length[4]);
					}
					// Next 2
					else
					{
						// Next 3
						if (direction[5] == 3)
						{
							// 231423
							sizeOfField = (length[2] * length[3]) - (length[0] * length[5]);
						}
						// Next 4
						else
						{
							// 231424
							sizeOfField = (length[1] * length[2]) - (length[4] * length[5]);
						}
					}
				}
			}
		}
		break;
	// Start 3
	case 3:
		// Next 2
		if (direction[1] == 2)
		{
			// 323142
			sizeOfField = (length[3] * length[4]) - (length[0] * length[1]);
		}
		// Next 1
		else
		{
			// Next 3
			if (direction[2] == 3)
			{
				// 313142
				sizeOfField = (length[4] * length[5]) - (length[1] * length[2]);
			}
			// Next 4
			else
			{
				// Next 1
				if (direction[3] == 1)
				{
					// 314142
					sizeOfField = (length[0] * length[5]) - (length[2] * length[3]);
				}
				// Next 2
				else
				{
					// Next 4
					if (direction[4] == 4)
					{
						// 314242
						sizeOfField = (length[0] * length[1]) - (length[3] * length[4]);
					}
					// Next 3
					else
					{
						// Next 1
						if (direction[5] == 1)
						{
							// 314231
							sizeOfField = (length[2] * length[3]) - (length[0] * length[5]);
						}
						// Next 2
						else
						{
							// 314232
							sizeOfField = (length[1] * length[2]) - (length[4] * length[5]);
						}
					}
				}
			}
		}
		break;
	// Start 4
	case 4:
		// Next 1
		if (direction[1] == 1)
		{
			// 414231
			sizeOfField = (length[3] * length[4]) - (length[0] * length[1]);
		}
		// Next 2
		else
		{
			// Next 4
			if (direction[2] == 4)
			{
				// 424231
				sizeOfField = (length[4] * length[5]) - (length[1] * length[2]);
			}
			// Next 3
			else
			{
				// Next 2
				if (direction[3] == 2)
				{
					// 423231
					sizeOfField = (length[0] * length[5]) - (length[2] * length[3]);
				}
				// Next 1
				else
				{
					// Next 3
					if (direction[4] == 3)
					{
						// 423131
						sizeOfField = (length[0] * length[1]) - (length[3] * length[4]);
					}
					// Next 4
					else
					{
						// Next 1
						if (direction[5] == 1)
						{
							// 423141
							sizeOfField = (length[1] * length[2]) - (length[4] * length[5]);
						}
						// Next 2
						else
						{
							// 423142
							sizeOfField = (length[2] * length[3]) - (length[0] * length[5]);
						}
					}
				}
			}
		}
		break;
	default:
		break;
	}
	
	// Multiply the size of a field of oriental melon and the number of oriental melons
	cout << sizeOfField * K;
}