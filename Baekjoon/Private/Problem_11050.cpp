#include "Problem_11050.h"

using namespace std;

#include <map>
#include <iostream>

typedef struct tagMulKey
{
    int iN = { };
    int iK = { };

    bool operator<(const tagMulKey& tSrc) const 
    {
        if (iN == tSrc.iN)
            return iK < tSrc.iK;
        else
            return iN < tSrc.iN;
    }
} MKEY;

map<MKEY, int> mapMemo_11050;

int Calc_11050(int iN, int iK)
{
    if (iK == 0 || iN == iK)
        return 1;

    auto iter = mapMemo_11050.find(MKEY{ iN, iK });
    if (iter != mapMemo_11050.end())
        return iter->second;
    else
    {
        int iSrc = Calc_11050(iN - 1, iK) + Calc_11050(iN - 1, iK - 1);
        mapMemo_11050.emplace(MKEY{ iN, iK }, iSrc);
    
        return iSrc;
    }
}

int CProblem_11050::Solve_Problem()
{
    int iN = { }, iK = { };
    cin >> iN >> iK;

    cout << Calc_11050(iN, iK) << '\n';

    return 0;
}

/* 이항 계수 */
/*
원소의 개수 N에 대해 K개의 아이템을 순서 없이 뽑는 조합의 수
이항이라는 말이 뭍은 이유는 하나의 아이템에 대해 뽑거나 안뽑거나의 선택만 존재
K == 0, K == N 일때의 경우의 수는 1 (전부 뽑거나 하나도 안뽑거나)
DP로 N을 1줄이고 N과 K를 모두 1 줄인 것을 더하면 됨
*/