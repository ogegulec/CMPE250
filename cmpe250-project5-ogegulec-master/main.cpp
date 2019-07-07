#include "Search.h"


template<class Container>
void splitter(const string& str, Container& cont){
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),back_inserter(cont));
}




int main(int argc,char* argv[]) {
    clock_t tStart=clock();
    ifstream infile(argv[1]);
    char *out = argv[2];
    ofstream myfile;
    string line1;
    string line3;
    if (!infile.is_open())
        cout << "Could not open file\n";
    //getline(infile, line1);
    infile>>line1;
    myfile.open(out);

    vector<string> data;
    data.clear();
    string line2;
    //getline(infile, line2);
    infile>>line2;
    splitter(line2, data);
    int a=stoi(data[0]);
    string dict[a];
    for(int i=0; i<a; i++){
        data.clear();
        //getline(infile, dict[i]);
        infile>>dict[i];

    }



        Search s1(line1.size()+1);
        for(int i=0; i<a; i++){
            s1.find(dict[i],line1,101);
        }
      s1.calculate(line1.size()+1,myfile);


   // printf("time taken: %.4fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    myfile.close();


    return 0;
}
