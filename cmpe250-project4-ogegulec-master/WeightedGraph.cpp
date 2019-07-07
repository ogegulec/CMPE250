//
// Created by ege onur güleç on 7.12.2018.
//
#include "WeightedGraph.h"


WeightedGraph::WeightedGraph(int V) {
        this->V = V;
    adj = new list<iPair>[this->V];
    adjMST = new list<iPair>[this->V];

}

void WeightedGraph::addEdge(int u, int v, int w) {
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));

}
void WeightedGraph::addEdge2(int u, int v, int w) {
    adjMST[u].push_back(make_pair(v,w));
    adjMST[v].push_back(make_pair(u,w));
}
bool WeightedGraph::isInLimit(int i, int j, int row, int col) {
    return(i>=0 && i<row && j>=0 && j<col);

}
void WeightedGraph::primMST(int search[],int row,int column,ofstream &myfile) {
    priority_queue<iPair,vector<iPair>,greater<iPair> > pq;
    int src = 0;

    vector<int> key(V,INF);
    vector<int> parent(V,-1);
    vector<bool> inMST(V,false);

    pq.push(make_pair(0,src));
    key[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;
        list<pair<int,int> >::iterator it;
        for(it = adj[u].begin();it!=adj[u].end();it++){
            int v = (*it).first;
            int weight = (*it).second;

            if(!inMST[v] && key[v] > weight){
                key[v] = weight;
                pq.push(make_pair(key[v],v));
               parent[v] = u;

            }
        }

    }


  for(int i=1;i<V;i++){
        //cout << parent[i] << " - "  << i <<" "<< key[i]<< endl;
        addEdge2(i,parent[i],key[i]);
    }
   /* for(int i=0; i<V; i++){
        list<pair<int,int> >::iterator it;
        for(it = adjMST[i].begin();it!=adjMST[i].end();it++){
            cout<<i<<" "<<(*it).first<<endl;
        }
    } */

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    stack<int> *myStack = new stack<int>();
    vector<int> members;


        pathBFS(search,key,row,column,myfile);



   /* int maxWeight=key[u];
    while(!yourStack->empty()){

        int u=yourStack->top();
        cout<<u<<endl;
        if(key[u]>maxWeight){
            maxWeight=key[u];
        }
        yourStack->pop();
    }
    cout<<maxWeight; */

}







void WeightedGraph::pathBFS(int search[],vector<int> key,int row,int column,ofstream &myfile) {
    vector <int> dist(this->V,0);
    vector <int> parent(this->V,-1);
    vector <bool> visited(this->V,false);
    queue<int> Q;
    int m=search[0];
    m=m-1;
    m=m*row;
    m=m+search[1];
    m=m-1;
    dist[m] = 0;
    int n=search[2]-1;
    n=n*row;
    n=n+search[3];
    n=n-1;

    visited[m] = true;
    Q.push(m);
    list<pair<int,int> >::iterator it;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        visited[u]=true;
       if(u == n){
            //cout<<dist[u];
            myfile<<dist[u];
            return;
        }

        for(it = adjMST[u].begin();it!=adjMST[u].end();++it){
            int v = (*it).first;
            if(!visited[v]){
                if((*it).second>dist[u]){
                    dist[v]=(*it).second;
                }
                else{
                    dist[v]=dist[u];
                }


                parent[v] = u;
                visited[v] = true;
                Q.push(v);
            }
        }
    }

   /*int k=parent[u];
    while(k!=z){
        if(parent[k]=z){
            cout<<dist[parent[k]]<<" ";
            k=parent[k];
        }
        else{
            k=parent[k];
        }
    }
    int m=parent[a];
    while(m!=b){
        if(parent[m]=b){
            cout<<dist[parent[m]]<<" ";
            m=parent[m];
        } else{
            m=parent[m];
        }
    } */

}


/*int WeightedGraph::shortestPath2(int **grid, int row, int col,int beginx,int beginy,int targetx,int targety) {

    int dis[row][col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            dis[i][j] = INT_MAX;
    int disx[] = {-1, 0, 1, 0};
    int disy[] = {0, 1, 0, -1};
    priority_queue<WeightedGraph, vector<WeightedGraph>,comp<WeightedGraph>> distanceQ;
    distanceQ.push(WeightedGraph(beginx,beginy,0));
    dis[beginx][beginy]=0;
    while(!distanceQ.empty()){
        WeightedGraph g1= distanceQ.top();
        distanceQ.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = g1.x + disx[i];
            int y = g1.y + disy[i];


            if (!isInLimit(x, y,row,col)) {
                continue;
            }


          int a=grid[x][y]-grid[g1.x][g1.y];
          int b=abs(a);
          if(dis[x][y]>b){
              dis[x][y]=b;
              distanceQ.push(WeightedGraph(x,y,b));
          }


        }

        }
    return dis[targetx-1][targety-1];




}
*/





