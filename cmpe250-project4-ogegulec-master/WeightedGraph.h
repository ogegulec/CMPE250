//
// Created by ege onur güleç on 1.12.2018.
//

#ifndef PROJECT4_WEIGHTEDGRAPH_H
#define PROJECT4_WEIGHTEDGRAPH_H
#include <vector>
#include <cmath>
#include <list>
#include <queue>
#include <string>
#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#define INF 0x3f3f3f3f
using namespace std;
typedef pair<int,int> iPair;
class WeightedGraph{
    public:
    int V;
    void addEdge(int u,int v,int w);
    void addEdge2(int u,int v,int w);
    void primMST(int search[],int row,int column,ofstream &myfile);
    list <pair<int,int> > *adj;
    list <pair<int,int> > *adjMST;

    WeightedGraph(int V);
    static int shortestPath2(int **grid, int row, int col,int beginx,int beginy,int targetx,int targety);
   static  bool isInLimit(int i,int j,int row,int column);

void pathBFS(int search[],vector<int> key,int row,int column,ofstream &myfile);







};


#endif //PROJECT4_WEIGHTEDGRAPH_H
