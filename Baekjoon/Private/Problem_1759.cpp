#include "Problem_1759.h"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int CProblem_1759::Solve_Problem()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int iNumL = { }, iNumC = { };
	cin >> iNumL >> iNumC;

	string strSecretNode = { };
	for (int iC = 0; iC < iNumC; ++iC)
	{
		char chSrc = { };
		cin >> chSrc;

		strSecretNode.push_back(chSrc);
	}

	vector<int> vecPermutation;
	for (int iIndex = iNumL; iIndex < iNumC; ++iIndex)
		vecPermutation.push_back(0);
	for (int iIndex = 0; iIndex < iNumL; ++iIndex)
		vecPermutation.push_back(1);

	sort(strSecretNode.begin(), strSecretNode.end());

	unordered_set<string> setDup;
	vector<string> vecAnsPermutation;
	do
	{
		int iCons = { }, iGath = { };

		string strSrc = { };

		for (auto iter = vecPermutation.begin(); iter != vecPermutation.end(); ++iter)
		{
			if (*iter == 1)
			{
				strSrc.push_back(strSecretNode[distance(vecPermutation.begin(), iter)]);
			}
		}
		
		for (auto iter : strSrc)
		{
			if (iter == 'a' || iter == 'e' || iter == 'i' || iter == 'o' || iter == 'u')
				++iCons;
			else
				++iGath;
		}

		if (iCons > 0 && iGath > 1)
		{
			auto iter = setDup.find(strSrc);
			
			if (iter != setDup.end())
				continue;

			setDup.emplace(strSrc);
			vecAnsPermutation.push_back(strSrc);
		}

	} while (next_permutation(vecPermutation.begin(), vecPermutation.end()));

	sort(vecAnsPermutation.begin(), vecAnsPermutation.end());
	for (auto& iter : vecAnsPermutation)
		cout << iter << '\n';

	return 0;
}
