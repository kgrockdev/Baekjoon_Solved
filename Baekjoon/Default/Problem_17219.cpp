#include "Problem_17219.h"

using namespace std;

#include <string>
#include <iostream>
#include <unordered_map>

int CProblem_17219::Solve_Problem()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int iNumStore = { }, iNumFind = { };
	cin >> iNumStore >> iNumFind;

	unordered_map<string, string> mapStorage;

	for (int iIndex = 0; iIndex < iNumStore; ++iIndex)
	{
		string strSite = { }, strPassword = { };
		cin >> strSite >> strPassword;

		mapStorage.emplace(strSite, strPassword);
	}

	for (int iIndex = 0; iIndex < iNumFind; ++iIndex)
	{
		string strSite = { };
		cin >> strSite;

		cout << mapStorage.find(strSite)->second << '\n';
	}

	return 0;
}
