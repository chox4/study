//
//  main.cpp
//  No.2108
//
//  Created by kyuhwan cho on 01/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<int> temp;
bool compare(pair<int,int>a, pair<int,int>b){
    if(a.second==b.second){
        return a.first<b.first;
    }
    return a.second>b.second;
}
int avg(double sum, int len){
    return round(sum/len);
}
int mid(int len){
    return temp[len/2];
}
int lenth(){
    return temp.back()-temp.front();
}
int many(){
    vector<pair<int,int>> v;
    int flag=0;
    for(int i=0; i<temp.size(); i++){
        flag = 0;
        for(int j=0; j<v.size(); j++){
            if(v[j].first==temp[i]){
                v[j].second++;
                flag = 1;
                continue;
            }
        }
        if(flag==0){
            v.push_back(make_pair(temp[i],0));
        }
    }
    sort(v.begin(),v.end(),compare);
    if(v.size()==1){
        return v[0].first;
    }else if(v[0].second!=v[1].second){
        return v[0].first;
    }else{
        return v[1].first;
    }
}
int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase,num;
    int sum=0;
    int avg_val,mid_val,len_val,many_val;
    vector<int> v;
    cin>>testCase;
    for(int i=0; i<testCase; i++){
        cin>>num;
        sum += num;
        v.push_back(num);
    }
    temp = v;
    sort(temp.begin(), temp.end());
    avg_val = avg(sum, testCase);
    mid_val = mid(testCase);
    len_val = lenth();
    many_val = many();
    cout<<avg_val<<"\n";
    cout<<mid_val<<"\n";
    cout<<many_val<<"\n";
    cout<<len_val<<"\n";
    return 0;
}
