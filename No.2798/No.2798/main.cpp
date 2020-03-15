//
//  main.cpp
//  No.2798
//
//  Created by kyuhwan cho on 2020/03/07.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int cardN, maxx,answer=0;
    vector<int> v;
    cin>>cardN>>maxx;
    for(int i=0; i<cardN; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    int flag = 0;
    for(int i=0; i<v.size(); i++){
        for(int j=i+1; j<v.size(); j++){
            for(int k=j+1; k<v.size(); k++){
                int tmp = v[i]+v[j]+v[k];
                if(tmp==maxx){
                    flag = 1;
                    answer = tmp;
                    break;
                }else if(tmp<maxx && tmp>answer){
                    answer = tmp;
                }
            }
            if(flag==1){
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    cout<<answer<<"\n";
    return 0;
}
