//
//  main.cpp
//  No.1021
//
//  Created by kyuhwan cho on 2020/03/04.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    deque<int> d[3];
    vector<int> v;
    int len,num;
    cin>>len>>num;
    for(int i=0; i<len; i++){
        d[0].push_back(i+1);
        d[1].push_back(i+1);
        d[2].push_back(i+1);
    }
    for(int i=0; i<num; i++){
        int number;
        cin>>number;
        v.push_back(number);
    }
    int cnt=0;
    for(int i=0; i<v.size(); i++){
        if(v[i]==d[0].front()){
            d[0].pop_front();
            d[1] = d[0];
            d[2] = d[0];
        }else{
            int len[2]={0,0};
            //shift left
            while(d[1].front()!=v[i]){
                int tmp = d[1].front();
                d[1].pop_front();
                d[1].push_back(tmp);
                len[0]++;
            }
            //shift right
            while(d[2].front()!=v[i]){
                int tmp = d[2].back();
                d[2].pop_back();
                d[2].push_front(tmp);
                len[1]++;
            }
            //shift right가 작으니 len[1]만큼 이동
            if(len[0]>=len[1]){
                int cyc = len[1];
                cnt += cyc;
                while(cyc--){
                    int tmp = d[0].back();
                    d[0].pop_back();
                    d[0].push_front(tmp);
                }
            }else{
                int cyc = len[0];
                cnt += cyc;
                while(cyc--){
                    int tmp = d[0].front();
                    d[0].pop_front();
                    d[0].push_back(tmp);
                }
            }
            d[0].pop_front();
            d[1] = d[0];
            d[2] = d[0];
        }
    }
    cout<<cnt<<"\n";
}
