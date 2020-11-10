#include <fstream>
#include <iostream>
#include <cstring>
#include <list>
#include <unordered_map>
#include <cstdlib>
using namespace std;

void visit_customer_portal();
// ----------------TRIE--------------------
//Trie for storing customer emails
class trie_node{
    public:
    char data;
    unordered_map <char, trie_node*> children;
    bool terminal;
    trie_node(char d){
        data = d;
        terminal = false;
    }
};

class Trie{
    public:
    trie_node* root;
    int customer_count;
    Trie(){
        root = new trie_node('\0');
        customer_count = 0;
    }
    
    //insert a record into trie
    void insert(string email){
        trie_node* temp = root;
        for(int i=0; email[i]!='@'; i++){
            if(email[i]=='\0'){
                break;
            }
            char ch = email[i];
            if(temp->children.count(ch)){
                //character exists in trie already
                temp = temp->children[ch];
            }
            else{
                trie_node* n = new trie_node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
        customer_count++;
    }

    //search a record (with email)
    bool search(string email){
        trie_node* temp = root;
        for(int i=0; email[i]!='@'; i++){
            if(email[i]=='\0'){
                break;
            }
            char ch = email[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            temp = temp->children[ch];
        }
        return temp->terminal?true:false;
    }
};

// -------------------CUSTOMERS----------------------
class Customer{
    public:
    char name[30] = {'\0'};
    char address[30] = {'\0'};
    char email[50] = {'\0'};
    char phone_no[15] = {'\0'};
    char password[20] = {'\0'};
    Customer(){
        //name = address = email = phone_no = password = "";
    }
    Customer(string a, string b, string c, string d, string e){
        strcpy(name, a.c_str());
        strcpy(address, b.c_str());
        strcpy(email, c.c_str());
        strcpy(phone_no, d.c_str());
        strcpy(password, e.c_str());
    }
};

void initCustomers(Trie T){
    fstream f1;
    Customer C;

    f1.open("customers.txt", ios::in||ios::binary);
    //int i=0;
    do{
        f1.read( (char*)&C, sizeof(Customer) );
        string email = C.email;
        T.insert(email);
        //i++;
    }while(!f1.eof());
    cout<<"Initiated customer trie\n";
    f1.close();
}

// ---------- create account ------------
bool createAccount(Trie &T){
    system("clear");
    cin.clear();
    fflush(stdin);

    string name, address, email, phone, password;
    cout<<"Enter name: \n";
    getline(cin, name);
    cout<<"Enter address: \n";
    getline(cin, address);
    cout<<"Enter email: \n";
    getline(cin, email);
    cout<<"Enter phone number: \n";
    getline(cin, phone);
    cout<<"Enter password: \n";
    getline(cin, password);

    //check if email already exists
    bool p = T.search(email);
    if(p){
        cout<<"An account with this email already exists. Please choose a different email.\n";
        cout<<"Directing you back to the customer portal...\n";
        //system("clear");
        char c;
        cout<<"Press any key, followed by 'enter' key, to continue.\n";
        cin>>c;
        return false;
    }

    //new entry
    //initializing customer object
    Customer C1(name, address, email, phone, password);

    //writing customer details in file 'customers.txt'
    fstream f1;
    f1.open("customers.txt", ios::app||ios::binary);
    f1.write( (char*)&C1, sizeof(C1) );
    f1.close();

    T.insert(email);
    system("clear");
    cout<<"Successfully created customer account.\n";
    cout<<"Directing you back to the customer portal...\n";
    char c;
    cout<<"Press any key, followed by 'enter' key, to continue.\n";
    cin>>c;
    //system("clear");
    return true;
}

// --------------- BOOKINGS -------------------
class Booking{
    public:
    char cust_name[30];
    char cust_email[50];
    char date[20];
    char places[10][30]={"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    int amount;
    int no_of_people;
    char agent_name[30];

    Booking(){
        //places = {"\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0", "\0"};
    }

    void initBooking(string name, string email, string d, list <string> p, float a, int n, string agent){
        strcpy(cust_email, email.c_str());
        strcpy(cust_name, name.c_str());
        strcpy(date, d.c_str());
        //places = p;
        amount = a;
        no_of_people = n;
        strcpy(agent_name, agent.c_str());
    }
    void printBooking(){
        cout<<"Customer Name: "<<cust_name<<endl;
        cout<<"Customer Email: "<<cust_email<<endl;
        cout<<"Date of Booking: "<<date<<endl;
        cout<<"Places included in Trip: ";
        for(int i=0; i<10; i++){
            if(places[i]!='\0'){
                cout<<places[i]<<" ";
            }
        }
        cout<<"\nNo of people on trip: "<<no_of_people<<endl;
        cout<<"Total amount for Trip: "<<amount<<endl;
        cout<<"Agent Name: "<<agent_name<<endl;
    }
};