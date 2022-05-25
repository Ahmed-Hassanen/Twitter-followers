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

void write(){
    ofstream fin;
    fin.open("sorted.csv");

    for(int i=0;i<ans.size();i++){

        fin<<ans[i].second<<","<<ans[i].first<<endl;
    }

fin.close();
}

int main()
{
   read();
   // main project
    // select the person who followed in the map
    for(long i=0;i<v.size();i++){
        long temp;
        for(long j=0;j<v[i].size();j++){
            if(v[i][j]==','){
                temp=j+1;
                break;
            }
        }
        long sum=0,cnt=0;
        for(long j=temp;j<v[i].size();j++){
            sum=sum*10+(v[i][j]-'0');
            cnt++;
        }
        relations[sum]++;
    }
    // put into vector of pair to sort them
    for(auto x:relations){
        ans.push_back({x.second,x.first});
    }
    // sort them
    sort(ans.rbegin(),ans.rend());
     write();

    return 0;
}
