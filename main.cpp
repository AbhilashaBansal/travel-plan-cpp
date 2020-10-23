#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include "graphs.h"
#include "customers.h"
#include "admin.h"
#include <cstdlib>
using namespace std;

//global variables
Admin Ad[3];
Agent Ag[15];
map <string, int> m;
Trie CT;
GraphInt cost_graph;
GraphFloat time_graph;
bool admin_logged_in = false;

void enter(); //forward declaration 

void initLocations(){
    string locations[50] = {
        "Delhi", "Mumbai", "Hongkong", "Tokyo", "Bangkok", "Singapore", "Sydney", "Melbourne",
        "Dubai", "Cairo", "Moscow", "Stockholm", "Seoul", "Canada", "Shanghai", "Beijing", "San Francisco",
        "Washington DC", "Los Angeles", "Chicago", "New York", "South Africa", "Rio", "Santiago", "Mexico",
        "Peru", "Miami", "London", "Germany", "Italy", "Paris"
    };
    for(int i=0; locations[i]!=""; i++){
        m[locations[i]] = 1;
    }
    cout<<"Initiated locations map\n";
}

//Admin Portal
void visit_admin_portal(){
    //create login fn
    bool success = admin_logged_in || login_admin(Ad,2);
    if(success){
        admin_logged_in = true;
        system("clear");
        cout<<"WELCOME TO ADMIN PORTAL\n";
        int x;
        cout<<"1: Add a Location\n";
        cout<<"2: Add an Agent\n";
        cout<<"3: View all Customers\n";
        cout<<"4: View all Bookings\n";
        cout<<"5: Navigate back\n";
        cout<<"6: Exit\n";
        cin>>x;
        switch(x){
            case 3: {
                system("clear");
                view_all_customers();
                cout<<"Press any key, followed by 'enter' key, to navigate back.\n";
                char c;
                cin>>c;
                visit_admin_portal();
                break;
            }
            case 5: {
                system("clear");
                admin_logged_in = false;
                enter();
                break;
            }
            case 6: {
                system("clear");
                admin_logged_in = false;
                cout<<"Thank you for using the Travel Plan Management Software!\n";
                cout<<"Built by ABHILASHA BANSAL & ABHAY GUPTA\n";
                cout<<"Exitting now ...\n";
                break;
            }
            default: {
                cout<<"Invalid Input\n";
                enter();
            }
        }
        
    }
    else{
        cout<<"Login failed, please enter correct details again.\n";
        cout<<"Press any key, followed by 'enter' key, to navigate back.\n";
        char c;
        cin>>c;
        enter();
    }
    //cout<<"This portal is still under development.\n";
}

//Customer Portal
void visit_customer_portal(){
    system("clear");
    int x;
    cout<<"1: Create an account\n";
    cout<<"2: View all locations\n";
    cout<<"3: Find a Plan\n";
    cout<<"4: View your Bookings\n";
    cout<<"5: Navigate back\n";
    cout<<"6: Exit\n";
    cin>>x;
    switch(x){
        case 1: {
            bool p = createAccount(CT);
            visit_customer_portal();
            break;
        }
        case 2: {
            system("clear");
            cout<<"AVAILABLE LOCATIONS\n";
            for(auto p: m){
                cout<<p.first<<endl;
            }
            char x;
            cout<<"Press any key, followed by 'enter' key, to navigate back.\n";
            cin>>x;
            cin.clear();
            fflush(stdin);
            visit_customer_portal();
            break;
        }
        case 3: {
            system("clear");
            string dest;
            cout<<"Enter the name of a destination in correct format: ";
            cin>>dest;
            map<string, string> parent;
            int cost = dijk_cost("Delhi", dest, parent, cost_graph.m);
            if(cost==-1){
                cout<<"Location not found!!\n";
                cout<<"Redirecting you back, press any key followed by 'Enter' to proceed.\n";
                char c;
                cin>>c;
                visit_customer_portal();
            }
            else{
                cout<<"The minimum cost plan is for: "<<cost<<"INR.\n";
            }
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            enter();
            break;
        }
        case 6: {
            system("clear");
            cout<<"Thank you for using the Travel Plan Management Software!\n";
            cout<<"Built by ABHILASHA BANSAL & ABHAY GUPTA\n";
            cout<<"Exitting now ...\n";
            break;
        }
        default: {
            cout<<"Invalid Input\n";
            visit_customer_portal();
        }
    }
}

//Entry Point
void enter(){
    int a;
    system("clear");
    cout<<"1: Go to Admin Portal\n";
    cout<<"2: Go to User Portal\n";
    cout<<"3: Exit\n";
    cin>>a;
    switch(a){
        case 1: {
            visit_admin_portal();
            break; 
        }
        case 2: {
            visit_customer_portal();
            break;
        }
        case 3: {
            system("clear");
            cout<<"Thank you for using the Travel Plan Management Software!\n";
            cout<<"Built by ABHILASHA BANSAL & ABHAY GUPTA\n";
            cout<<"Exitting now ...\n";
            break;
        }
        default: {
            cout<<"Invalid Input\n";
            enter();
        }
    }
}

//Init cost and time graphs after reading places.txt
void initGraphs(){
    //add code
    int edges=0;
    Edge E1;
    fstream f1;
    f1.open("places.txt", ios::in);
    f1.read( (char*)&E1, sizeof(E1) );
    cost_graph.addEdge(E1.dest_1, E1.dest_2, E1.cost);
    edges++;
    while(!f1.eof()){
        f1.read( (char*)&E1, sizeof(E1) );
        cost_graph.addEdge(E1.dest_1, E1.dest_2, E1.cost);
        //cout<<"COOL ";
        edges++;
    }
    cout<<"Graphs initiated, "<<edges<<" edges created!\n";
    f1.close();
}

int main(){
    
    //initialising admins
    initAdmins(Ad);

    int agent_count;
    //initialising travel agents
    initAgents(Ag, agent_count);
    cout<<agent_count<<" agents found!\n";
    cout<<Ag[0].name<<endl;

    //initialising available travel locations
    initLocations();
    for(auto p: m){
        cout<<p.first<<" ";
    }
    cout<<endl;

    cout<<&(CT)<<endl;
    //initialisng customers
    initCustomers(CT);

    //Initialising cost & time graphs
    initGraphs();
    map <string, string> parent;
    string child = "London";
    cout<<dijk_cost("Delhi", child, parent, cost_graph.m)<<endl;
    
    while(parent[child]!="Delhi"){
        cout<<child<<"<--";
        child = parent[child];
    }
    cout<<endl;
    vector <string> w;
    cout<<dijk_time("Delhi", "London", w, time_graph.m)<<endl;
    for(string s: w){
        cout<<s<<" ";
    }
    cout<<endl;
    char x;
    cout<<"Press any key, followed by 'enter' key, to start program.\n";
    cin>>x;
    cin.clear();
    fflush(stdin);
    enter();
    
    //add more code
    return 0;
}