#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//const int boardSize = 9;
//const int width = ceil(sqrt(boardSize));

extern bool UCS;
extern bool euclidean;

class board{
    private:
        vector<int> currentState;
        vector<int> goalState;
        
    public:
        board();
        board(vector<int> v);
        ~board();
        board* parent;
        int boardSize;
        int width;
        double cost;
        double hCost;
        double gCost;
        //bool UCS;
        int blankLocation();
        board* moveUp();
        board* moveDown();
        board* moveLeft();
        board* moveRight();
        bool goalFound();
        double misplacedCost();
        void print();
        void printGoal();
        board* getParent();
        vector<int> getVec();
        void setVec(vector<int>);
        void setGoal(vector<int>);
        
        //Functions for UCS, Misplace and Eucledian distance
        int f();
        int g();
        int h();

};

struct CompareCost{ //comparator struct for priority queue
    bool operator()(board* const  b1, board* const b2){
        if(b1->cost == b2->cost){
            if(b1->gCost < b2->gCost){//THIS MAKES SURE TO PRIORITIZE g(n) IF f(n) is equal
                return false;
            }
        }
        else{
            return b1->cost > b2->cost;
        }
    }
};

#endif