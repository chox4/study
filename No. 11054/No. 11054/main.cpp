//
//  main.cpp
//  No. 11054
//
//  Created by kyuhwan cho on 12/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
using namespace std;
int seq[1001];
int to_right[1001];
int to_left[1001];
int main(int argc, const char * argv[]) {
    int num;
    cin>>num;
    for(int i=0; i<num; i++){
        cin>>seq[i];
    }
    for(int i=0; i<num; i++){
        to_right[i] = 1;
        for(int j=0;j<i; j++){
            if(seq[j]<seq[i] && to_right[i]<to_right[j]+1){
                to_right[i] = to_right[j]+1;
            }
        }
    }
    for(int i=num-1; i>-1; i--){
        to_left[i] = 1;
        for(int j=num-1;j>i; j--){
            if(seq[j]<seq[i] && to_left[i]<to_left[j]+1){
                to_left[i] = to_left[j]+1;
            }
        }
    }
    int answer = to_right[0]+to_left[0]-1;
    for(int i=0; i<num; i++){
        if(answer<to_right[i]+to_left[i]-1){
            answer = to_right[i]+to_left[i]-1;
        }
    }
    cout<<answer<<"\n";
}

