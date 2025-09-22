#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){ 
    vector<int> v;
    cout<<"size of vector 1: "<<v.size()<<endl;
    cout<<"capacity of vector 1: "<<v.capacity()<<endl;
    v.push_back(1);
    cout<<"size of vector 2: "<<v.size()<<endl;
    cout<<"capacity of vector 2: "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"size of vector 3: "<<v.size()<<endl;
    cout<<"capacity of vector 3: "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"size of vector 4: "<<v.size()<<endl;
    cout<<"capacity of vector 4: "<<v.capacity()<<endl;
    v.push_back(4);
    cout<<"size of vector 5: "<<v.size()<<endl;
    cout<<"capacity of vector 5: "<<v.capacity()<<endl;
    v.push_back(5);
    cout<<"size of vector 6: "<<v.size()<<endl;
    cout<<"capacity of vector 6: "<<v.capacity()<<endl;
    v.push_back(6);
    cout<<"size of vector 7: "<<v.size()<<endl;
    cout<<"capacity of vector 7: "<<v.capacity()<<endl;
    v.push_back(7);
    cout<<"size of vector 8: "<<v.size()<<endl;
    cout<<"capacity of vector 8: "<<v.capacity()<<endl;
    v.push_back(8);
    cout<<"size of vector 9: "<<v.size()<<endl;
    cout<<"capacity of vector 9: "<<v.capacity()<<endl;
    v.push_back(9);
    cout<<"size of vector 10: "<<v.size()<<endl;
    cout<<"capacity of vector 10: "<<v.capacity()<<endl;
    int n = v.size();
    cout<<"elements in the vector: ";   
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
        for(auto value:v)
        cout<<value<<" ";
        cout<<endl;
        cout<<"front:"<<v.front()<<endl;
        cout<<"back:"<<v.back()<<endl;
        v.insert(v.begin()+3,10);
        for(auto vlaue:v)
     // insert 100 at index 3
        cout<<"after inserting 10 at index 3: ";
        for(auto value:v)
        cout<<value<<" ";
        cout<<endl;
        v.erase(v.begin()+3);
        cout<<"after erasing element at index 3: ";
        for(auto value:v)
        cout<<value<<" ";
        cout<<endl;
        v.pop_back();
        cout<<"after popping last element: ";
        for(auto value:v)
        cout<<value<<" ";
        cout<<endl;
        v.clear();
        cout<<"after clearing the vector: ";
        cout<<"size: "<<v.size()<<endl;
        cout<<"capacity: "<<v.capacity()<<endl;  
       for(auto itr=v.begin();itr!=v.end();itr++){
           cout<<*itr<<" ";
    }
    return 0;
}
}