//
//  main.cpp
//  탑
//
//  Created by kyuhwan cho on 12/11/2019.
//  Copyright © 2019 kyuhwan cho. All rights reserved.
//

#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer;
    queue<int> q;
    for(int i=0; i<heights.size(); i++){
        q.push(heights[i]);
    }
    int cnt = -1;
    while(!q.empty()){
        int pop_val = q.front();
        q.pop();cnt++;
        int pos = 0;
        for(int i=0; i<heights.size(); i++){
            if(i==cnt){
                answer.push_back(pos);
                break;
            }else if(pop_val < heights[i]){
                pos = i+1;
            }
        }
    }
    return answer;
}
