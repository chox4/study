//
//  main.cpp
//  No.2206
//
//  Created by kyuhwan cho on 30/09/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 1000
int map[MAX_SIZE][MAX_SIZE];
int check[MAX_SIZE][MAX_SIZE];
int N,M;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int,int>> q;
void bfs(){
    q.push(make_pair(0,0));
    check[0][0] = 1;
    while(!q.empty()){
        pair<int,int> front = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int fx = front.first+dx[i];
            int fy = front.second+dy[i];
            if(fx>=0&&fx<M&&fy>=0&&fy<M){
                if(map[fx][fy]!=1&&check[fx][fy]==0){
                    q.push(make_pair(fx,fy));
                    check[fx][fy] = check[front.first][front.second]+1;
                }
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    bfs();
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cout<<check[i][j]<<" ";
        }
        cout<<endl;
    }
}

//6 4
//0000
//1110
//1000
//0000
//0111
//0000

