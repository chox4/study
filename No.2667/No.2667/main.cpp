//
//  main.cpp
//  No.2667
//
//  Created by kyuhwan cho on 25/09/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 25
int map[MAX_SIZE][MAX_SIZE];
int complex_num=0;
int complex[MAX_SIZE*MAX_SIZE];
bool check_dfs[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int N;
void dfs(int x, int y){
    if(check_dfs[x][y]){
        return;
    }
    check_dfs[x][y] = true;
    complex[complex_num]++;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&& nx<N && ny>=0 && ny<N){
            if(map[nx][ny]==1&&check_dfs[nx][ny]==false){
                dfs(nx,ny);
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(check_dfs[i][j]==false && map[i][j]==1){
                complex_num++;
                dfs(i,j);
            }
        }
    }
    sort(complex+1, complex+complex_num+1);
    cout<<complex_num<<endl;
    for(int i=1; i<=complex_num; i++){
        cout<<complex[i]<<endl;
    }
}
