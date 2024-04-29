#include "Problem_2579.h"

using namespace std;

#include <iostream>

int arrStairs[2][301] = { };
int arrStairScores[301] = { };

int CProblem_2579::Solve_Problem()
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	int iNumChair = { };
	cin >> iNumChair;

	for (int iIndex = 0; iIndex < iNumChair; ++iIndex)
	{
		int iSrc = { };
		cin >> iSrc;

		arrStairScores[iIndex] = iSrc;
	}

	arrStairs[0][0] = 0;
	arrStairs[1][0] = 0;

	arrStairs[0][1] = arrStairScores[0];
	arrStairs[1][1] = arrStairScores[0];

	for (int iIndex = 2; iIndex <= iNumChair; ++iIndex)
	{
		// Stairs 0 : �� ĭ ���� �ڽ��� ���̳� �� ĭ ���� ����� �� �ۿ� ���� �� ����
		// Stairs 1 : �� ĭ ���� �ڽ��� ���̳� �� ĭ ���� ����� �� �ۿ� ���� �� ����, �� ���� �ִ� ��

		arrStairs[0][iIndex] = max(arrStairs[0][iIndex - 2], arrStairs[1][iIndex - 1]) + arrStairScores[iIndex - 1];
		arrStairs[1][iIndex] = max(arrStairs[0][iIndex - 2], arrStairs[1][iIndex - 2]) + arrStairScores[iIndex - 1];
	}

	cout << max(arrStairs[0][iNumChair], arrStairs[1][iNumChair]) << '\n';

	return 0;
}
