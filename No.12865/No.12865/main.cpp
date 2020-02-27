//
//  main.cpp
//  No.12865
//
//  Created by kyuhwan cho on 12/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[101][100001];
//dp[물건수][가치]

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int num,capacity,weight,value;
    cin>>num>>capacity;
    vector<pair<int, int>> v;
    v.reserve(num);
    for(int i=0; i<num; i++){
        cin>>weight>>value;
        v.push_back(make_pair(weight,value));
    }
    sort(v.begin(), v.end());
    for(int i=1; i<=num; i++){
        for(int j=1; j<=capacity; j++){
            if(v[i-1].first>j){
                //무게가 j보다 크다면 못넣으니까 물건수-1 했을때 값 그대로 가져오기
                dp[i][j] = dp[i-1][j];
            }else{
                //물건수 -1 했을 때 값과 물건 하나 추가했을 때 가치를 비교해 큰 값을 dp에 저장
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i-1].first]+v[i-1].second);
            }
        }
    }
    cout<<dp[num][capacity]<<"\n";
}


// 참고 사이트
// https://velog.io/@imacoolgirlyo/12865%EB%B2%88-%ED%8F%89%EB%B2%94%ED%95%9C-%EB%B0%B0%EB%82%AD-86k4cgn35m
