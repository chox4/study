//
//  main.cpp
//  No.1874
//
//  Created by kyuhwan cho on 2020/03/02.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(int argc, const char * argv[]) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int testCase;
    cin>>testCase;
    vector<int> v;
    vector<char> answer;
    stack<int> s;
    for(int i=0; i<testCase; i++){
        int num;
        cin>>num;
        v.push_back(num);
    }
    int number = 1;
    for(int i=0; i<v.size(); i++){
        //스택 비어있다면
        if(s.empty()){
            //v[i]까지 푸시연산
            while(number<=v[i]){
                s.push(number++);
                answer.push_back('+');
            }
            //마지막 v[i]값은 팝 연산
            if(!s.empty()){
                s.pop();
                answer.push_back('-');
            }else{
                //비어있는데 팝 연산하는 부분은 수열을 만들 수 없는 상황.
                cout<<"NO"<<"\n";
                return 0;
            }
        }else{
            //스택의 top이 크므로 v[i] 값까지 팝연산
            if(s.top()>v[i]){
                while(s.top()>=v[i]){
                    s.pop();
                    answer.push_back('-');
                    //팝연산 뒤 스택이 비어있다면 조건문에서 에러발생하므로 예외처리.
                    if(s.empty()){
                        break;
                    }
                }
            }
            //스택의 top이 작으면 v[i]까지 푸쉬연산 & top 이랑 v[i]가 같다면 바로 팝연산
            else if(s.top()<=v[i]){
                while(s.top()<=v[i]){
                    //같으면 팝연산
                    if(s.top()==v[i]){
                        s.pop();
                        answer.push_back('-');
                        break;
                    }else{
                        //top이 작으니까 푸쉬연산
                        s.push(number++);
                        answer.push_back('+');
                    }
                }
            }
//            else if(s.top()==v[i]){
//                s.pop();
//                answer.push_back('-');
//            }
        }
    }
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<"\n";
    }
    return 0;
}
