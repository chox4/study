//
//  main.cpp
//  No.7568
//
//  Created by kyuhwan cho on 2020/03/15.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase;
    cin>>testCase;
    vector<pair<pair<int, int>,int>> v;
    vector<pair<int, int>> temp;
    for(int i=0; i<testCase; i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(make_pair(a,b),0));
    }
    int cnt=1;
    for(int i=0; i<v.size(); i++){
        cnt=1;
        for(int j=0; j<v.size(); j++){
            if(i==j) continue;
            if(v[i].first.first<v[j].first.first && v[i].first.second<v[j].first.second){
                cnt++;
            }
        }
        v[i].second = cnt;
    }
    for(int i=0; i<v.size(); i++){
        cout<<v[i].second<<" ";
    }
    cout<<"\n";
    return 0;
}
