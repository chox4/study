//
//  main.cpp
//  No.11047
//
//  Created by kyuhwan cho on 2020/02/27.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int grd(int price){
    if(price==0){
        return 0;
    }
    int cnt=0;
    int maxx=0;
    for(int i=0; i<v.size(); i++){
        if(v[i] > price){
            maxx = v[i-1];
            break;
        }else if(v[i] == price){
            maxx = v[i];
            break;
        }
    }
    if(maxx==0){
        maxx=v[v.size()-1];
    }
    cnt = price/maxx;
    return cnt+grd(price-maxx*cnt);
}

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num,price;
    cin>>num>>price;
    for(int i=0; i<num; i++){
        int coin;
        cin>>coin;
        v.push_back(coin);
    }
    cout<<grd(price)<<"\n";
    return 0;
}
