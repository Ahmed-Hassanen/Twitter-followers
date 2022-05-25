#include <bits/stdc++.h>
using namespace std;
vector<string> v;
map<long ,long> relations;
map<string,bool> ok;
vector<pair<long,long>> ans;
map<int,vector<int>> graph;
vector<pair<int,int>> close;
map<long,bool> ok2;
long id;
long n;
string s;
void read()
{
    ifstream fin;
    string line;
    // Open an existing file
    fin.open("twitter.csv");
    while(!fin.eof()){
        fin>>line;
        if(!ok[line]) {
            v.push_back(line);
            ok[line] = true;
        }
    }
}

int main(){

        read();
        for(long i=0;i<v.size();i++){
        long temp;
        for(long j=0;j<v[i].size();j++){
            if(v[i][j]==','){
                temp=j+1;
                break;
            }
        }
        long sum1=0,sum2=0;
        for(long j=temp;j<v[i].size();j++){
            sum2=sum2*10+(v[i][j]-'0');
        }
        for(long j=0;j<temp-1;j++){
            sum1=sum1*10+(v[i][j]-'0');
        }
        graph[sum1].push_back(sum2);
    }
    cout<<"enter id"<<endl;
    cin>>id;
    for(int i=0;i<graph[id].size();i++) ok2[graph[id][i]]=1;
    for(auto x:graph){
        int cnt=0;
        if(x.first==id) continue;
        for(int i=0;i<x.second.size();i++){
            if(ok2[graph[x.first][i]]) cnt++;
        }
        if(cnt) close.push_back({cnt,x.first});
    }
    sort(close.rbegin(),close.rend());
    if(close.size()!=0)
       for(int i=0;i<close.size();i++) cout<<close[i].second<<" ";
    else
       cout<<"no recommend"<<endl;
 
    return 0;



}