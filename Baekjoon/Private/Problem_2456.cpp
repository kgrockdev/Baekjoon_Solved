#include "Problem_2456.h"

using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>

#define NUM_CANDIDATE 3

typedef struct tagCandidate
{
	int iNumber = { };
	int iScore = { };
	
	int iThree = { };
	int iTwo = { };
} CAND;

int CProblem_2456::Solve_Problem()
{
	vector<CAND> vecContainer;

	int iNum = { };
	cin >> iNum;

	vecContainer.reserve(NUM_CANDIDATE);

	for (int iIndex = 0; iIndex < NUM_CANDIDATE; ++iIndex)
		vecContainer.push_back({ iIndex + 1, 0 });

	for (int iIndex = 0; iIndex < iNum; ++iIndex)
	{
		int iScoreA = { }, iScoreB = { }, iScoreC = { };
		cin >> iScoreA >> iScoreB >> iScoreC;

		vecContainer[0].iThree += (iScoreA == 3) ? 1 : 0;
		vecContainer[1].iThree += (iScoreB == 3) ? 1 : 0;
		vecContainer[2].iThree += (iScoreC == 3) ? 1 : 0;

		vecContainer[0].iTwo += (iScoreA == 2) ? 1 : 0;
		vecContainer[1].iTwo += (iScoreB == 2) ? 1 : 0;
		vecContainer[2].iTwo += (iScoreC == 2) ? 1 : 0;

		vecContainer[0].iScore += iScoreA;
		vecContainer[1].iScore += iScoreB;
		vecContainer[2].iScore += iScoreC;
	}

	sort(vecContainer.begin(), vecContainer.end(), 
		[](CAND tElemA, CAND tElemB)->bool 
		{ 
			if (tElemA.iScore == tElemB.iScore)
			{
				if (tElemA.iThree == tElemB.iThree)
					return tElemA.iTwo > tElemB.iTwo;
				else
					return tElemA.iThree > tElemB.iThree;
			}
			else
				return tElemA.iScore > tElemB.iScore; 
		});

	if (vecContainer[0].iScore == vecContainer[1].iScore &&
		vecContainer[0].iThree == vecContainer[1].iThree &&
		vecContainer[0].iTwo == vecContainer[1].iTwo)
		cout << "0 " << vecContainer[0].iScore;
	else
		cout << vecContainer[0].iNumber << " " << vecContainer[0].iScore;

	return 0;
}
