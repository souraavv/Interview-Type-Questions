
// Question : ( ) has score 1
// AB has score A+B , if A and B are balanced paranthesis;
// (A) has a score 2*A , if A is balanced


#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpi vector<pair<int, int>>
#define all(v) (v).begin(), (v).end()
#define pii pair<int, int>
#define f(i, l, n) for (int i = l; i < n; ++i)
#define fr(i, l, n) for (int i = l; i >= n; --i)
#define pb push_back    

const int N = 2e5 + 10;
const int mod = 1e9 + 7;

vvi g;

vi close;

int sol(int i,int j){
    
    if(i+1==j)return 1;
    
    int k=close[i]; 
    if(k==j)return sol(i+1,j-1)*2;
    
    return sol(i,k)+sol(k+1,j);
    
}


// Approach: 
// Find the closing bracet of the i index: and It will be either last or somewhere in between : So if it is at last then answer is 2*sol(i+1,j-1) 
// And if it is somewhere between then we know final answer will be the sum of solution of two individual sequences;
    
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin>>s;
    
    int n=s.size();
    close= vi(n,0);
    stack<char> S;
    
    for(int i=0;i<n;++i){
        if(s[i]==')'){
            close[S.top()]=i;
            S.pop();
        }
        else{
            S.push(i);            
        }
    }
    
    cout<<sol(0,n-1)<<"\n";
    return 0;
}


// sample input: (()(()))
// Sample Output: 6

