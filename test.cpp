/*Dheeraj bhardwaj presents*/
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define pb push_back
#define pob pop_back
#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>
#define MOD 1000000007
#define inf 1e18
#define ff first
#define ss second
#define fo(i, a, b) for (int i = a; i < b; i++)
#define rfo(i, a, b) for (int i = a; i >= b; i--)
#define test int t
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
/*---------------------------------------------------------------------------------------------------------------------------*/
//Some predefined functions
int gcd(int a,int b)
{
     return b == 0 ? a : gcd(b, a % b);     //Euclid’s Algorithm       log(min(a, b))
}
int expo(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv(int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime(int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
void swap(int &x, int &y) {int temp = x; x = y; y = temp;}
int combination(int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
void google(int t) {cout << "Case #" << t << ": ";}
vector<int> sieve(int n){  vector<int> arr(n + 1, true);  vector<int> vect; for (int i = 2; i <= n; i++)   if (arr[i] == 1)   {      vect.push_back(i);      for (int j = 2 * i; j <= n; j += i)           arr[j] = 0;    } return arr;}
int lcm(int a,int b){ return (a*b)/gcd(a,b); }
bool comp(pair<int,int>a,pair<int,int>b)
{
    if(a.first<b.first) return true;
    else if(a.first==b.first)
    {
        if(a.second<b.second)
        return true;
        else
        return false;
    }
    return false;
}

void solve()
{
    //write your code here Dheeraj bhardwaj
    int n; cin>>n;
    int a[n],b[n];
    fo(i,0,n) cin>>a[i];
    fo(i,0,n) cin>>b[i];

    vector<pair<int,int>> va(n),vb(n),chk(n);
    fo(i,0,n){
        va[i]={a[i],i};
        vb[i]={b[i],i};
    }
    sort(va.begin(),va.end());
    sort(vb.begin(),vb.end());

    vi ans;
    int val=INT_MIN;
    fo(i,0,n){
        val=max(val,a[i]-b[i]);
        int x=vb[0].ff;
        int y=a[vb[0].ss];
        if(vb[0].ss==i){
            x=vb[1].ff;
            y=a[vb[1].ss];
        }

        int val1=a[i]+x;
        int val2=b[i]+y;
        if(val1<val2) continue;

        y=va[0].ff;
        x=b[va[0].ss];
        if(va[0].ss==i){
            y=va[1].ff;
            x=b[va[1].ss];
        }

        val1=a[i]+x;
        val2=b[i]+y;

        if(val1<val2) continue;

        ans.pb(i+1);

    }
    vi fg;
    fo(i,0,n){
        if(a[i]-b[i] == val){
            fg.pb(i+1);
        }}
       cout<<fg.size()<<endl;
fo(i,0,fg.size()) cout<<fg[i]<<" ";
    cout<<endl;
}

signed main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }

}