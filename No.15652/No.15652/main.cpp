//
//  main.cpp
//  No.15652
//
//  Created by kyuhwan cho on 2020/04/23.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m;
bool visited[9];
vector<int> v;

void dfs(int cnt, int idx){
    if(cnt==m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    for(int i=idx; i<n+1; i++){
        v.push_back(i);
        dfs(cnt+1, i);
        v.pop_back();
    }
}

int main(int argc, const char * argv[]) {
    cin>>n>>m;
    dfs(0, 1);
    
    return 0;
}
