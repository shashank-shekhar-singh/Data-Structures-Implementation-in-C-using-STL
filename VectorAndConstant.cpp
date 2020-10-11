#include<iostream>
#include<vector>

using namespace std;

#define SIZE 5

int main() {
    vector<int> arr(SIZE);
    
    for (int i = 0; i< SIZE; i++) {
        cout<<"Enter the element "<< i+1 << ": ";
        cin>>arr[i];
    } 

    cout<< "Elements are : ";
    for (int i = 0; i < SIZE; i++)
        cout<< " " << arr[i];

    return 0;
}