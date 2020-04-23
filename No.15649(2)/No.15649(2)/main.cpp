//
//  main.cpp
//  No.15649(2)
//
//  Created by kyuhwan cho on 2020/04/23.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool visited[9];
vector<int> v;
int n,m;

void dfs(int num){
    if(num==m){
        for(int i=0; i<v.size(); i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<n+1; i++){
        if(visited[i]){
            continue;
        }
        visited[i] = true;
        v.push_back(i);
        dfs(num+1);
        visited[i] = false;
        v.pop_back();
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    cin>>n>>m;
    dfs(0);
    return 0;
}
