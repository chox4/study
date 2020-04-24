//
//  main.cpp
//  No.2981
//
//  Created by kyuhwan cho on 2020/04/24.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

int gcd(int a, int b){
    if(a%b==0){
        return b;
    }
    return gcd(b, a%b);
}


int main(int argc, const char * argv[]) {
    int n;
    cin>>n;
    vector<int> v(n),ans;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int q = v[1]-v[0];
    for(int i=2; i<n; i++){
        q = gcd(q,v[i]-v[i-1]);
    }
    for(int i=2; i*i<=q; i++){
        if(q % i == 0){
            ans.push_back(i);
            ans.push_back(q/i);
        }
    }
    ans.push_back(q);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
