#include <iostream>
#include <fstream>
#include <sstream>
#include "polinom.h"

using namespace std;



/* Global Variables*/
Polinom *Pol[10];

/* Functions */

void poliynomialAssignment(string value,int rank)
{
    int degree[5];
    int num = 0, val;
    string name,b;
    stringstream ss(value);
    getline(ss, b, ' ');
    stringstream nameStream(b);
    nameStream >> name;
    cout << "Polinom: " << name <<endl;
    while(getline(ss, b, ','))
    {
        stringstream ss2(b);
        ss2 >> val;
        cout << num+1 << ". deger: " << val << endl;
        degree[num] = val;
        num++;
    }
    cout << "===============================" << endl;
    Pol[rank] = new Polinom(name, degree, num);
}

void readTheFile()
{
    string string1, strign2;
    ifstream file("polinom.txt");
    int polRank = 0;
    if (file.is_open())
    {
        string a;
        while(getline(file,a))
        {
            poliynomialAssignment(a, polRank);
            polRank++;
        }
    }
}


/* Main */
int main(int argc, char const *argv[])
{
    cout << "Test" << endl;
    readTheFile();
    Polinom *sonuc1, *sonuc2, *sonuc3, *sonuc4;
    int scalar_value = 18;

    sonuc1 = (*Pol[1] + Pol[5]);
    //sonuc1->print(false);

    sonuc2 = Pol[10]+scalar_value;
    //sonuc2->print(false);

    Pol[2]++;
    *Pol[3] += Pol[7];

    sonuc3 = (*Pol[6] - Pol[2]);
    //sonuc3->print(false);

    Pol[2] == Pol[10];

    sonuc4 = *(*Pol[3] - Pol[9]) + Pol[5];
    //sonuc4->print(true);

    for (int i = 0; i<10; i++)
    {
        //Pol[i]->print(false);
    }

    return 0;
}
