#include "Problem_31712.h"

#include <vector>
#include <iostream>

using namespace std;

typedef struct tagSkillDesc
{
    int iDelay = { };
    int iDamage = { };
} SKILL;

int CProblem_31712::Solve_Problem()
{
    vector<SKILL> vecSkills;

    for (int iIndex = 0; iIndex < 3; ++iIndex)
    {
        SKILL tSkill = { };
        cin >> tSkill.iDelay >> tSkill.iDamage;

        vecSkills.push_back(tSkill);
    }

    int iHP = { }, iTime = { };
    cin >> iHP;

    while (iHP > 0)
    {
        for (auto iter : vecSkills)
        {
            if (iTime % iter.iDelay == 0)
                iHP -= iter.iDamage;
        }

        ++iTime;
    }

    cout << iTime - 1 << endl;

    return 0;
}
