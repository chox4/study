//
//  main.cpp
//  No.2565
//
//  Created by kyuhwan cho on 12/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int mem[101];
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<pair<int, int>>v;
    int num,a,b;
    cin>>num;
    v.reserve(num);
    for(int i=0; i<num; i++){
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<num; i++){
        mem[i] = 1;
        for(int j=0; j<i; j++){
            if(v[j].second<v[i].second && mem[i]<mem[j]+1){
                mem[i] = mem[j]+1;
            }
        }
    }
    int max=-1;
    for(int i=0; i<num; i++){
        if(max<mem[i]){
            max = mem[i];
        }
    }
    cout<<num-max<<"\n";
}


