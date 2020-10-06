#include <cstring>
#include <iostream>
#include <fstream>
using namespace std;

class Admin{
    string name;
    string email;
    string phone_no;
    string password;
    public:
    void add_admin(string n, string e, string p, string pass){
        name = n;
        email = e;
        phone_no = p;
        password = pass; 
    }
};

void initAdmins(Admin Ad[]){
    //add code
    fstream f1;
    f1.open("admins.txt", ios::in);
    int i=0;
    while(!f1.eof()){
        f1.read( (char*)&Ad[i], sizeof(Ad[i]) );
        i++;
    }
    cout<<"Admins information read\n";
    f1.close();
}

class Agent{
    public:
    string name;
    string email;
    string phone_no;
    public:
    Agent(string n="Alina", string e="a@mail.com", string p="9891002255"){
        name = n;
        email = e;
        phone_no = p;
    }
    void add_details(string a, string b, string c){
        name = a;
        email = b;
        phone_no = c;
    }
    string getName(){
        return name;
    }
};

void initAgents(Agent Ag[], int &agent_count){
    //add code
    agent_count=0;
    fstream f1;
    f1.open("agents.txt", ios::in);
    int i=0;
    while(!f1.eof()){
        f1.read( (char*)&Ag[i], sizeof(Ag[i]) );
        i++;
    }
    cout<<"Agent details initiated\n";
    agent_count = i;
    f1.close();
}

string assign_Agent(Agent A[], int no){
    fstream f;
    int count;
    f.open("count.txt", ios::in);
    f.read( (char*)&count, sizeof(int) );
    count = (count+1)%no;
    f.write( (char*)&count, sizeof(int) );
    return A[count].getName();
}