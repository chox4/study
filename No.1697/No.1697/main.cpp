//
//  main.cpp
//  No.1697
//
//  Created by kyuhwan cho on 30/09/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
#define MAX_SIZE 100001
int check[MAX_SIZE];
queue<int> q;
void bfs(int n, int m){
    q.push(n);
    check[n]=1;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        if(front==m){
            cout<<check[front]-1<<endl;
            return;
        }
        int next_n1 = front-1;
        int next_n2 = front+1;
        int next_n3 = front*2;
        if(next_n1>=0&&check[next_n1]==0){
            check[next_n1] = check[front]+1;
            q.push(next_n1);
        }
        if(next_n2<=MAX_SIZE-1&&check[next_n2]==0){
            check[next_n2] = check[front]+1;
            q.push(next_n2);
        }
        if(next_n3<=MAX_SIZE-1&&check[next_n3]==0){
            check[next_n3] = check[front]+1;
            q.push(next_n3);
        }
    }
}

int main(){
    int N,M;
    cin>>N>>M;
    fill_n(check,MAX_SIZE,0);
    bfs(N,M);
    return 0;
}
