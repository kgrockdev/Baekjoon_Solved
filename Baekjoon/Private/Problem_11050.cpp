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

/* ���� ��� */
/*
������ ���� N�� ���� K���� �������� ���� ���� �̴� ������ ��
�����̶�� ���� ���� ������ �ϳ��� �����ۿ� ���� �̰ų� �Ȼ̰ų��� ���ø� ����
K == 0, K == N �϶��� ����� ���� 1 (���� �̰ų� �ϳ��� �Ȼ̰ų�)
DP�� N�� 1���̰� N�� K�� ��� 1 ���� ���� ���ϸ� ��
*/