//
//  main.cpp
//  No.1932
//
//  Created by kyuhwan cho on 21/07/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
int mem[501][501];
int tri_arr[501][501];

void max_tri(int size){
    for(int i=size; i>-1; i--){
        for(int j=0; j<i; j++){
            if(i == size){
                mem[i][j] = tri_arr[i][j];
            }else{
                mem[i][j] = max(mem[i+1][j],mem[i+1][j+1])+tri_arr[i][j];
            }
        }
    }
    cout<<mem[1][0]<<endl;
}

int main(int argc, const char * argv[]) {
    int triSize;
    cin>>triSize;
    for(int i=0; i<triSize+1; i++){
        for(int j=0; j<i; j++){
            cin>>tri_arr[i][j];
        }
    }
    for(int i=0; i<501; i++){
        fill_n(mem[i],501,-1);
    }
    max_tri(triSize);
//    for(int i=0; i<triSize+1; i++){
//        for(int j=0; j<i; j++){
//            cout<<mem[i][j]<<" ";
//        }
//        cout<<endl;
//    }
}
