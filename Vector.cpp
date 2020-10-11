#include<iostream>
#include<vector>

using namespace std;

int main() {
    cout<<"Enter the no. of elements: ";
    int size;
    cin>> size;

    vector<int> arr; // Right now we have vector of default size so we have to resize it
    arr.resize(size);

    
    for (int i = 0; i < size; i++) {
        cout<<"Enter the element "<< i+1 << ": ";
        cin>>arr[i];
    } 

    cout<< "Elements are :";
    for (int i = 0; i < size; i++)
        cout<< " " << arr[i];

    return 0;
}