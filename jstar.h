#ifndef JSTAR_H
#define JSTAR_H

#include "board.h"
#include <set>
#include <queue>

using namespace std;

class jStar{
    public:
        int maxQueueSize;
        int exploredSize;
        int expandSize;
        jStar();
        ~jStar();
        board* root;
        board* goal;
        set<vector<int>> explored;
        set<vector<int>> frontierSet;
        priority_queue<board*, vector<board*>, CompareCost> frontier;

        board* solve(board*);
        void printSolution(board*);
};

#endif