//
//  main.cpp
//  No.2630
//
//  Created by kyuhwan cho on 2020/04/24.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
#define MAX 128
int map[MAX][MAX];
int w = 0,b = 0;

void quadTree(int x, int y, int len){
    int flag = map[x][y];
    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(flag!=map[i][j]){
                flag = -1;
                break;
            }
        }
        if(flag==-1) break;
    }
    if(flag==0){
        w++;
    }else if(flag==1){
        b++;
    }else if(flag==-1){
        quadTree(x,y,len/2);
        quadTree(x+len/2,y, len/2);
        quadTree(x,y+len/2,len/2);
        quadTree(x+len/2, y+len/2, len/2);
    }
}

int main(int argc, const char * argv[]) {
    int len;
    cin>>len;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            cin>>map[i][j];
        }
    }
    quadTree(0,0,len);
    cout<<w<<endl;
    cout<<b<<endl;
    return 0;
}
