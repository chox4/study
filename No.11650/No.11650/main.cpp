//
//  main.cpp
//  No.11650
//
//  Created by kyuhwan cho on 01/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase,num1,num2;
    cin>>testCase;
    vector<pair<int,int>> v;
    for(int i=0; i<testCase; i++){
        cin>>num1>>num2;
        v.push_back(make_pair(num1,num2));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); i++){
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    }
}
