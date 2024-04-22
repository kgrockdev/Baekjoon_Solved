#include "Problem_1268.h"

using namespace std;

#include <vector>
#include <iostream>
#include <algorithm>

typedef struct tagStudentInfo
{
	int iStudentIdx = { };

	int iFirst = { };
	int iSecond = { };
	int iThird = { };
	int iForth = { };
	int iFifth = { };

	int iScore = { 0 };
} STD_INFO;

int CProblem_1268::Solve_Problem()
{
	vector<STD_INFO> vecStudents;

	int iNumStudent = { };
	cin >> iNumStudent;

	int iScoreArray[5][10] = { };
	for (int iStudent = 0; iStudent < 5; ++iStudent)
	{
		STD_INFO tInfo = { };
		cin >> tInfo.iFirst >> tInfo.iSecond >> tInfo.iThird >> tInfo.iForth >> tInfo.iFifth;

		iScoreArray[0][tInfo.iFirst]	+= 1;
		iScoreArray[1][tInfo.iSecond]	+= 1;
		iScoreArray[2][tInfo.iThird]	+= 1;
		iScoreArray[3][tInfo.iForth]	+= 1;
		iScoreArray[4][tInfo.iFifth]	+= 1;

		tInfo.iStudentIdx = iStudent + 1;
		vecStudents.push_back(tInfo);
	}

	for (int iStudent = 0; iStudent < 5; ++iStudent)
	{
		vecStudents[iStudent].iScore += iScoreArray[0][vecStudents[iStudent].iFirst];
		vecStudents[iStudent].iScore += iScoreArray[1][vecStudents[iStudent].iSecond];
		vecStudents[iStudent].iScore += iScoreArray[2][vecStudents[iStudent].iThird];
		vecStudents[iStudent].iScore += iScoreArray[3][vecStudents[iStudent].iForth];
		vecStudents[iStudent].iScore += iScoreArray[4][vecStudents[iStudent].iFifth];
	}

	sort(vecStudents.begin(), vecStudents.end(), [](STD_INFO tStdInfoA, STD_INFO tStdInfoB) 
		{
			if (tStdInfoA.iScore == tStdInfoB.iScore)
				return tStdInfoA.iStudentIdx < tStdInfoB.iStudentIdx;
			else
				return tStdInfoA.iScore > tStdInfoB.iScore;
		});

	cout << vecStudents[0].iStudentIdx << endl;

	return 0;
}
