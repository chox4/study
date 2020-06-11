//
//  main.cpp
//  No.1920
//
//  Created by kyuhwan cho on 2020/06/10.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n;
    vector<int> a(n), ans;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    cin>>m;
    vector<int> v(m);
    for(int i=0; i<m; i++){
        cin>>v[i];
        int num = v[i];
        if(binary_search(a.begin(),a.end(),num)){
            ans.push_back(1);
        }else{
            ans.push_back(0);
        }
    }
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
