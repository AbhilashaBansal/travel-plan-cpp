#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;

class Edge{
    public:
    string dest_1, dest_2;
    int cost;
    float time;
    Edge(string a="", string b="", int c=0, float t=0.00){
        dest_1 = a;
        dest_2 = b;
        cost = c;
        time = t;
    }
    void init(string a, string b, int c, float t){
        dest_1 = a;
        dest_2 = b;
        cost = c;
        time = t;
    }
};

class Graph{
    public:
    int v;
    map<string, list< pair <string, int> > > m;
    void addEdge(string x, string y, int wt){
        m[x].push_back(make_pair(y, wt));
        m[y].push_back(make_pair(x, wt));
    }
};

//DIJKSTRA'S ALGORITHM FOR MINIMUM COST PLAN
int dijk_cost(string src, string dest, vector <string> &path){
    //
    return 1;
}


//DIJKSTRA'S ALGORITHM FOR MINIMUM TIME PLAN
float dijk_time(string src, string dest, vector <string> &path){
    //
    return 1.0;
}
