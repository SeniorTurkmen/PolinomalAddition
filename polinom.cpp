#include <iostream>
#include <fstream>

using namespace std;


/* Polynominal Class Defination*/

class Polinom
{
private:
    string name;
    int *val;
    int size;
public:
    Polinom();
    Polinom(string name, int *val);
    ~Polinom();
    void print();
    void degree();
    bool pol_Degree(Polinom const &t);
    Polinom operator+(Polinom const &t);
    Polinom operator-(Polinom const &t);
    int operator+(int number);
    void operator++();
    Polinom operator+=(Polinom const &t);
    void operator==(Polinom const &t);
};
/* Functions of Polynomial Class */
Polinom::Polinom()
{
    this->val = new int (1);
    this->name = "x";
    this->val = 0;
}

Polinom::Polinom(string name, int *val):name(name),val(val){}

Polinom::~Polinom()
{
    delete [] val;
}

void Polinom::print(bool write){
    cout << "Polinom: "<< this->name << endl;
    this->Degree(write);
    cout << "================" << endl;
}

void Polinom::degree(bool write){
    int size = this->size;
    for (int degree : this->val)
    {
        cout << "(" << degree << "X^" << size << ")" ;
        if(variableNumber != 0 )
            cout << "+";
        size--;
    }
    cout << endl;
    if (write)
    {
        ofstream file("sonuc.txt");

        if ( file.is_open() ){
            file << this->name<< ": ";
            for (int degree : this->val)
            {
                file << "(" << degree << "X^" << size << ")" ;
                if(variableNumber != 0 )
                    file << "+";
                size--;
            }
            file << endl;
            file.close();
        }
    }
}

void Polinom::pol_Degree(Polinom const &t){
    return this->size == t.size;
}

Polinom Polinom::operator+(Polinom const &t){
    Polinom pol = new Polinom();

    pol.name = "newPolinom";

    int thisPolSize = this->size;
    int rhsPolSize = t.size;

    if(thisPolSize > rhsPolSize){
        pol.val = new int (thisPolSize);
        pol.val[0] = this->val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol.val[i] = this->val[i] + t.val[i-1];
        }
    }else if(rhsPolSize > thisPolSize){
        pol.val = new int (rhsPolSize);
        pol.val[0] = t.val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol.val[i] = this->val[i-1] + t.val[i];
        }
    }else
    {
        for (int i = 0; i < rhsPolSize; i++)
        {
            pol.val[i] = this->val[i] + t.val[i];
        }
    }

    return pol;
}

Polinom Polinom::operator-(Polinom const &t){
    Polinom pol = new Polinom();

    pol.name = "newPolinom";

    int thisPolSize = this->size;
    int rhsPolSize = t.size;

    if(thisPolSize > rhsPolSize){
        pol.val = new int (thisPolSize);
        pol.val[0] = this->val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol.val[i] = this->val[i] - t.val[i-1];
        }
    }else if(rhsPolSize > thisPolSize){
        pol.val = new int (rhsPolSize);
        pol.val[0] = t.val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol.val[i] = this->val[i-1] - t.val[i];
        }
    }else
    {
        for (int i = 0; i < rhsPolSize; i++)
        {
            pol.val[i] = this->val[i] - t.val[i];
        }
    }

    return pol;
}

int Polinom::operator+(int number){
    int sum = 0;
    sum += number;
    for (int degree : this->val)
    {
        sum += degree;
    }
    return sum;
}

void Polinom::operator++(){
    this->val[this->size]++;
}

Polinom Polinom::operator+=(Polinom const &t){
    Polinom pol = new Polinom();

    pol.name = this->name;

    int thisPolSize = this->size;
    int rhsPolSize = t.size;

    if(thisPolSize > rhsPolSize){
        pol.val = new int (thisPolSize);
        pol.val[0] = this->val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol.val[i] = this->val[i] + t.val[i-1];
        }
    }else if(rhsPolSize > thisPolSize){
        pol.val = new int (rhsPolSize);
        pol.val[0] = t.val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol.val[i] = this->val[i-1] + t.val[i];
        }
    }else
    {
        for (int i = 0; i < rhsPolSize; i++)
        {
            pol.val[i] = this->val[i] + t.val[i];
        }
    }

    return pol;
}

void Polinom::operator==(Polinom const &t){
    if(this->pol_Degree(t)){
        cout << "Dereceleri esit" << endl;
    }else
    {
        cout << "Dereceler esit Degil" << endl;
    }
}

/* Global Variables*/

/* Functions */

readTheFile()
{

}

poliynomialAssignment()
{

}

/* Main */
int main(int argc, char const *argv[])
{
    Polinom sonuc1, sonuc2, sonuc3, sonuc4;
    int scalar_value = 18;

    sonuc1 = pol[1] + pol[5];
    sonuc1.print(false);

    sonuc2 = pol[10] + scalar_value;
    sonuc2.print(false);

    Pol[2]++;
    Pol[3] += Pol[7];

    sonuc3 = Pol[6] - Pol[2];
    sonuc3.print(false);

    Pol[2] == Pol[10];

    sonuc4 = (Pol[3] - Pol[9]) + Pol[5];
    sonuc4.print(true);

    for (Polinom pol : Pol)
    {
        pol.print(false);
    }
    
    return 0;
}
