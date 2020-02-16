//
//  main.cpp
//  오픈채팅방
//
//  Created by kyuhwan cho on 16/02/2020.
//  Copyright © 2020 kyuhwan cho. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

pair<string, string> parse(string str){
    int flag = 0;
    string userId="";
    string name="";
    for(int i=0; i<str.length(); i++){
        if(str[i]==' '&& flag == 0){
            flag = 1;
        }else if(str[i]!=' '&&flag ==1){
            userId += str[i];
        }else if(str[i]==' '&&flag ==1){
            flag = 2;
        }else if(str[i]!=' '&&flag ==2){
            name += str[i];
        }
    }
    return make_pair(userId, name);
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> user;
    //save user in hash
    for(int i=0; i<record.size(); i++){
        pair<string, string> k = parse(record[i]);
        string userId=k.first;
        string name=k.second;
        if(record[i].find("Enter")!=-1){
            if (!user.insert(make_pair(userId,name)).second){
                auto it = user.find(userId);
                it->second = name;
            }
        }else if(record[i].find("Change")!=-1){
            auto it = user.find(userId);
            it->second = name;
        }
    }
    for(int i=0; i<record.size(); i++){
        pair<string, string> k = parse(record[i]);
        string userId=k.first;
        string name=k.second;
        if(record[i].find("Enter")!=-1){
            auto it = user.find(userId);
            answer.push_back(it->second+"님이 들어오셨습니다.");
        }else if(record[i].find("Leave")!=-1){
            auto it = user.find(userId);
            answer.push_back(it->second+"님이 나가셨습니다.");
        }
    }
    return answer;
}

int main(){
    vector<string> record;
    record.push_back("Enter uid1234 Muzi");
    record.push_back("Enter uid4567 Prodo");
    record.push_back("Leave uid1234");
    record.push_back("Enter uid1234 Prodo");
    record.push_back("Change uid4567 Ryan");
    vector<string> answer = solution(record);
    for(int i=0; i<answer.size(); i++){
        cout<<answer[i]<<"\n";
    }
}
