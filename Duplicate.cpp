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

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin>>n;
    vi a(n);
    int x=0;
    for(int &i: a){
        cin>>i;
        x^=i;
    }
    
    int f=0;
    int i;
    for(i=30;i>=0;--i){
        if(x&(1<<i)){
            f=i;
            break;
        }
    }
    
    int u=0,v=0;
    for(int i=0;i<n;++i){
        if(a[i]&(1<<f))u^=a[i];
        else v^=a[i];
    }
    cout<<u<<" "<<v<<"\n";
    

    return 0;
}

/*  Sample Input:  8
                   3 4 8 2 1 2 8 3
                   
    Sample Output: 4 1

*/
