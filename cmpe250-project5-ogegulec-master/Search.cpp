//
// Created by ege onur güleç on 20.12.2018.
//
#include "Search.h"
Search::Search(int a) {

    adjList=new list<int>[a];

}
void Search:: find(string pat, string txt, int q)
{
    int M = pat.size();
    int N = txt.size();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;

    // Calculate the hash value of pattern and first
    // window of text
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Check the hash values of current window of text
        // and pattern. If the hash values match then only
        // check for characters on by one
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M){
                //printf("Pattern found at index %d \n", i);
                //cout<<i+pat.size()<<endl;
                int m=i+pat.size();

                adjList[i].push_back(m);
            }

        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
                t = (t + q);
        }


    }

}
void Search::calculate(int a,ofstream &myfile) {
    long long int arr[a];
    for(int i=0; i<a; i++){
        arr[i]=0;
    }
    arr[a-1]=1;
    long long int count=0;
    for(int i=a-1; i>=0; i-- ){
        list<int>::iterator it;
        for(it=adjList[i].begin(); it!=adjList[i].end(); it++){
            if((*it)!=NULL){
                arr[i]=(arr[i]+arr[*it])%1000000007;
            }
        }

    }
    //cout<<arr[0];
    myfile<<arr[0];
}
