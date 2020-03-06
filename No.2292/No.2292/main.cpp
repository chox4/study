//
//  main.cpp
//  No.2292
//
//  Created by kyuhwan cho on 2020/03/06.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    vector<long long> v;
    long long room;
    cin>>room;
    long long seq = 1;
    long long num = 0;
    while(seq < 1000000000){
        v.push_back(seq);
        num += 6;
        seq += num;
    }
    if(room>v[v.size()-1]){
        cout<<v.size()+1<<"\n";
    }else{
        for(int i=0; i<v.size(); i++){
            if(room <= v[i]){
                cout<<i+1<<"\n";
                break;
            }
        }
    }
    return 0;
}
