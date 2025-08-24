#include<bits/stdc++.h>
#include<random>
#include<chrono>
using namespace std;

pair<int,int> Partition(vector<int> &arr, int low, int high){

    int mid = low;           
    int pivot = arr[low];
    while(mid<=high){
        if(arr[mid]<pivot){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==pivot)
            mid++;
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }

    return make_pair(low,mid-1);

}

void QuickSort(vector<int> &arr, int low, int high){
    
    begin: 

    if(low<high){   

        pair<int,int> pair = Partition(arr,low,high);
        QuickSort(arr,low,pair.first-1);
        low = pair.second+1;
        goto begin;
    }
}

bool isSorted(const vector<int>& arr){
    for(size_t i=1;i<arr.size();i++){
        if(arr[i-1] > arr[i])
            return false;
    }
    return true;
}

void printArray(const vector<int>& arr){
    for(size_t i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
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

    int n = arr.size();
    cout<<"Is Sorted? "<< (isSorted(arr) ? "Yes" : "No");
    
    // Time Count
    auto start = chrono::high_resolution_clock::now();

    QuickSort(arr,0,n-1);

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = end - start;
    
    cout<<endl<<"Running Time = "<<duration.count()<<" ms"<<endl;
    cout<<"Size of the Array = "<<arr.size()<<endl;
    cout<<"Is Sorted? "<< (isSorted(arr) ? "Yes" : "No") <<endl;
}