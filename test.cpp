#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

void printArr(int *arr){
    for(int i = 0; i<5;i++)
        cout << arr[i] <<endl;
}

int main(){
    int arr[5]= {1,2,3,4,5};

    printArr(arr);
    return 0;
}
