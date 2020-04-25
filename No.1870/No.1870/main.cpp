//
//  main.cpp
//  No.1870
//
//  Created by kyuhwan cho on 2020/04/25.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#define MAX 3000
#define endl "\n"
using namespace std;
int fst = 0;
int snd = 0;
int thd = 0;
int board[MAX][MAX];

void divTree(int x, int y, int len){
    int flag = board[x][y];
    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(flag!=board[i][j]){
                flag = -2;
                break;
            }
        }
        if(flag==-2)break;
    }
    if(flag==0){
        snd++;
    }else if(flag==1){
        thd++;
    }else if(flag==-1){
        fst++;
    }else if(flag==-2){
        divTree(x,y,len/3);
        divTree(x,y+len/3,len/3);
        divTree(x,y+len/3+len/3,len/3);
        divTree(x+len/3,y,len/3);
        divTree(x+len/3,y+len/3,len/3);
        divTree(x+len/3,y+len/3+len/3,len/3);
        divTree(x+len/3+len/3,y,len/3);
        divTree(x+len/3+len/3,y+len/3,len/3);
        divTree(x+len/3+len/3,y+len/3+len/3,len/3);
    }
}


int main(int argc, const char * argv[]) {
    int len;
    cin>>len;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            cin>>board[i][j];
        }
    }
    divTree(0,0,len);
    cout<<fst<<endl;
    cout<<snd<<endl;
    cout<<thd<<endl;
    return 0;
}
