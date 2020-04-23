//
//  main.cpp
//  No.15650
//
//  Created by kyuhwan cho on 2020/04/23.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> v;
bool visited[9];

void dfs(int cnt, int idx){
    if(cnt==m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
    }
    for(int i=idx; i<n+1; i++){
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        v.push_back(i);
        dfs(cnt+1, i);
        visited[i] = false;
        v.pop_back();
    }
    
}
void Input(){
    cin>>n>>m;
}
int main(int argc, const char * argv[]) {
    Input();
    dfs(0,1);
    
    return 0;
}
