//
//  main.cpp
//  No.1966
//
//  Created by kyuhwan cho on 2020/03/02.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    queue <pair<int,int>> q;
    //우선순위 큐로 가중치 정렬, 기본값 내림차순
    priority_queue<int> pq;
    int testCase,N,M;
    cin>>testCase;
    while(testCase--){
        cin>>N>>M;
        int num;
        int cnt=0;
        for(int i=0; i<N; i++){
            cin>>num;
            q.push(make_pair(num,i));
            pq.push(num);
        }
        while(!q.empty()){
            int pop_num = q.front().first;
            int pop_idx = q.front().second;
            q.pop();
            if(pq.top()==pop_num){
                pq.pop();
                cnt++;
                if(pop_idx == M){
                    cout<<cnt<<"\n";
                }
            }else{
                q.push(make_pair(pop_num,pop_idx));
            }
        }
        
    }
}
