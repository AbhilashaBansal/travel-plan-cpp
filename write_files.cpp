#include <fstream>
#include "graphs.h"
#include "customers.h"
#include "admin.h"
using namespace std;

int main(){
    Agent A[10];
    A[0].add_details("Amit Aggarwal", "amit@gmail.com", "9898171722");
    A[1].add_details("Elena", "elena@gmail.com", "9616757520");
    A[2].add_details("Rahul Gupta", "rahulg@gmail.com", "8484565630");
    A[3].add_details("Kavya Gupta", "kavya@mail.com", "7878454590");
    A[4].add_details("Anastasia", "ana_st@gmail.com", "8736028383");
    A[5].add_details("Abhimanyu Jain", "abhimanyu@mail.com", "8498238322");
    A[6].add_details("Thomas Gray", "tommo@gmail.com", "5588909012");
    A[7].add_details("Alisha Das", "alisha_das@gmail.com", "8347823828");
    A[8].add_details("D Hardman", "daniel@gmail.com", "7777893434");
    A[9].add_details("Mia Kapoor", "mia_k@gmail.com", "8534999900");

    fstream f1;
    f1.open("agents.txt", ios::out);
    
    for(int i=0; i<=9; i++){
        f1.write( (char*)&A[i], sizeof(A[i]) );
    }
    f1.close();

    Admin Ad[2];
    Ad[0].add_admin("Abhilasha Bansal", "abhilashabansal529@gmail.com", "8368658081", "12345abcde");
    Ad[1].add_admin("Abhay Gupta", "abhay_gupta@gmail.com", "9999999911", "abhaygupta");
    fstream f2;
    f2.open("admins.txt", ios::out);
    for(int i=0; i<=1; i++){
        f2.write( (char*)&Ad[i], sizeof(Ad[i]) );
    }
    f2.close();
    return 0;
}