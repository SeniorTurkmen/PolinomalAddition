#ifndef POLINOM_H
# define POLINOM_H

#include<iostream>
#include<fstream>

using namespace std;
/* Polynominal Class Defination*/

class Polinom
{
public:
    string name;
    int *val;
    int size;
    Polinom();
    Polinom(string name, int *val, int size);
    ~Polinom();
    void print(bool wirte);
    void degree(bool write);
    bool pol_Degree(Polinom const *t);
    Polinom *operator+(Polinom const *t);
    Polinom *operator-(Polinom const *t);
    void operator=(Polinom const *t);
    int operator+(int number);
    void operator++();
    Polinom *operator+=(Polinom const *t);
    void operator==(Polinom const *t);
};
/* Functions of Polynomial Class */
Polinom::Polinom()
{
    this->val = new int [5];
    this->name = "x";
    this->val = 0;
}

Polinom::Polinom(string name, int arr[], int size)
{
    this->name = name;
    this->val = new int [5];
    for (int i = 0; i < size; i++)
    {
        this->val[i] = arr[i];
    }
    this->size = size;
}

Polinom::~Polinom()
{
    delete [] val;
}

void Polinom::print(bool write){
    cout << "Polinom: "<< this->name << endl;
    this->degree(write);
    cout << "================" << endl;
}

void Polinom::degree(bool write){
    int size = this->size;
    for (int i = 0; i < this->size; i++)
    {
        cout << "(" << this->val[i] << "X^" << size << ")" ;
        if(size != 0 )
            cout << "+";
        size--;
    }
    cout << endl;
    size = this->size;
    if (write)
    {
        ofstream file("sonuc.txt");

        if ( file.is_open() ){
            file << this->name<< ": ";
            for(int i = 0; i < this->size; i++)
            {
                file << "(" << this->val[i] << "X^" << size << ")" ;
                if(size != 0 )
                    file << "+";
                size--;
            }
            file << endl;
            file.close();
        }
    }
}

bool Polinom::pol_Degree(Polinom const *t){
    return this->size == t->size;
}

Polinom *Polinom::operator+(Polinom const *t){
    Polinom *pol = new Polinom();

    pol->name = "newPolinom";

    int thisPolSize = this->size;
    int rhsPolSize = t->size;

    if(thisPolSize > rhsPolSize){
        pol->val = new int (thisPolSize);
        pol->val[0] = this->val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol->val[i] = this->val[i] + t->val[i-1];
        }
    }else if(rhsPolSize > thisPolSize){
        pol->val = new int (rhsPolSize);
        pol->val[0] = t->val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol->val[i] = this->val[i-1] + t->val[i];
        }
    }else
    {
        for (int i = 0; i < rhsPolSize; i++)
        {
            pol->val[i] = this->val[i] + t->val[i];
        }
    }

    return pol;
}

Polinom *Polinom::operator-(Polinom const *t){
    Polinom *pol = new Polinom();

    pol->name = "newPolinom";

    int thisPolSize = this->size;
    int rhsPolSize = t->size;

    if(thisPolSize > rhsPolSize){
        pol->val = new int (thisPolSize);
        pol->val[0] = this->val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol->val[i] = this->val[i] - t->val[i-1];
        }
    }else if(rhsPolSize > thisPolSize){
        pol->val = new int (rhsPolSize);
        pol->val[0] = t->val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol->val[i] = this->val[i-1] - t->val[i];
        }
    }else
    {
        for (int i = 0; i < rhsPolSize; i++)
        {
            pol->val[i] = this->val[i] - t->val[i];
        }
    }

    return pol;
}

void Polinom::operator=(Polinom const *t){
    this->name = t->name;
    this->val = t->val;
}

int Polinom::operator+(int number){
    int sum = 0;
    sum += number;
    for (int i = 0; i < this->size; i++)
    {
        sum += this->val[i];
    }
    return sum;
}

void Polinom::operator++(){
    this->val[this->size]++;
}

Polinom *Polinom::operator+=(Polinom const *t){
    Polinom *pol = new Polinom();

    pol->name = this->name;

    int thisPolSize = this->size;
    int rhsPolSize = t->size;

    if(thisPolSize > rhsPolSize){
        pol->val = new int (thisPolSize);
        pol->val[0] = this->val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol->val[i] = this->val[i] + t->val[i-1];
        }
    }else if(rhsPolSize > thisPolSize){
        pol->val = new int (rhsPolSize);
        pol->val[0] = t->val[0];
        for (int i = 1; i<thisPolSize ; i++)
        {
            pol->val[i] = this->val[i-1] + t->val[i];
        }
    }else
    {
        for (int i = 0; i < rhsPolSize; i++)
        {
            pol->val[i] = this->val[i] + t->val[i];
        }
    }

    return pol;
}

void Polinom::operator==(Polinom const *t){
    if(this->pol_Degree(t)){
        cout << "Dereceleri esit" << endl;
    }else
    {
        cout << "Dereceler esit Degil" << endl;
    }
}



#endif