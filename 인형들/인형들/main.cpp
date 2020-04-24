//
//  main.cpp
//  인형들
//
//  Created by kyuhwan cho on 2020/04/24.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;
vector<int> v;

double average(int i, int k){
    double m=0;
    int idx = i;
    int len = k;
    for(int j= idx; j<idx+len; j++){
        m += v[j];
    }
    m = m/k;
    return m;
}
double sigma(int i, int k){
    double m = average(i,k);
    double s =0;
    int idx = i;
    int len = k;
    for(int j=idx; j<idx+len; j++){
        s += pow(m-v[j],2);
    }
    s = s/k;
    return sqrt(s);
}


int main(int argc, const char * argv[]) {
    int n,k;
    double res = 99999999;
    cin>>n>>k;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    for(int j=k; j<n+1; j++){
        for(int i=0; i<v.size()-j+1; i++){
            res = min(res, sigma(i,j));
        }
    }
    cout<<fixed<<setprecision(11)<<res<<"\n";
    return 0;
}

