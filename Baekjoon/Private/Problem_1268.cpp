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

	vector<int> vecFriends;
} STD_INFO;

int CProblem_1268::Solve_Problem()
{
	vector<STD_INFO> vecStudents;

	int iNumStudent = { };
	cin >> iNumStudent;

	for (int iStudent = 0; iStudent < iNumStudent; ++iStudent)
	{
		STD_INFO tInfo = { };
		cin >> tInfo.iFirst >> tInfo.iSecond >> tInfo.iThird >> tInfo.iForth >> tInfo.iFifth;

		tInfo.iStudentIdx = iStudent + 1;
		vecStudents.push_back(tInfo);
	}

	for (auto& itSelf : vecStudents)
	{
		for (auto& itOther : vecStudents)
		{
			if (itSelf.iStudentIdx == itOther.iStudentIdx)
				continue;

			if ((itSelf.iFirst == itOther.iFirst) ||
				(itSelf.iSecond == itOther.iSecond) ||
				(itSelf.iThird == itOther.iThird) ||
				(itSelf.iForth == itOther.iForth) ||
				(itSelf.iFifth == itOther.iFifth))
				itSelf.vecFriends.push_back(itOther.iStudentIdx);
		}
	}

	sort(vecStudents.begin(), vecStudents.end(), [](STD_INFO tStdInfoA, STD_INFO tStdInfoB)
		{
			if (tStdInfoA.vecFriends.size() == tStdInfoB.vecFriends.size())
				return tStdInfoA.iStudentIdx < tStdInfoB.iStudentIdx;
			else
				return tStdInfoA.vecFriends.size() > tStdInfoB.vecFriends.size();
		});

	cout << vecStudents[0].iStudentIdx << endl;

	return 0;
}
