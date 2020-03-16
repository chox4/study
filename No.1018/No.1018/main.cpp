//
//  main.cpp
//  No.1018
//
//  Created by kyuhwan cho on 2020/03/16.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
char chess[50][50];

const char* mark[8]={
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};
int painting(int x, int y){
    int cnt=0;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(mark[i][j]!=chess[x+i][y+j]){
                cnt++;
            }
        }
    }
    if(cnt>32){
        cnt = 64-cnt;
    }
    return cnt;
}
int main(int argc, const char * argv[]) {
    int row,col;
    cin>>col>>row;
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            cin>>chess[i][j];
        }
    }
    int minn=65;
    for(int i=0; i<col-7; i++){
        for(int j=0; j<row-7; j++){
            minn = min(minn,painting(i,j));
        }
    }
    cout<<minn<<"\n";
    return 0;
}
