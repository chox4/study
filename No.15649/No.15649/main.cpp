//
//  main.cpp
//  No.15649
//
//  Created by kyuhwan cho on 2020/03/20.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>

#define endl "\n"
using namespace std;
int N,M;
int arr[10];
bool visit[10];

void dfs(int length){
    if(length==M){
        for(int i=0; i<M; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1; i<N+1; i++){
        if(visit[i]) continue;
        visit[i] = true;
        arr[length] = i;
        dfs(length+1);
        visit[i] = false;
    }
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        visit[i] = true;
        arr[0] = i;
        dfs(1);
        visit[i] = false;
    }
    return 0;
}
