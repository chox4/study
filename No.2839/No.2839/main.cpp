//
//  main.cpp
//  No.2839
//
//  Created by kyuhwan cho on 2020/03/06.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//
// 메모이제이션기법 사용.
#include <iostream>
using namespace std;
int bag[5001];
int min_bag(int sugar){
    if(bag[sugar]!=-1){
        return bag[sugar];
    }
    if(sugar<0){
        return 0;
    }else if(sugar<6){
        if(sugar==3||sugar==5){
            bag[sugar] = 1;
            return bag[sugar];
        }else{
            bag[sugar] = 9999;
            return bag[sugar];
        }
    }else{
        bag[sugar-3] = min_bag(sugar-3);
        bag[sugar-5] = min_bag(sugar-5);
        bag[sugar] = min(bag[sugar-3], bag[sugar-5])+1;
        return bag[sugar];
    }
}


int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int sugar;
    cin>>sugar;
    fill_n(bag,5001,-1);
    int answer = min_bag(sugar);
    //7일때 10000출력됨.
    if(answer>=9999){
        cout<<"-1"<<"\n";
    }else{
        cout<<answer<<"\n";
    }
    return 0;
}
