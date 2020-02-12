//
//  main.cpp
//  No.1912
//
//  Created by kyuhwan cho on 12/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int seq[100001];
int dp[100001];

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num,val;
    cin>>num;
    for(int i=0; i<num; i++){
        cin>>val;
        seq[i] = val;
    }
    dp[0] = seq[0];
    for(int i=1; i<num; i++){
        dp[i] = max(dp[i-1]+seq[i],seq[i]);
    }
    int max_val=dp[0];
    for(int i=0; i<num; i++){
        if(max_val<dp[i]){
            max_val = dp[i];
        }
    }
    cout<<max_val<<"\n";
}
