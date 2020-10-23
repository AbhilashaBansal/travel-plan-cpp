#include <fstream>
#include <iostream>
#include <cstring>
#include <list>
#include <unordered_map>
#include <cstdlib>
using namespace std;

void visit_customer_portal();
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

class Customer{
    public:
    string name;
    string address;
    string email;
    string phone_no;
    string password;
    Customer(){
        name = address = email = phone_no = password = "";
    }
    Customer(string a, string b, string c, string d, string e){
        name = a;
        address = b;
        email = c;
        phone_no = d;
        password = e;
    }
};

void initCustomers(Trie T){
    fstream f1;
    Customer C;

    f1.open("customers.txt", ios::in);
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
    f1.open("customers.txt", ios::app);
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

class Booking{
    public:
    string cust_name;
    string cust_email;
    string date;
    list <string> places;
    float amount;
    int no_of_people;
    string agent_name;
    Booking(string name, string email, string d, list <string> p, float a, int n, string agent){
        cust_email = email;
        cust_name = name;
        date = d;
        places = p;
        amount = a;
        no_of_people = n;
        agent_name = agent;
    }
    void printBooking(){
        cout<<"Customer Name: "<<cust_name<<endl;
        cout<<"Customer Email: "<<cust_email<<endl;
        cout<<"Date of Booking: "<<date<<endl;
        cout<<"Places included in Trip: ";
        cout<<"No of people on trip: "<<no_of_people<<endl;
        for(auto p: places){
            cout<<p<<" ";
        }
        cout<<endl;
        cout<<"Total amount for Trip: "<<amount<<endl;
        cout<<"Agent Name: "<<agent_name<<endl;
    }
};