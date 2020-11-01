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
    int time;
    Edge(){
        strcpy(dest_1, "Delhi");
        strcpy(dest_2, "China");
        cost=0;
        time = 0;
    }
    Edge(char a[], char b[], int c=0, int t=0){
        strcpy(dest_1,a);
        strcpy(dest_2, b);
        cost = c;
        time = t;
    }
    void init(char a[], char b[], int c, int t){
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
    void addEdge(char* x, char* y, int wt){
        string y1(y);
        string x1(x);
        m[x].push_back(make_pair(y1, wt));
        m[y].push_back(make_pair(x1, wt));
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

// ------------ PRE EXISTING PLANS --------------
class Plan{
    public:
    string name_of_plan;
    int cost;
    int no_of_days;
    list <string> l;
};

void initPlans(Plan P[], int n){
    P[0].name_of_plan = "Europian Dream";
    P[0].cost = 128000;
    P[0].no_of_days = 7;
    P[0].l.push_back("London");
    P[0].l.push_back("Paris");
    P[0].l.push_back("Rome");

    P[1].name_of_plan = "Europian Special";
    P[1].cost = 85000;
    P[1].no_of_days = 8;
    P[1].l.push_back("London");
    P[1].l.push_back("Paris");
    P[1].l.push_back("Switzerland");

    P[2].name_of_plan = "Europian Tour";
    P[2].cost = 160000;
    P[2].no_of_days = 8;
    P[2].l.push_back("London");
    P[2].l.push_back("Berlin");
    P[2].l.push_back("Prague");
    P[2].l.push_back("Zurich");

    P[3].name_of_plan = "Spanish Delight";
    P[3].cost = 50000;
    P[3].no_of_days = 6;
    P[3].l.push_back("Madrid");
    P[3].l.push_back("Barcelona");
    P[3].l.push_back("Valencia");

    P[4].name_of_plan = "Japan in Style";
    P[4].cost = 145000;
    P[4].no_of_days = 6;
    P[4].l.push_back("Tokyo");
    P[4].l.push_back("Seoul");

    P[5].name_of_plan = "Asian Adventures";
    P[5].cost = 125000;
    P[5].no_of_days = 6;
    P[5].l.push_back("Tokyo");
    P[5].l.push_back("Manila");
    P[5].l.push_back("Singapore");

    P[6].name_of_plan = "Australian Holiday";
    P[6].cost = 155000;
    P[6].no_of_days = 9;
    P[6].l.push_back("Melbourne");
    P[6].l.push_back("Sydney");
    P[6].l.push_back("Gold Coast");
    P[6].l.push_back("Adelaide");

    P[7].name_of_plan = "South America Highlights";
    P[7].cost = 95000;
    P[7].no_of_days = 8;
    P[7].l.push_back("Rio");
    P[7].l.push_back("Argentina");
    P[7].l.push_back("Santiago");
    P[7].l.push_back("Iguazu Falls");
    
    P[8].name_of_plan = "East Cost, USA";
    P[8].cost = 105000;
    P[8].no_of_days = 6;
    P[8].l.push_back("New York");
    P[8].l.push_back("Washington DC");
    P[8].l.push_back("Niagra Falls");
    
    P[9].name_of_plan = "USA Super Plan";
    P[9].cost = 250000;
    P[9].no_of_days = 11;
    P[9].l.push_back("New York");
    P[9].l.push_back("New Jersey");
    P[9].l.push_back("Washington DC");
    P[9].l.push_back("Niagra Falls");
    P[9].l.push_back("Las Vegas");
    P[9].l.push_back("Los Angeles");

    cout<<"Initialised Tour Plans\n";
}

// ---------- DIJKSTRA'S ALGORITHM FOR MINIMUM COST PLAN ----------
void dijk_cost(string src, map <string, string> &parent, map <string, int> &dist, map <string, list< pair <string, int> > > &m){
    
    for(auto p: m){
        dist[p.first] = INT_MAX; //initializing distances to inf initially
    }

    dist[src] = 0;
    set <pair<int, string> > s; //to maintain & find next vertex at min distance
    s.insert(make_pair(0, src));
    parent[src] = src;

    while(!s.empty()){
        auto p = *(s.begin());
        string place = p.second;
        int node_dist = p.first;

        //we've finalised this node at this point
        s.erase(s.begin());

        //we'll run the algorithm once, and store the min distance to all nodes, from 'Delhi'

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

}


