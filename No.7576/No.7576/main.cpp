//
//  main.cpp
//  No.7576
//
//  Created by kyuhwan cho on 28/09/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 1000
int map[MAX_SIZE][MAX_SIZE];
int check[MAX_SIZE][MAX_SIZE];
int X,Y;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt=0;
queue<pair<int,int>> q;
void bfs(){
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        int fx = front.first;
        int fy = front.second;
        for(int i=0; i<4; i++){
            int nx = fx+dx[i];
            int ny = fy+dy[i];
            if(nx>=0&&nx<X&&ny>=0&&ny<Y){
                if(check[nx][ny]==-1&&map[nx][ny]==0){
                    q.push(make_pair(nx, ny));
                    check[nx][ny]=check[fx][fy]+1;
                    if(cnt<check[nx][ny]){
                        cnt = check[nx][ny];
                    }
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>Y>>X;
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            cin>>map[i][j];
            check[i][j]=-1;
        }
    }
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            if(map[i][j]==1){
            q.push(make_pair(i, j));
            check[i][j]=0;
            }
        }
    }
    bfs();
    for(int i=0; i<X; i++){
        for(int j=0; j<Y; j++){
            if(check[i][j]==-1&&map[i][j]==0){
                cnt = -1;
            }
        }
    }
    cout<<cnt<<endl;
}
