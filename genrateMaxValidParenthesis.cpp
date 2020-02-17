// A string of parenthesis, alphabets, digits ( a(0)) or (#($)*) : Remove the minimum of brackets to get a balanced bracket sequence


#include<bits/stdc++.h>

using namespace std;
#define pb push_back

bool check(string s){
    int cnt=0;
    for(char c:s){
        if(c=='(')cnt++;
        if(c==')')cnt--;
        if(cnt<0)return 0;
    }
    return cnt==0;
}



int main(){
    
    string s;
    cin>>s;
    
    queue<string> q;
    q.push(s);
    map<string,int> vis;
    vector<string> ans;
    int lvl=0;
    while(!q.empty()){
        string u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        
        if(check(u)){
            lvl=1;
            ans.pb(u);
        }
        if(lvl)continue;
        
        for(int i=0;i<u.size();++i){
            if(u[i]=='(' or u[i]==')'){
                string n=u.substr(0,i)+u.substr(i+1,u.size());
                q.push(n);
            }
        }
        
    }
    for(string it: ans)cout<<it<<"\n";
    
}


/*
Sample Input : (a)())(#)
Sample Output:  (a())(#),(a)()(#)

*/
