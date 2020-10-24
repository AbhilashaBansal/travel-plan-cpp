#include <fstream>
#include <iostream>
#include <map>
#include <cstring>
#include "graphs.h"
#include "customers.h"
#include "admin.h"
#include <cstdlib>
#include <stdlib.h>
using namespace std;

//global variables
Admin Ad[3];
Agent Ag[15];
map <string, int> m;
Trie CT;
GraphInt cost_graph;
GraphFloat time_graph;
map<string, string> parent;
map<string, int> dist;
Plan P[10];
bool admin_logged_in = false;

void enter(); //forward declaration 

void initLocations(){
    string locations[50] = {
        "Delhi", "Mumbai", "Hongkong", "Tokyo", "Bangkok", "Singapore", "Sydney (Australia)", "Melbourne (Australia)",
        "Dubai", "Cairo", "Moscow", "Stockholm", "Seoul", "Canada", "San Francisco (USA)",
        "Washington DC (USA)", "LA (USA)", "Chicago (USA)", "New York (USA)", "Cape Town (South Africa)", "Rio (Brazil)", "Santiago", "Mexico City",
        "Peru", "Miami (USA)", "London", "Berlin (Germany)", "Rome", "Paris", "Spain", "Havana"
    };
    for(int i=0; locations[i]!=""; i++){
        m[locations[i]] = 1;
    }
    cout<<"Initiated locations map\n";
}

void print_path(string dest){
    if(parent[dest]==dest){
        cout<<dest<<"-->";
        return;
    }
    print_path(parent[dest]);
    cout<<dest<<"-->";
}

// -------------- Admin Portal -------------------
void visit_admin_portal(){
    //create login fn
    bool success = admin_logged_in || login_admin(Ad,2);
    if(success){
        admin_logged_in = true;
        system("clear");
        cout<<"WELCOME TO ADMIN PORTAL\n";
        int x;
        cout<<"1: Add a Location\n";
        cout<<"2: View all Customers\n";
        cout<<"3: View all Bookings\n";
        cout<<"4: Navigate back\n";
        cout<<"5: Exit\n";
        cin>>x;
        switch(x){
            case 1: {
                system("clear");
                add_edge(cost_graph, time_graph);
                cout<<"\nPress any key, followed by 'enter' key, to navigate back.\n";
                char c;
                cin>>c;
                visit_admin_portal();
                break;
            }
            case 2: {
                system("clear");
                view_all_customers();
                cout<<"Press any key, followed by 'enter' key, to navigate back.\n";
                char c;
                cin>>c;
                visit_admin_portal();
                break;
            }
            case 3: {
                view_all_bookings();
                cout<<"Press any key, followed by 'enter' key, to navigate back.\n";
                char c;
                cin>>c;
                visit_admin_portal();
                break;
            }
            case 4: {
                system("clear");
                admin_logged_in = false;
                enter();
                break;
            }
            case 5: {
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

bool book_custom(Booking &B, string dest); 

// -------FINDING A CUSTOM PLAN BASIS SINGLE LOCATION-----------
void find_a_plan(){
    system("clear");
    string dest;
    cout<<"Enter the name of a destination in correct format, to find a plan: ";
    cin.ignore();
    getline(cin, dest);

    if(m.count(dest)==0){
        cout<<"Location not found!!\n";
        cout<<"Redirecting you back, press any key followed by 'Enter' to proceed.\n";
        char c;
        cin>>c;
        visit_customer_portal();
        return;
    }
    else{
        cout<<"Flight cost: "<<dist[dest]<<endl;
        cout<<"The minimum cost plan is for: "<<(2*dist[dest])+20000<<"INR.\n";
        print_path(dest);
        cout<<endl;
        cout<<"1: Book this plan\n";
        cout<<"2: Enter another destination\n";
        cout<<"3: Navigate back\n";
        int choice;
        cin>>choice;
        if(choice==1){
            //add booking code here
            Booking B1;
            bool done = book_custom(B1, dest);
            if(done){
            system("clear");
            cout<<"BOOKING CONFIRMED\n";
            cout<<"Your agent will get in touch with you soon!\n";
            B1.printBooking();
            cout<<"\nRedirecting you back, press any key followed by 'Enter' to proceed.\n";
            char c;
            cin>>c;
            visit_customer_portal();
            return;
            }
            else{
                cout<<"\nSome error occured. Booking not done. Please try again.\n";
                cout<<"Redirecting you back, press any key followed by 'Enter' to proceed.\n";
                char c;
                cin>>c;
                visit_customer_portal();
                return;
            }

        }
        else if(choice==2){
            find_a_plan();
            return;       
        }
        else {
            visit_customer_portal();
            return;
        }
    }
    return;
}

// ------------- Booking Functionality -----------------
bool book_premade_package(Plan P, Booking &B){
    system("clear");
    cin.clear();
    fflush(stdin);
    string email;
    cout<<"PS: You need to have a valid customer account to make a booking.\n";
    cout<<"If you dont have an account press any key followed by 'enter', and you'd be redirected.\n";
    cout<<"Enter your email: \n";
    getline(cin, email);
    bool exists = CT.search(email);
    if(exists){
        cout<<"Enter your name: ";
        getline(cin, B.cust_name);
        B.cust_email = email;
        int i=0;
        for(string s: P.l){
            strcpy(B.places[i], s.c_str());
            i++;
        }
        //B.places = P.l;
        //B.agent_name = assign_Agent(Ag, 10);
        cout<<"Enter preferred date of travel: ";
        getline(cin, B.date);
        cout<<"Enter no of people: ";
        cin>>B.no_of_people;
        B.amount = (P.cost)*B.no_of_people;
        fstream f1;
        f1.open("bookings.txt", ios::app);
        f1.write( (char*)&B, sizeof(B) );
        f1.close();
    }
    else{
        cout<<"Create a valid account to make the booking.\n";
        return false;
    }
    return true;
}

bool book_custom(Booking &B, string dest){
    system("clear");
    cin.clear();
    fflush(stdin);
    string email;
    cout<<"PS: You need to have a valid customer account to make a booking.\n";
    cout<<"If you dont have an account press any key followed by 'enter', and you'd be redirected.\n";
    cout<<"Enter your email: \n";
    getline(cin, email);
    bool exists = CT.search(email);
    if(exists){
        cout<<"Enter your name: ";
        getline(cin, B.cust_name);
        B.cust_email = email;
        strcpy(B.places[0], dest.c_str());
        B.agent_name = assign_Agent(Ag, 10);
        cout<<"Enter preferred date of travel: ";
        getline(cin, B.date);
        cout<<"Enter no of people: ";
        cin>>B.no_of_people;
        int cost = (dist[dest]*2) + 20000;
        B.amount = (cost)*B.no_of_people;
        fstream f1;
        f1.open("bookings.txt", ios::app);
        f1.write( (char*)&B, sizeof(B) );
        f1.close();
    }
    else{
        cout<<"Create a valid account to make the booking.\n";
        return false;
    }
    return true;
}

// --------Book one of those pre-existing packages-----------
void book_a_package(){
    cout<<"................AVAILABLE PLANS.....................\n";
    for(int i=0; i<10; i++){
        //displaying available packages
        cout<<i+1<<" "<<P[i].name_of_plan<<endl;
        cout<<"Price per person: "<<P[i].cost<<endl;
        cout<<"No of days: "<<P[i].no_of_days;
        cout<<"Places: ";
        for(string s: P[i].l){
            cout<<s<<" ";
        }
        cout<<"\n\n";
    }
    cout<<"1: Book one of these plans\n";
    cout<<"2: Navigate back\n";
    int c;
    cin>>c;
    if(c==1){
        int choice;
        cout<<"Enter the no of the plan you want to book: ";
        cin>>choice;
        Booking B1;
        bool done = book_premade_package(P[choice-1], B1);
        cout<<"Here\n";
        if(done){
            system("clear");
            cout<<"BOOKING CONFIRMED\n";
            cout<<"Your agent will get in touch with you soon!\n";
            B1.printBooking();
            cout<<"\nRedirecting you back, press any key followed by 'Enter' to proceed.\n";
            char c;
            cin>>c;
            visit_customer_portal();
            return;
        }
        else{
            cout<<"\nSome error occured. Booking not done. Please try again.\n";
            cout<<"Redirecting you back, press any key followed by 'Enter' to proceed.\n";
            char c;
            cin>>c;
            visit_customer_portal();
            return;
        }
    }
    else{
        visit_customer_portal();
        return;
    }
}

//Customer Login
bool customer_login(string &email){
    string a, password;
    cout<<"Enter your email: ";
    cin>>a;
    email = a;
    cout<<"Enter password: ";
    cin>>password;
    fstream f1;
    f1.open("customers.txt", ios::in);
    Customer C;
    bool p=false;
    while(!f1.eof()){
        f1.read( (char*)&C, sizeof(Customer) );
        if(C.email==email && C.password==password){
            p = true;
            break;
        }
    }
    f1.close();
    return p;
}

// -------------- Customer Portal -----------------
void visit_customer_portal(){
    system("clear");
    int x;
    cout<<"1: Create an account\n";
    cout<<"2: View all locations\n";
    cout<<"3: Find a Plan\n";
    cout<<"4: Book a Package\n";
    cout<<"5: View your Bookings\n";
    cout<<"6: Navigate back\n";
    cout<<"7: Exit\n";
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
                cout<<p.first<<"  ";
            }
            char x;
            cout<<"\nPress any key, followed by 'enter' key, to navigate back.\n";
            cin>>x;
            cin.clear();
            fflush(stdin);
            visit_customer_portal();
            break;
        }
        case 3: {
            find_a_plan();
            break;
        }
        case 4: {
            book_a_package();
            break;
        }
        case 5: {
            system("clear");
            string email;
            bool login_success = customer_login(email);
            if(login_success){
                int bookings;
                fstream f1;
                f1.open("bookings.txt", ios::in);
                Booking B;
                f1.read( (char*)&B, sizeof(Booking) );
                while(!f1.eof()){
                    if(B.cust_email==email){
                        bookings++;
                        B.printBooking();
                        cout<<endl;
                    }
                    f1.read( (char*)&B, sizeof(Booking) );
                }
                if(bookings==0){
                    cout<<"No bookings found for this account!\n";
                }
                f1.close();
                cout<<"Press any key followed by 'enter' to navigate back.\n";
                char c;
                cin>>c;
                visit_customer_portal();
            }
            else{
                cout<<"Login failed. Please try again.\n";
                cout<<"Redirecting you. Press any key followed by 'enter' to continue.\n";
                char c;
                cin>>c;
                visit_customer_portal();
            }
            break;
        }
        case 6: {
            enter();
            break;
        }
        case 7: {
            system("clear");
            cout<<"Thank you for using the Travel Plan Management Software!\n";
            cout<<"Built by ABHILASHA BANSAL & ABHAY GUPTA\n";
            cout<<"Exitting now ...\n";
            break;
        }
        default: {
            cout<<"Invalid Input\n";
            cout<<"Redirecting you back, press any key followed by 'Enter' to proceed.\n";
            char c;
            cin>>c;
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

    while(!f1.eof()){
        edges++;
        f1.read( (char*)&E1, sizeof(E1) );
        cost_graph.addEdge(E1.dest_1, E1.dest_2, E1.cost);
        //cout<<"COOL ";
    }
    cout<<"Graphs initiated, "<<edges<<" edges created!\n";
    f1.close();
}

int main(){
    system("clear");
    srand (time(NULL));
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
    dijk_cost("Delhi", parent, dist, cost_graph.m);
    cout<<endl;
    initPlans(P, 10);

    char x;
    cout<<"Press any key, followed by 'enter' key, to start program.\n";
    cin>>x;
    cin.clear();
    fflush(stdin);
    enter();
    
    //add more code
    return 0;
}