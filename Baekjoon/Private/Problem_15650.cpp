#include "Problem_15650.h"

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_15650::Solve_Problem()
{
	int iNum = { }, iSel = { };
	cin >> iNum >> iSel;

	vector<int> vecSrcPerm;
	vector<int> vecPermutation;

	for (int iIndex = iSel; iIndex < iNum; ++iIndex)
		vecSrcPerm.push_back(0);

	for (int iIndex = 0; iIndex < iSel; ++iIndex)
		vecSrcPerm.push_back(1);

	for (int iIndex = 0; iIndex < iNum; ++iIndex)
		vecPermutation.push_back(iIndex + 1);

	set<vector<int>> setPermutation;

	do
	{
		vector<int> vecSrc;

		for (auto iIndex = 0; iIndex < iNum; ++iIndex)
		{
			if (vecSrcPerm[iIndex] == 1)
				vecSrc.push_back(vecPermutation[iIndex]);
		}

		setPermutation.emplace(vecSrc);

	} while (next_permutation(vecSrcPerm.begin(), vecSrcPerm.end()));

	for (auto& iter : setPermutation)
	{
		for (auto& elem : iter)
		{
			cout << elem << " ";
		}

		cout << endl;
	}

    return 0;
}