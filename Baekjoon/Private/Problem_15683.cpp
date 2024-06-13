#include "Problem_15683.h"

#include <vector>
#include <iostream>

using namespace std;

int iNumRow = { };
int iNumCol = { };

typedef struct tagWork
{
	pair<int, int> pairPos = { };

	int iOption = { };
	int iDigit = { };
} WORK;

void DFS_15683(vector<vector<int>>& vecCCTV, pair<int, int> pairPos, int& iAnswer, int iOption, int iDigit)
{
	// 상
	if ((iOption == 5) ||
		(iOption == 1 && (iDigit == 0)) ||
		(iOption == 2 && (iDigit == 0 || iDigit == 2)) ||
		(iOption == 3 && (iDigit == 0 || iDigit == 3)) ||
		(iOption == 4 && (iDigit == 0 || iDigit == 1 || iDigit == 3)))
	{
		if (pairPos.first > 0 &&
			vecCCTV[pairPos.first - 1][pairPos.second] != 6)
		{
			if (vecCCTV[pairPos.first - 1][pairPos.second] == 0)
			{
				++iAnswer;
				vecCCTV[pairPos.first - 1][pairPos.second] = 7;
			}
			DFS_15683(vecCCTV, { pairPos.first - 1, pairPos.second }, iAnswer, 1, 0);
		}
	}

	// 하
	if ((iOption == 5) ||
		(iOption == 1 && (iDigit == 2)) ||
		(iOption == 2 && (iDigit == 0 || iDigit == 2)) ||
		(iOption == 3 && (iDigit == 1 || iDigit == 2)) ||
		(iOption == 4 && (iDigit == 1 || iDigit == 2 || iDigit == 3)))
	{
		if (pairPos.first < iNumRow - 1 &&
			vecCCTV[pairPos.first + 1][pairPos.second] != 6)
		{
			if (vecCCTV[pairPos.first + 1][pairPos.second] == 0)
			{
				++iAnswer;
				vecCCTV[pairPos.first + 1][pairPos.second] = 7;
			}
			DFS_15683(vecCCTV, { pairPos.first + 1, pairPos.second }, iAnswer, 1, 2);
		}
	}

	// 좌
	if ((iOption == 5) ||
		(iOption == 1 && (iDigit == 3)) ||
		(iOption == 2 && (iDigit == 1 || iDigit == 3)) ||
		(iOption == 3 && (iDigit == 2 || iDigit == 3)) ||
		(iOption == 4 && (iDigit == 0 || iDigit == 2 || iDigit == 3)))
	{
		if (pairPos.second > 0 &&
			vecCCTV[pairPos.first][pairPos.second - 1] != 6)
		{
			if (vecCCTV[pairPos.first][pairPos.second - 1] == 0)
			{
				++iAnswer;
				vecCCTV[pairPos.first][pairPos.second - 1] = 7;
			}
			DFS_15683(vecCCTV, { pairPos.first, pairPos.second - 1 }, iAnswer, 1, 3);
		}
	}

	// 우
	if ((iOption == 5) ||
		(iOption == 1 && (iDigit == 1)) ||
		(iOption == 2 && (iDigit == 1 || iDigit == 3)) ||
		(iOption == 3 && (iDigit == 0 || iDigit == 1)) ||
		(iOption == 4 && (iDigit == 0 || iDigit == 1 || iDigit == 2)))
	{
		if (pairPos.second < iNumCol - 1 &&
			vecCCTV[pairPos.first][pairPos.second + 1] != 6)
		{
			if (vecCCTV[pairPos.first][pairPos.second + 1] == 0)
			{
				++iAnswer;
				vecCCTV[pairPos.first][pairPos.second + 1] = 7;
			}
			DFS_15683(vecCCTV, { pairPos.first, pairPos.second + 1 }, iAnswer, 1, 1);
		}
	}
}

int CProblem_15683::Solve_Problem()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> iNumRow >> iNumCol;

	int iBlank = { };

	vector<vector<int>> vecCCTV; vecCCTV.reserve(iNumRow);

	vector<vector<pair<int, int>>> vecCCTVPosition;
	for (int iCC = 0; iCC < 5; ++iCC)
		vecCCTVPosition.push_back(vector<pair<int, int>>{ });

	for (int iRow = 0; iRow < iNumRow; ++iRow)
	{
		vector<int> vecSrc; vecSrc.reserve(iNumCol);

		for (int iCol = 0; iCol < iNumCol; ++iCol)
		{
			int iSrc = { };
			cin >> iSrc;
			vecSrc.push_back(iSrc);

			if (iSrc > 0 && iSrc < 6)
				vecCCTVPosition[iSrc - 1].push_back(pair<int, int>{ iRow, iCol });

			if (iSrc == 0)
				++iBlank;
		}

		vecCCTV.push_back(vecSrc);
	}

	int iAnswer = { };

	// CCTV - 5번
	while (vecCCTVPosition[4].size() > 0)
	{
		pair<int, int> pairPos = vecCCTVPosition[4].back();
		vecCCTVPosition[4].pop_back();

		DFS_15683(vecCCTV, pairPos, iAnswer, 5, 0);
	}
	vecCCTVPosition.pop_back();

	// CCTV - 1 ~ 4번
	vector<vector<WORK>> vecWork;
	vector<vector<WORK>> vecWorkSrc;

	while (vecCCTVPosition.size() > 0)
	{
		vector<pair<int, int>> vecPosition = vecCCTVPosition.back();
		vecCCTVPosition.pop_back();

		while (vecPosition.size() > 0)
		{
			pair<int, int> pairPosition = vecPosition.back();
			vecPosition.pop_back();

			if (vecWork.size() == 0)
			{
				switch (vecCCTVPosition.size())
				{
				case 0:
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 1, 0 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 1, 1 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 1, 2 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 1, 3 } });
					break;
				case 1:
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 2, 0 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 2, 1 } });
					break;
				case 2:
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 3, 0 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 3, 1 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 3, 2 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 3, 3 } });
					break;
				case 3:
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 4, 0 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 4, 1 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 4, 2 } });
					vecWorkSrc.push_back(vector<WORK>{ WORK{ pairPosition, 4, 3 } });
					break;
				}
			}
			else
			{
				switch (vecCCTVPosition.size())
				{
				case 0:
					for (auto& workIter : vecWork)
					{
						workIter.push_back(WORK{ pairPosition, 1, 0 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 1, 1 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 1, 2 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 1, 3 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();
					}
					break;
				case 1:
					for (auto& workIter : vecWork)
					{
						workIter.push_back(WORK{ pairPosition, 2, 0 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 2, 1 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();
					}
					break;
				case 2:
					for (auto& workIter : vecWork)
					{
						workIter.push_back(WORK{ pairPosition, 3, 0 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 3, 1 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 3, 2 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 3, 3 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();
					}
					break;
				case 3:
					for (auto& workIter : vecWork)
					{
						workIter.push_back(WORK{ pairPosition, 4, 0 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 4, 1 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 4, 2 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();

						workIter.push_back(WORK{ pairPosition, 4, 3 });
						vecWorkSrc.push_back(workIter);
						workIter.pop_back();
					}
					break;
				}
			}

			if (vecWorkSrc.size() > 0)
			{
				swap(vecWork, vecWorkSrc);
				vecWorkSrc.clear();
			}
		}
	}

	int iMaxAnswer = { };
	for (auto& iter : vecWork)
	{
		int iSrcAnswer = { };
		vector<vector<int>> vecSrcCCTV = vecCCTV;
		for (auto& workIter : iter)
		{
			DFS_15683(vecSrcCCTV, workIter.pairPos, iSrcAnswer, workIter.iOption, workIter.iDigit);
		}

		iMaxAnswer = (iMaxAnswer < iSrcAnswer) ? iSrcAnswer : iMaxAnswer;
	}

	cout << iBlank - iAnswer - iMaxAnswer << endl;

	return 0;
}
