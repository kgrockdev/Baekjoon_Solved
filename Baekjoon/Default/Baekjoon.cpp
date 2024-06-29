#include "Problem_0000.h"
#include "Problem_11931.h"

int main()
{
	CProblem_11931::Solve_Problem();
}

/*

	vector<int> vecPermutation; vecPermutation.push_back(0);
	for (int iCheck = 1; iCheck < iNumCheck - 2; ++iCheck)
		vecPermutation.push_back(1);

	vector<int> vecSrc;
	for (int iCheck = 0; iCheck < iNumCheck - 2; ++iCheck)
		vecSrc.push_back(iCheck);

	int iAnswer = { INT_MAX };

	do
	{
		vector<int> vecOrder; vecOrder.push_back(0);
		for (int iOrder = 0; iOrder < vecSrc.size(); ++iOrder)
		{
			if (vecPermutation[iOrder] == 1)
				vecOrder.push_back(vecSrc[iOrder] + 1);
		}
		vecOrder.push_back(vecCheckPoint.size() - 1);

		int iSrcMin = { };
		for (auto iter = vecOrder.begin();;)
		{
			pair<int, int> pairA = vecCheckPoint[*(iter++)];
			if (iter == vecOrder.end())
				break;

			pair<int, int> pairB = vecCheckPoint[*(iter)];

			iSrcMin += CalcManhattanDist_10655(pairA, pairB);
		}

		iAnswer = (iAnswer < iSrcMin) ? iAnswer : iSrcMin;

	} while (next_permutation(vecPermutation.begin(), vecPermutation.end()));

	cout << iAnswer << endl;

*/