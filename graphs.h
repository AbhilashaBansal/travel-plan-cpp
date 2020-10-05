#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

class Graph{
    public:
    int v;
    map<string, list< pair <string, int> > > m;
    void addEdge(string x, string y, int wt){
        m[x].push_back(make_pair(y, wt));
        m[y].push_back(make_pair(x, wt));
    }
};