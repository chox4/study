//
//  main.cpp
//  No.2178
//
//  Created by kyuhwan cho on 27/09/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 100

int map[MAX_SIZE][MAX_SIZE];
int dist_check[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
queue<pair<int,int>> q;
int N,M;
void bfs(int x, int y){
    q.push(make_pair(x,y));
    dist_check[x][y]++;
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        int fx = front.first;
        int fy = front.second;
        for(int i=0; i<4; i++){
            int nx = fx+dx[i];
            int ny = fy+dy[i];
            if(nx>=0&&nx<N&&ny>=0&&ny<M){
                if(dist_check[nx][ny]==0&&map[nx][ny]==1){
                    q.push(make_pair(nx, ny));
                    dist_check[nx][ny] = dist_check[fx][fy]+1;
                }
            }
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d",&map[i][j]);
            dist_check[i][j]=0;
        }
    }
    bfs(0,0);
    cout<<dist_check[N-1][M-1]<<endl;
}
