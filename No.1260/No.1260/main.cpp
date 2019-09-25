//
//  main.cpp
//  No.1260
//
//  Created by kyuhwan cho on 25/09/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> a[1001];
queue<int> q;
bool check_dfs[1001];
bool check_bfs[1001];


void dfs(int x){
    if(check_dfs[x]){
        return;
    }
    check_dfs[x] = true;
    cout<<x<<' ';
    for(int i=0; i<a[x].size(); i++){
        int y = a[x][i];
        dfs(y);
    }
}


void bfs(int start){
    q.push(start);
    check_bfs[start] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<' ';
        for(int i=0; i<a[x].size(); i++){
            int y = a[x][i];
            if(!check_bfs[y]){
                q.push(y);
                check_bfs[y] = true;
            }
        }
    }
}


int main(int argc, const char * argv[]) {
    int n,e,v;
    cin>>n>>e>>v;
    for(int i=0; i<e; i++){
        int from, to;
        cin>>from>>to;
        a[from].push_back(to);
        a[to].push_back(from);
    }
    for(int i=1; i<=n; i++){
        sort(a[i].begin(), a[i].end());
    }
    dfs(v);
    cout<<endl;
    bfs(v);
}


//      1
// 2         3
//      4
//4 5 1
//1 2
//1 3
//1 4
//2 4
//3 4

