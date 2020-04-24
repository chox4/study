//
//  main.cpp
//  상금 헌터
//
//  Created by kyuhwan cho on 2020/04/23.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    vector<pair<int, int>> fst;
    vector<pair<int, int>> snd;
    fst.reserve(6);
    snd.reserve(5);
    fst = {
        make_pair(1,500),
        make_pair(3,300),
        make_pair(6,200),
        make_pair(10,50),
        make_pair(15,30),
        make_pair(21,10)
    };
    snd = {
        make_pair(1,512),
        make_pair(3,256),
        make_pair(7,128),
        make_pair(15,64),
        make_pair(31,32)
    };
    int testCase;
    cin>>testCase;
    while(testCase--){
        int fst_rank, snd_rank,price=0;
        cin>>fst_rank>>snd_rank;
        for(int i=0; i<6; i++){
            if(fst_rank==0){
                break;
            }
            if(fst_rank>fst[i].first) continue;
            else{
                price+= fst[i].second;
                break;
            }
        }
        for(int i=0; i<5; i++){
            if(snd_rank==0){
                break;
            }
            if(snd_rank>snd[i].first) continue;
            else {
                price+= snd[i].second;
                break;
                }
        }
        cout<<price*10000<<"\n";
    }
    return 0;
}
