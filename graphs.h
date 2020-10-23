#include <iostream>
#include <map>
#include <list>
#include <cstring>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

class Edge{
    public:
    char dest_1[30], dest_2[30];
    int cost;
    float time;
    Edge(char a[] = "Delhi", char b[] = "China", int c=0, float t=0.00){
        strcpy(dest_1,a);
        strcpy(dest_2, b);
        cost = c;
        time = t;
    }
    void init(char a[], char b[], int c, float t){
        strcpy(dest_1, a);
        strcpy(dest_2, b);
        cost = c;
        time = t;
    }
};

class GraphInt{
    public:
    int v;
    map<string, list< pair <string, int> > > m;
    void addEdge(string x, string y, int wt){
        m[x].push_back(make_pair(y, wt));
        m[y].push_back(make_pair(x, wt));
    }
};
class GraphFloat{
    public:
    int v;
    map<string, list< pair <string, float> > > m;
    void addEdge(string x, string y, float wt){
        m[x].push_back(make_pair(y, wt));
        m[y].push_back(make_pair(x, wt));
    }
};


//FIX PATH, ALSO FIX DIJK_TIME
//DIJKSTRA'S ALGORITHM FOR MINIMUM COST PLAN
int dijk_cost(string src, string dest, map <string, string> &parent, map <string, list< pair <string, int> > > &m){
    
    unordered_map <string, int> dist;
    for(auto p: m){
        dist[p.first] = INT_MAX; //initializing distances to inf initially
    }

    //char dest_ch[dest.length()+1];
    //strcpy(dest_ch, dest.c_str());
    dist[src] = 0;
    //path.push_back(src);

    set <pair<int, string> > s; //to maintain & find next vertex at min distance
    s.insert(make_pair(0, src));
    string par = src;
    while(!s.empty()){
        auto p = *(s.begin());
        string place = p.second;
        int node_dist = p.first;

        //we've finalised this node at this point
        s.erase(s.begin());
        //path.push_back(place);
        // parent[place] = par;
        // par = place;
        //char ch[place.length()+1];
        //strcpy(ch, place.c_str());

        if(place==dest){
            return dist[dest]; //already reached our req destination location 
        }

        for(auto child_pair: m[place]){
            int edge_wt = child_pair.second;
            if(node_dist + edge_wt < dist[child_pair.first]){
                string vertex = child_pair.first;
                auto f = s.find(make_pair(dist[vertex], vertex));
                if(f!=s.end()){
                    s.erase(f);
                }
                parent[vertex] = place;
                dist[vertex] = node_dist + edge_wt;
                s.insert(make_pair(dist[vertex], vertex));
            }
        }
    }

    //dest not found in graph
    return -1;
}


//DIJKSTRA'S ALGORITHM FOR MINIMUM TIME PLAN
float dijk_time(string src, string dest, vector <string> &path, map <string, list< pair <string, float> > > &m){
    
    unordered_map <string, float> time;
    for(auto p: m){
        time[p.first] = 100000.00; //initializing time to large value initially
    }

    time[src] = 0.00;
    //path.push_back(src);

    set <pair<float, string> > s; //to maintain & find next vertex at min distance
    s.insert(make_pair(0.00, src));

    while(!s.empty()){
        auto p = *(s.begin());
        string place = p.second;
        float node_time = p.first;

        //we've finalised this node at this point
        s.erase(s.begin());
        path.push_back(place);
        //char ch[place.length()+1];
        //strcpy(ch, place.c_str());

        if(place==dest){
            return time[dest]; //already reached our req destination location 
        }

        for(auto child_pair: m[place]){
            float edge_wt = child_pair.second;
            if(node_time + edge_wt < time[child_pair.first]){
                string vertex = child_pair.first;
                auto f = s.find(make_pair(time[vertex], vertex));
                if(f!=s.end()){
                    s.erase(f);
                }
                time[vertex] = node_time + edge_wt;
                s.insert(make_pair(time[vertex], vertex));
            }

        }
    }

    //dest not found in graph
    return -1.00;
}
