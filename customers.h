#include <fstream>
#include <cstring>
#include <list>
using namespace std;

class Customer{
    public:
    string name;
    string address;
    string email;
    string phone_no;
    string password;
    Customer(string a, string b, string c, string d, string e){
        name = a;
        address = b;
        email = c;
        phone_no = d;
        password = e;
    }
};

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