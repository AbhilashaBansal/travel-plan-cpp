#include <iostream>
#include <fstream>
#include <cstring>
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
    bool login(string name, string password){
        if(name==this->name && this->password==password){
            cout<<"here\n";
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
    system("clear");
    cout<<"Enter name : ";
    cin.ignore();
    getline(cin, name);
    cout<<"Enter password : ";
    cin>>password;
    for(int i=0; i<no; i++){
        bool p = Ad[i].login(name, password);
        if(p){
            return true;
        }
    }
    return false;
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
    ifstream f1;
    f1.open("agents.txt", ios::in);
    int i=0;
    f1.read( (char*)&Ag[i], sizeof(Agent) );
    i++;
    while(!f1.eof()){
        f1.read( (char*)&Ag[i], sizeof(Agent) );
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

//view all customers
void view_all_customers(){
    int total_cust=0;
    ifstream f1;
    Customer C1;
    f1.open("customers.txt", ios::in);
    do{
        f1.read( (char*)&C1, sizeof(Customer) );
        cout<<C1.name<<" "<<C1.address<<" "<<C1.phone_no<<" "<<C1.email<<endl;
        total_cust++;
        //ERROR: LAST OBJECT IS BEING READ TWICE
        //Fix it
    }while(!f1.eof());
    cout<<"Total customers are: "<<total_cust<<endl;
    f1.close();
}