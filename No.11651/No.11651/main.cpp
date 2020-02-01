//
//  main.cpp
//  No.11651
//
//  Created by kyuhwan cho on 01/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(pair<int,int>a, pair<int,int> b){
    if(a.second==b.second){
        return a.first<b.first;
    }
        return a.second<b.second;
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase,num1,num2;
    vector<pair<int,int>>v;
    cin>>testCase;
    for(int i=0; i<testCase; i++){
        cin>>num1>>num2;
        v.push_back(make_pair(num1,num2));
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0; i<testCase; i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
    
    return 0;
}
