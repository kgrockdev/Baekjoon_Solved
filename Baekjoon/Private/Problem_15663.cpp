#include "Problem_15663.h"

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int CProblem_15663::Solve_Problem()
{
	int iN = { }, iM = { };
	cin >> iN >> iM;

	vector<int> vecContainer;

	for (int iIndex = 0; iIndex < iN; ++iIndex)
	{
		int iSrc = { };
		cin >> iSrc;

		vecContainer.push_back(iSrc);
	}

	sort(vecContainer.begin(), vecContainer.end());
	set<vector<int>> setPermutation;

	do
	{
		vector<int> vecSrc;

		for (int iIndex = 0; iIndex < iM; ++iIndex)
			vecSrc.push_back(vecContainer[iIndex]);

		setPermutation.emplace(vecSrc);

	} while (next_permutation(vecContainer.begin(), vecContainer.end()));

	for (auto& iterPerm : setPermutation)
	{
		for (auto& iter : iterPerm)
		{
			cout << iter << " ";
		}
		cout << '\n';
	}

	return 0;
}
