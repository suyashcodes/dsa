#include<iostream>
using namespace std;

int main(){
    int n;
    int adj_matrix[50][50];
    cout<<"Enter the no of cities : ";
    cin>>n;
        string city[n];

    for(int i=0;i<n;i++){
        cout<<"Enter the city name "<<i+1<<" : ";
        cin>>city[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout<<"\nEnter the time to trave from city "<< city[i] <<" to city "<<city[j]<<" : ";
            cin>>adj_matrix[i][j];
            adj_matrix[j][i] = adj_matrix[i][j];
        }
    }

    for(int i=0;i<n;i++){
        cout<<"\t"<<city[i]<<"\t";
    }
    for(int i=0;i<n;i++){
        cout<<"\n"<<city[i];
        for(int j=0;j<n;j++){
            cout<<"\t"<<adj_matrix[i][j]<<"\t";
        }
    }
    return 0;
}
