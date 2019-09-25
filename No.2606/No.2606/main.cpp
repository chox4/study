//
//  main.cpp
//  No.2606
//
//  Created by kyuhwan cho on 25/09/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define startNode 1

vector<int> a[101];
queue<int> q;
bool check_dfs[101];
bool check_bfs[101];
int virusNum=-1;

void dfs(int x){
    if(check_dfs[x]){
        return;
    }
    check_dfs[x] = true;
    virusNum++;
    for(int i=0; i<a[x].size();i++){
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
        virusNum++;
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
    int c_num,e_num;
    cin>>c_num>>e_num;
    for(int i=0; i<e_num; i++){
        int from,to;
        cin>>from>>to;
        a[from].push_back(to);
        a[to].push_back(from);
    }
    for(int i=1;i<=c_num; i++){
        sort(a[i].begin(), a[i].end());
    }
    dfs(startNode);
    cout<<virusNum<<endl;
}

//7
//6
//1 2
//2 3
//1 5
//5 2
//5 6
//4 7

