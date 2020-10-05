#include <fstream>
#include "graphs.h"
#include "customers.h"
#include "admin.h"
using namespace std;

void visit_admin_portal(){
    cout<<"This portal is still under development.\n";
}

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
            break;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        case 4: {
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            system("clear");
            cout<<"Thank you for using the Travel Plan Management Software!\n";
            cout<<"Exitting now ...\n";
            break;
        }
        default: {
            cout<<"Invalid Input\n";
            visit_customer_portal();
        }
    }
}
void enter(){
    int a;
    system("clear");
    cout<<"1: Go to Admin Portal\n";
    cout<<"2: Go to User Portal\n";
    cout<<"3: Exit\n";
    cin>>a;
    switch(a){
        case 1: {
            break; //add code
        }
        case 2: {
            visit_customer_portal();
            break;
        }
        case 3: {
            system("clear");
            cout<<"Thank you for using the Travel Plan Management Software!\n";
            cout<<"Exitting now ...\n";
            break;
        }
        default: {
            cout<<"Invalid Input\n";
            enter();
        }
    }
}
int main(){
    Agent A[11];
    Admin Ad[3];
    initAdmins(Ad);
    initAgents(A);
    enter();
    return 0;
}