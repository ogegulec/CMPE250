//
// Created by ege onur güleç on 19.12.2018.
//

#ifndef PROJECT5_SEARCH_H
#define PROJECT5_SEARCH_H
#include <iostream>
#include <fstream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <vector>
#include<stdio.h>
#include<string.h>
#include <time.h>
#include <list>
#define d 256
using namespace std;
class Search{
public:
    list<int> *adjList;

    void find(string pat, string txt, int q);
    Search(int a);
    void calculate(int a,ofstream &myfile);

};




#endif //PROJECT5_SEARCH_H
