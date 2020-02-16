//
//  main.cpp
//  실패율
//
//  Created by kyuhwan cho on 16/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<double, int>a, pair<double, int> b){
    if(a.first==b.first){
        return a<b;
    }
    return a>b;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<double, int>>failure;
    vector<int> stage = stages;
    sort(stage.begin(), stage.end());
    int stage_cnt = stage.size();
    for(int cnt=1; cnt<N+1; cnt++){
        int elem_cnt=0;
        for(int i=0; i<stage.size(); i++){
            if(stage[i]==cnt){
                elem_cnt++;
            }
        }
        double fail;
        if(stage_cnt==0){
             fail = 0;
        }else{
            fail = (double)elem_cnt/stage_cnt;
        }
        failure.push_back(make_pair(fail,cnt));
        stage_cnt -= elem_cnt;
    }
    sort(failure.begin(), failure.end(), compare);
    for(int i=0; i<failure.size(); i++){
        answer.push_back(failure[i].second);
    }
    return answer;
}

int main(){
    int n=5;
    vector<int> stages;
    stages.push_back(1);
    stages.push_back(1);
    stages.push_back(1);
    stages.push_back(1);
    stages.push_back(1);
    stages.push_back(1);
    stages.push_back(1);
    stages.push_back(1);
    vector<int> answer = solution(n,stages);
    for(auto it = answer.begin(); it!=answer.end(); it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}
