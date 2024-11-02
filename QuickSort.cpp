#include<bits/stdc++.h>
#include<random>
#include<chrono>
using namespace std;

int Partition(vector<int> &arr, int low, int high){

    int pivot = arr[high]; // for lomuto always last element
    int i = low - 1;
    for(int j = low; j<= high-1;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        } 
    }
    swap(arr[i+1],arr[high]); // set the pivot to its correct position
    return i+1; // location of the pivot

}


void QuickSort(vector<int> &arr, int low, int high){

    if(low<high){
        int partition = Partition(arr,low,high);
        QuickSort(arr,low,partition-1);
        QuickSort(arr,partition+1,high);
    }
}

int main(){

    vector<int> arr;
    for(int i=0;i<100000;i++)
        arr.push_back(i+1);

    for(int i=0;i<5000;i++){ //inserting same element 
        arr.push_back(55);
        arr.push_back(999);
        arr.push_back(64874);
        arr.push_back(1342);
        arr.push_back(9577);
    }
    for(int i=0;i<10000;i++){ //inserting same element 
        arr.push_back(76467);
        arr.push_back(99990);
        arr.push_back(6474);
        arr.push_back(132);
        arr.push_back(77);
    }

    //Suffle the arr elements
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(),arr.end(),g);

    // Time Count

    
    
    int n = arr.size();

    // cout<<"Original Array"<<endl;
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    auto start = chrono::high_resolution_clock::now();

    QuickSort(arr,0,n-1);

    auto end = chrono::high_resolution_clock::now();
    
    // cout<<"Sorted Array"<<endl;
    // for(int i=0;i<n;i++)
    //     cout<<arr[i]<<" ";
    // cout<<endl;

    
    chrono::duration<double, milli> duration = end - start;

    cout<<endl<<"Running Time = "<<duration.count()<<" ms"<<endl;
    cout<<"Size of the Array = "<<arr.size()<<endl;

}