//
//  main.cpp
//  No.1012
//
//  Created by kyuhwan cho on 25/09/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 50

bool check_dfs[MAX_SIZE][MAX_SIZE];
int map[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int M,N;
queue<pair<int,int>> q;
void dfs(int x, int y){
    if(check_dfs[x][y]){
        return;
    }
    check_dfs[x][y]=true;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx>=0&&nx<M&&ny>=0&&ny<N){
            if(check_dfs[nx][ny]==false&&map[nx][ny]==1){
                dfs(nx,ny);
            }
        }
    }
}

void bfs(int x, int y){
    q.push(make_pair(x,y));
    check_dfs[x][y] = true;
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        int fx = front.first;
        int fy = front.second;
        for(int i=0; i<4; i++){
            int nx = fx+dx[i];
            int ny = fy+dy[i];
            if(nx>=0&&ny<M&&ny>=0&&ny<N){
                if(check_dfs[nx][ny]==false && map[nx][ny]==1){
                    q.push(make_pair(nx, ny));
                    check_dfs[nx][ny]=true;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    int testCase;
    cin>>testCase;
    while(testCase--){
        for(int i=0; i<MAX_SIZE; i++){
            fill_n(check_dfs[i],MAX_SIZE,false);
            fill_n(map[i],MAX_SIZE,0);
        }
        int earthworm_num=0;
        int K;
        cin>>M>>N>>K;
        for(int i=0; i<K; i++){
            int x,y;
            cin>>x>>y;
            map[x][y]=1;
        }
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(check_dfs[i][j]==false && map[i][j]==1){
                    earthworm_num++;
                    //dfs(i,j);
                    bfs(i,j);
                }
            }
        }
        cout<<earthworm_num<<endl;
    }
}
