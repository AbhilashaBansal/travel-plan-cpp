#include <iostream>
#include <fstream>
#include "graphs.h"
#include "customers.h"
#include "admin.h"
using namespace std;

int main(){
    Agent A[11];
    //writing agents information
    A[0].add_details("Aman Aggarwal", "aman@gmail.com", "9898171722");
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
        f1.write( (char*)&A[i], sizeof(Agent) );
    }
    f1.close();

    Admin Ad[2];
    //writing admin info
    Ad[0].add_admin("Abhilasha Bansal", "abhi123bansal@gmail.com", "8368658081", "12345abcde");
    Ad[1].add_admin("Abhay Gupta", "abhaygupta260@gmail.com", "8851889423", "abhaygupta");
    fstream f2;
    f2.open("admins.txt", ios::out);
    for(int i=0; i<=1; i++){
        f2.write( (char*)&Ad[i], sizeof(Admin) );
    }
    f2.close();

    //adding edges to graph
    Edge E[100];
    E[0].init("Delhi", "Dubai", 7500, 3.35);
    E[1].init("Delhi", "Mumbai", 1400, 2.05);
    E[2].init("Delhi", "Bangkok", 6300, 4.00);
    E[3].init("Delhi", "Moscow", 20000, 14.00);
    E[4].init("Delhi", "London", 25500, 9.25);

    E[5].init("Mumbai", "Hong Kong", 17000, 12.55);
    E[6].init("Mumbai", "Cape Town (South Africa)", 40000, 18.10);
    E[7].init("Mumbai", "London", 24500, 9.15);

    E[8].init("Dubai", "Cairo", 13000, 6.00);
    E[9].init("Dubai", "New York (USA)", 61000, 18.25);

    E[10].init("Cairo", "London", 13000, 5.20);
    E[11].init("Moscow", "Stockholm", 6900, 7.0);
    E[12].init("Stockholm", "London", 3500, 2.40);
    E[13].init("Stockholm", "Berlin (Germany)", 5300, 4.1);

    E[14].init("Hong Kong", "Tokyo", 9350, 3.55);
    E[15].init("Bangkok", "Singapore", 5500, 2.30);
    E[16].init("Singapore", "Melbourne (Australia)", 47000, 7.25);
    E[17].init("Singapore", "Sydney (Australia)", 19600, 7.45);

    E[18].init("Sydney (Australia)", "Melbourne (Australia)", 3500, 1.30);

    E[19].init("Tokyo", "Sydney (Australia)", 66000, 9.5);
    E[20].init("Tokyo", "Seoul", 9200, 2.40);
    E[21].init("Tokyo", "Canada", 32350, 12.50);
    E[22].init("Tokyo", "New York (USA)", 29300, 18.10);
    E[23].init("Tokyo", "LA (USA)", 25000, 18.30);
    E[24].init("Tokyo", "San Francisco (USA)", 25000, 18.30);

    E[25].init("Canada", "LA (USA)", 8500, 5.14);
    E[26].init("Canada", "San Francisco (USA)", 8000, 5.40);
    E[27].init("Canada", "Chicago (USA)", 7700, 1.50);
    E[28].init("Canada", "Washington DC (USA)", 9100, 1.27);

    E[29].init("London", "Rio (Brazil)", 19200, 15.47);
    E[30].init("London", "Washington DC (USA)", 21000, 11.00);
    E[31].init("London", "New York (USA)", 10000, 8.00);
    E[32].init("London", "Paris", 2800, 7.15);
    E[33].init("London", "Rome", 1750, 2.55);
    E[34].init("London", "Berlin (Germany)", 1400, 1.50);

    E[35].init("Rome", "Cape Town (South Africa)", 19800, 15.20);
    E[36].init("Rome", "Paris", 1000, 2.15);
    E[37].init("Rome", "Berlin (Germany)", 4400, 3.00);

    E[38].init("Paris", "Berlin (Germany)", 3500, 3.00);
    E[39].init("Paris", "Cape Town (South Africa)", 21300, 16.00);
    E[40].init("Paris", "New York (USA)", 13500, 11.00);
    E[41].init("Paris", "Washington DC (USA)", 15500, 16.00);

    E[42].init("Cape Town (South Africa)", "Rio (Brazil)", 52500, 41.00);
    E[43].init("Cape Town (South Africa)", "Washington DC (USA)", 27400, 24.00);
    E[44].init("Cape Town (South Africa)", "New York (USA)", 27800, 22.15);
    E[45].init("Cape Town (South Africa)", "Dubai", 22000, 24.00);

    E[46].init("Rio (Brazil)", "Santiago", 7500, 5.40);
    E[47].init("Rio (Brazil)", "Spain", 16500, 15.00);

    E[48].init("Santiago", "Peru", 4400, 3.49);
    E[49].init("Santiago", "Mexico City", 1700, 9.45); 

    E[50].init("Spain", "Peru", 19900, 12.00); 
    E[51].init("Spain", "London", 3700, 2.25); 
    E[52].init("Spain", "Berlin (Germany)", 1000, 4.00); 
    E[53].init("Spain", "Paris", 2500, 2.00); 
    E[54].init("Spain", "Rome", 1250, 2.55); 
    E[55].init("Spain", "Dubai", 14450, 24.00); 
    E[56].init("Spain", "Delhi", 17800, 12.30);
    E[57].init("Spain", "New York (USA)", 10500, 10.00); 

    E[58].init("Mexico City", "New York (USA)", 11000, 5.15); 
    E[59].init("Mexico City", "LA (USA)", 7300, 4.20); 
    E[60].init("Mexico City", "Washington DC (USA)", 19300, 4.10); 
    E[61].init("Mexico City", "Chicago (USA)", 8700, 4.10); 
    E[62].init("Mexico City", "Peru", 8250, 8.00); 
    E[63].init("Mexico City", "Havana", 12750, 9.00); 

    E[64].init("Peru", "Miami (USA)", 6500, 7.00); 
    E[65].init("Peru", "Washington DC (USA)", 7500, 10.00); 
    E[66].init("Peru", "Havana", 21000, 7.40); 
    E[67].init("Peru", "LA (USA)", 20000, 9.00); 
    E[68].init("Peru", "San Francisco (USA)", 18000, 14.00); 

    E[69].init("New York (USA)", "Delhi", 26000, 14.00); 
    E[70].init("New York (USA)", "Chicago (USA)", 2500, 2.00); 
    E[71].init("New York (USA)", "Washington DC (USA)", 5500, 1.15); 
    E[72].init("New York (USA)", "San Francisco (USA)", 6400, 6.30); 
    E[73].init("New York (USA)", "LA (USA)", 4200, 7.00); 
    E[74].init("New York (USA)", "Miami (USA)", 2500, 2.55); 
    E[75].init("New York (USA)", "Canada", 5200, 1.40); 

    E[76].init("Chicago (USA)", "Delhi", 26500, 16.00); 
    E[77].init("Chicago (USA)", "LA (USA)", 2750, 4.30); 
    E[78].init("Chicago (USA)", "San Francisco (USA)", 4500, 4.50); 
    E[79].init("Chicago (USA)", "Washington DC (USA)", 2250, 1.52); 

    E[80].init("LA (USA)", "Washington DC (USA)", 4000, 4.45); 
    E[81].init("LA (USA)", "San Francisco (USA)", 2600, 1.20); 
    E[82].init("LA (USA)", "Miami (USA)", 3750, 4.40); 
    E[83].init("LA (USA)", "Delhi", 24000, 24.00); 
    E[84].init("LA (USA)", "Dubai", 31500, 15.55); 

    E[85].init("LA (USA)", "San Francisco (USA)", 7000, 8.00); 

    //writing edges of graph in file
    fstream f3;
    f3.open("places.txt", ios::out| ios::binary);
    
    for(int i=0; i<=85; i++){
        f3.write( (char*)&E[i], sizeof(E[i]) );
    }
    f3.close();
    return 0;
}