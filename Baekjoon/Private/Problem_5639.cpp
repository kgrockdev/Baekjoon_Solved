#include "Problem_5639.h"

#include <vector>
#include <iostream>

using namespace std;

void Call_5639(vector<int>& vecContainer, int iSNode, int iENode)
{
    if (iSNode == iENode)
        return;

    int iSrc = { iENode };
    for (int iIndex = iSNode + 1; iIndex < iENode; ++iIndex)
    {
        if (vecContainer[iIndex] > vecContainer[iSNode])
        {
            iSrc = iIndex;
            break;
        }
    }

    Call_5639(vecContainer, iSNode + 1, iSrc);
    Call_5639(vecContainer, iSrc, iENode);

    cout << vecContainer[iSNode] << '\n';
}

int CProblem_5639::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iSrc = { };
    vector<int> vecContainer;
    vecContainer.reserve(10000);

    while (cin >> iSrc)
        vecContainer.push_back(iSrc);

    Call_5639(vecContainer, 0, vecContainer.size());

    return 0;
}

/*

// 전위순회 결과 중앙 앞 뒤
// 후위순회 실행 앞 뒤 중앙

50 - 루트
30 - 왼 서브
24
5
28
45
98 - 오른 서브
52
60

*/

/*


typedef struct tagTreeNode
{
    int iNode = { };

    int iLeft = { };
    int iRight = { };
} NODE;

void Create_LeftSubTree(unordered_map<int, NODE>& mapTree, int iNode)
{

}

void Call_5639(unordered_map<int, NODE>& mapTree, int iNode)
{
    auto iter = mapTree.find(iNode);

    if (iter->second.iLeft != -1)
        Call_5639(mapTree, iter->second.iLeft);
    if (iter->second.iRight != -1)
        Call_5639(mapTree, iter->second.iRight);

    cout << iNode << '\n';
}


    unordered_map<int, NODE> mapTree;

    vector<pair<int, int>> vecParent;
    vecParent.reserve(10000);

    int iSrc = { }, iRoot = { };
    while (cin >> iSrc)
    {
        if (vecParent.size() == 0)
        {
            iRoot = iSrc;
            vecParent.push_back({ 0, iSrc });
            mapTree.emplace(iSrc, NODE{ iSrc, -1, -1 });
        }
        else
        {
            pair<int, int> iParent = vecParent.back();
            if (iSrc < iParent.second)
            {
                mapTree.find(iParent.second)->second.iLeft = iSrc;
                mapTree.emplace(iSrc, NODE{ iSrc, -1, -1 });
                vecParent.push_back({ 0, iSrc });
            }
            else
            {
                vecParent.pop_back();

                iParent = vecParent.back();
                mapTree.find(iParent.second)->second.iRight = iSrc;
                mapTree.emplace(iSrc, NODE{ iSrc, -1, -1 });
                vecParent.push_back({ 1, iSrc });
            }
        }
    }

    Call_5639(mapTree, iRoot);

*/

/*

                while (true)
                {
                    auto iterLeft = find_if(vecParent.begin(), vecParent.end(),
                        [](pair<int, int> pairSrc) { return (pairSrc.first == 0); });

                    auto iterRight = find_if(vecParent.begin(), vecParent.end(),
                        [](pair<int, int> pairSrc) { return (pairSrc.first == 1); });

                    if (iterLeft == vecParent.end() ||
                        iterRight == vecParent.end())
                    {
                        mapTree.find(vecParent.back().second)->second.iRight = iSrc;
                        mapTree.emplace(iSrc, NODE{ iSrc, -1, -1 });
                        vecParent.push_back({ 1, iSrc });

                        break;
                    }

                    vecParent.pop_back();
                }

*/

/*

                if (is_sorted(vecParent.begin(), vecParent.end()) == true)
                {
                    iParent = vecParent.back();

                    mapTree.find(iParent)->second.iRight = iSrc;
                    mapTree.emplace(iSrc, NODE{ iSrc, -1, -1 });
                    vecParent.push_back(iSrc);
                }
                else
                {
                    bool bCheck = { false };
                    while (vecParent.size() > 1)
                    {
                        vecParent.pop_back();

                        if (iParent > vecParent.back() &&
                            is_sorted(vecParent.begin(), vecParent.end()) == true)
                        {
                            bCheck = true;

                            vecParent.push_back(iParent);
                            iParent = vecParent.back();

                            mapTree.find(iParent)->second.iRight = iSrc;
                            mapTree.emplace(iSrc, NODE{ iSrc, -1, -1 });
                            vecParent.push_back(iSrc);

                            break;
                        }
                        else
                        {
                            if (vecParent.back() < iSrc)
                                iParent = vecParent.back();
                            else
                            {
                                vecParent.push_back(iParent);
                                break;
                            }
                        }
                    }

                    if (bCheck == false)
                    {
                        mapTree.find(iParent)->second.iRight = iSrc;
                        mapTree.emplace(iSrc, NODE{ iSrc, -1, -1 });
                        vecParent.push_back(iSrc);
                    }
                }

*/

/*
*                 vecParent.clear();
                vecParent.push_back(iRoot);
* 

                while (true)
                {
                    auto& iter = mapTree.find(vecParent.back())->second;
                    if (iSrc < iter.iNode)
                    {
                        if (iter.iLeft != -1)
                            vecParent.push_back(iter.iLeft);
                        else
                        {
                            iter.iLeft = iSrc;
                            mapTree.emplace(iSrc, NODE{ iSrc, -1, -1 });
                            vecParent.push_back(iSrc);
                            break;
                        }
                    }
                    else
                    {
                        if (iter.iRight != -1)
                            vecParent.push_back(iter.iRight);
                        else
                        {
                            iter.iRight = iSrc;
                            mapTree.emplace(iSrc, NODE{ iSrc, -1, -1 });
                            vecParent.push_back(iSrc);
                            break;
                        }
                    }
                }

*/