#include "Problem_20299.h"

#include <vector>
#include <iostream>

using namespace std;

int CProblem_20299::Solve_Problem()
{
	int iNumTeam = { }, iNumTeamScore = { }, iNumScore = { };
	cin >> iNumTeam >> iNumTeamScore >> iNumScore;

	vector<int> vecScores;
	for (int iIndex = 0; iIndex < iNumTeam; ++iIndex)
	{
		int iSrcA = { }, iSrcB = { }, iSrcC = { };
		cin >> iSrcA >> iSrcB >> iSrcC;

		if (iSrcA + iSrcB + iSrcC < iNumTeamScore)
			continue;

		if (iSrcA < iNumScore ||
			iSrcB < iNumScore || 
			iSrcC < iNumScore)
			continue;

		vecScores.push_back(iSrcA);
		vecScores.push_back(iSrcB);
		vecScores.push_back(iSrcC);
	}

	cout << vecScores.size() / 3 << endl;
	for (auto iter : vecScores)
		cout << iter << " ";
	cout << endl;

	return 0;
}
