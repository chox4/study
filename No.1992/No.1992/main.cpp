//
//  main.cpp
//  No.1992
//
//  Created by kyuhwan cho on 2020/04/25.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 64
using namespace std;

char board[MAX][MAX];
vector<char> v;
void quadTree(int x, int y, int len){
    char flag = board[x][y];
    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(flag!=board[i][j]){
                flag = -1;
                break;
            }
        }
        if(flag==-1)break;
    }
    if(flag=='1'){
        v.push_back('1');
    }else if(flag=='0'){
        v.push_back('0');
    }else if(flag==-1){
        v.push_back('(');
        quadTree(x,y,len/2);
        quadTree(x,y+len/2, len/2);
        quadTree(x+len/2,y,len/2);
        quadTree(x+len/2, y+len/2, len/2);
        v.push_back(')');
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
    quadTree(0,0,len);
    for(int i=0; i<v.size(); i++){
        cout<<v[i];
    }
    cout<<"\n";
    return 0;
}
