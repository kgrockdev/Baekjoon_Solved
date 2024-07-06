#include "Problem_1991.h"

#include <map>
#include <iostream>

using namespace std;

typedef struct tagNode
{
    char chNode = { };

    char chLeft = { };
    char chRight = { };
} NODE;

void CallLTree_1991(map<char, NODE>& mapTree, char chNode)
{
    auto iter = mapTree.find(chNode);

    cout << chNode;

    if (iter->second.chLeft != '.')
        CallLTree_1991(mapTree, iter->second.chLeft);

    if (iter->second.chRight != '.')
        CallLTree_1991(mapTree, iter->second.chRight);
}

void CallCTree_1991(map<char, NODE>& mapTree, char chNode)
{
    auto iter = mapTree.find(chNode);

    if (iter->second.chLeft != '.')
        CallCTree_1991(mapTree, iter->second.chLeft);

    cout << chNode;

    if (iter->second.chRight != '.')
        CallCTree_1991(mapTree, iter->second.chRight);
}

void CallRTree_1991(map<char, NODE>& mapTree, char chNode)
{
    auto iter = mapTree.find(chNode);

    if (iter->second.chLeft != '.')
        CallRTree_1991(mapTree, iter->second.chLeft);

    if (iter->second.chRight != '.')
        CallRTree_1991(mapTree, iter->second.chRight);

    cout << chNode;
}

int CProblem_1991::Solve_Problem()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);

    int iNum = { };
    cin >> iNum;

    map<char, NODE> mapTree;

    for (int iNode = 0; iNode < iNum; ++iNode)
    {
        char chNode = { }, chLeft = { }, chRight = { };
        cin >> chNode >> chLeft >> chRight;

        mapTree.emplace(chNode, NODE{ chNode, chLeft, chRight });
    }

    CallLTree_1991(mapTree, 'A');
    cout << '\n';

    CallCTree_1991(mapTree, 'A');
    cout << '\n';

    CallRTree_1991(mapTree, 'A');
    cout << '\n';

    return 0;
}
