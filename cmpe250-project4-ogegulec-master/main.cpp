
#include <vector>
#include <fstream>
#include <time.h>
#include <sstream>
#include <iterator>
#include <iomanip>
#include "WeightedGraph.h"
using namespace std;




template<class Container>
void splitter(const string& str, Container& cont){
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),back_inserter(cont));
}

//static void shortestPath(int grid[5][5], int row, int col,int beginx,int beginy,int targetx,int targety);

int gridSizeX = 0;
int gridSizeY = 0;

int main(int argc,char* argv[]) {
    clock_t tStart=clock();
    ifstream infile(argv[1]);
    char *out = argv[2];
    ofstream myfile;
    string line;
    if (!infile.is_open())
        cout << "Could not open file\n";
    getline(infile, line);
    vector<string> data;
    splitter(line, data);

    int row = stoi(data[0]);
    int column = stoi(data[1]);

    int grid[1000][1000];
    WeightedGraph g1(row*column);
    myfile.open(out);

    for (int i = 0; i < row; i++) {
        data.clear(); // cleaning up old data
        getline(infile, line);
        splitter(line, data);


        for (int j = 0; j < column; j++) {
            int w = stoi(data[j]);
            grid[i][j] = w;


        }

    }
    data.clear();
    getline(infile, line);
    splitter(line, data);
    int a=stoi(data[0]);


    int search[a*4];
    for(int i=0; i<a; i++){
        data.clear();
        getline(infile, line);
        splitter(line, data);
        for(int j=0; j<4; j++){
            search[4*i+j]=stoi(data[j]);
        }

    }



    int count=0;
    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(j!=column-1){
                int c=grid[i][j]-grid[i][j+1];
                int d=abs(c);
                g1.addEdge(count,count+1,d);
            }
            if(i!=row-1) {
                int c=grid[i][j]-grid[i+1][j];

                int d=abs(c);
                g1.addEdge(count,count+row,d);
            }
            count++;
        }
    }



       g1.primMST(search,row,column,myfile);
    myfile.close();




   // printf("time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);


    return 0;
}
/*
static void shortestPath(int grid[5][5], int row, int col,int beginx,int beginy,int targetx,int targety) {

    int dis[row][col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            dis[i][j] = INT_MAX;
    int disx[] = {-1, 0, 1, 0};
    int disy[] = {0, 1, 0, -1};
    priority_queue<WeightedGraph, vector<WeightedGraph>,comp<WeightedGraph>> distanceQ;
    distanceQ.push(WeightedGraph(beginx,beginy,0));
    dis[beginx-1][beginy-1]=0;
    while(!distanceQ.empty()){
        WeightedGraph g1= distanceQ.top();
        distanceQ.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = g1.x + disx[i];
            int y = g1.y + disy[i];


            if (!WeightedGraph::isInLimit(x, y,row,col)) {
                continue;
            }


            int a=grid[x][y]-grid[g1.x][g1.y];
            int b=abs(a);
            if(dis[x][y]>b ){

                dis[x][y]=b;
                distanceQ.push(WeightedGraph(x,y,b));
            }


        }

    }
    cout<<dis[targetx-1][targety-1];




}*/
