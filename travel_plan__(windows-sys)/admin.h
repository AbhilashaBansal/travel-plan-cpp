#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>
using namespace std;

// ------------------ADMIN FNS-----------------------
class Admin{
    char name[30];
    char email[50];
    char phone_no[20];
    char password[20];
    public:
    void add_admin(char* n, char* e, char* p, char* pass){
        strcpy(name, n);
        strcpy(email, e);
        strcpy(phone_no, p);
        strcpy(password, pass);
    }
    bool login(char* name, char* password){
        if(strcmp(name, this->name)==0 && strcmp(this->password,password)==0){
            //cout<<"here\n";
            return true;
        }
        return false;
    }
};

void initAdmins(Admin Ad[]){
    //add code
    ifstream f1;
    f1.open("admins.txt", ios::in);
    int i=0;
    while(!f1.eof()){
        f1.read( (char*)&Ad[i], sizeof(Admin) );
        i++;
    }
    cout<<"Admins information read\n";
    f1.close();
}

bool login_admin(Admin Ad[], int no=2){
    string name, password;
    system("cls");
    cout<<"Enter name : ";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter password : ";
    cin>>password;
    char name_1[30];
    char password_1[30];
    strcpy(name_1, name.c_str());
    strcpy(password_1, password.c_str());
    for(int i=0; i<no; i++){
        bool p = Ad[i].login(name_1, password_1);
        if(p){
            return true;
        }
    }
    return false;
}

// ----------------AGENTS-------------------
class Agent{
    public:
    char name[30];
    char email[50];
    char phone_no[20];
    public:
    Agent(string n="Alina", string e="a@mail.com", string p="9891002255"){
        strcpy(name, n.c_str());
        strcpy(email, e.c_str());
        strcpy(phone_no, p.c_str());
    }
    void add_details(string a, string b, string c){
        strcpy(name, a.c_str());
        strcpy(email, b.c_str());
        strcpy(phone_no, c.c_str());
    }
    string getName(){
        return name;
    }
};

void initAgents(Agent Ag[], int &agent_count){
    agent_count=0;
    ifstream f1;
    f1.open("agents.txt", ios::in);
    int i=0;
    f1.read( (char*)&Ag[i], sizeof(Agent) );

    while(!f1.eof()){
        i++;
        f1.read( (char*)&Ag[i], sizeof(Agent) );
    }
    cout<<"Agent details initiated\n";
    agent_count = i;
    f1.close();
}

string assign_Agent(Agent A[], int no=10){
    int c = rand()%(no-1);
    return A[c].getName();
}

// -----------------ADMIN FUNCTIONS------------------
//view all customers
void view_all_customers(){
    system("cls");
    int total_cust=0;
    ifstream f1;
    Customer C1;
    f1.open("customers.txt", ios::in);
    f1.read( (char*)&C1, sizeof(Customer) );
    
    while(!f1.eof()){
        cout<<C1.name<<" "<<C1.address<<" "<<C1.phone_no<<" "<<C1.email<<endl;
        total_cust++;
        f1.read( (char*)&C1, sizeof(Customer) ); 
        //cout<<C1.name<<" "<<C1.address<<" "<<C1.phone_no<<" "<<C1.email<<endl;
    }
    cout<<"Total customers are: "<<total_cust<<endl;
    f1.close();
}

//view all bookings
void view_all_bookings(){
    system("cls");
    int total_books=0;
    ifstream f1;
    Booking B1;
    f1.open("bookings.txt", ios::in);
    f1.read( (char*)&B1, sizeof(Booking) );
    while(!f1.eof()){
        B1.printBooking();
        cout<<endl;
        f1.read( (char*)&B1, sizeof(Booking) );
        total_books++;
    }
    cout<<"Total Bookings are: "<<total_books<<endl;
    f1.close();
}

class Edge;
class GraphInt;
class GraphFloat;
//forward declaration

bool add_edge(GraphInt &g1, GraphFloat &g2){
    char a[30], b[30];
    int cost;
    float time;
    cout<<"Enter place 1: ";
    cin.ignore();
    // cin.clear();
    // fflush(stdin);
    cin.getline(a, 30, '\n'); 
    cout<<"Enter place 2: ";

    cin.getline(b, 30, '\n'); 
    cout<<"Enter flight cost: ";
    cin>>cost;
    cout<<"Enter flight time: ";
    cin>>time;
    Edge E(a, b, cost, time);
    fstream f3;
    f3.open("places.txt", ios::app);
    f3.write( (char*)&E, sizeof(E) );
    f3.close();

    g1.addEdge(a, b, cost);
    g2.addEdge(a, b, time);
    cout<<"Place/Flight added successfully.\n";
    return true;
}