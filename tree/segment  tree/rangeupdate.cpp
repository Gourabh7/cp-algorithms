#include<bits/stdc++.h>
using namespace std;
#define int  long long int 
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define pf push_front
#define popb pop_back
#define popf pop_front
#define all(a) a.begin(), a.end()
#define mp make_pair
#define mod 1000000007
#define nl '\n'
int gcd(int a, int b)  
{  
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
}
int lcm(int a, int b)  
{  
    return (a / gcd(a, b)) * b; 
}  
bool compare(pair<int,int> &p1, pair<int,int> &p2)
{
    if(p1.first!=p2.first)
    return p1.first>p2.first;
    return p1.second<p2.second;
}
void build(int ind,int low,int high,vector<int>&arr,vector<pair<int,int>>&seg){
    if(low == high){
    seg[ind].first = arr[low];
    return;
    }
    int mid = low+(high-low)/2;
    build(2*ind+1,low,mid,arr,seg);
    build(2*ind+2,mid+1,high,arr,seg);
    seg[ind].first = seg[2*ind+1].first+seg[2*ind+2].first;
}
void update(int ind,int low,int high,int l,int r,int val,vector<int>&arr,vector<pair<int,int>>&seg){
            if(seg[ind].second!=0){
            seg[ind].first =seg[ind].first+(high-low+1)*seg[ind].second;
            if(low!=high){
            seg[2*ind+1].second += seg[ind].second;
            seg[2*ind+2].second += seg[ind].second; 
            }
       
            seg[ind].second=0;
    }
    if(low>r || high<l || low>high){
        return;
    }

    if(low>=l && high<=r){
        seg[ind].first = seg[ind].first+(high-low+1)*(val+seg[ind].second);
        if(low!=high){
        seg[2*ind+1].second += (seg[ind].second+val);
        seg[2*ind+2].second += (seg[ind].second+val);
        }

        seg[ind].second =0;
        return;
    }

    int mid = low+(high-low)/2;

        update(2*ind+1,low,mid,l,r,val,arr,seg);
        update(2*ind+2,mid+1,high,l,r,val,arr,seg);
    

    seg[ind].first = seg[2*ind+1].first+seg[2*ind+2].first;
}
int query(int ind,int low,int high,int l,int r,vector<int>&arr,vector<pair<int,int>>&seg){
               if(seg[ind].second!=0){
            seg[ind].first =seg[ind].first+(high-low+1)*seg[ind].second;
            if(low!=high){
            seg[2*ind+1].second += seg[ind].second;
            seg[2*ind+2].second += seg[ind].second; 
            }
       
            seg[ind].second=0;
    }
    if(low>r || high<l || low>high){
        return 0;
    }

    if(low>=l && high<=r){

        return seg[ind].first;
    }

    int mid   = low+(high-low)/2;
    int left = query(2*ind+1,low,mid,l,r,arr,seg);
    int right = query(2*ind+2,mid+1,high,l,r,arr,seg);

    return seg[ind].first = left+right;
}
int max(int a,int b){if(a>b)return a;return b;}
int min(int a,int b){ if(a<b)return a;return b;}
int computeXOR(int n)
{if (n % 4 == 0)  return n; if (n % 4 == 1) return 1; if (n % 4 == 2)   return n + 1; return 0;}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int uid(int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
#define fast_io      ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define out(v) for(int i = 0;i<v.size();i++){ cout<<v[i]<<" ";} cout<<nl;
#define pre(pref,v) for(int i = 0;i<v.size();i++) { pref.push_back(v[i]); if(i>=1) pref[i]+=pref[i-1];}
#define suf(suff,v) for(int i = 0;i<v.size();i++) {suff.push_back(v[i]); } for(int i=v.size()-2;i>=0;i--){ suff[i]+=suff[i+1];}
#define read(v,n) for(int i = 0;i<n;i++){ int p; cin>>p; v.push_back(p);}
main()  {
fast_io;
int t;
cin>>t;
vector<int>arr;
int n;
cin>>n;
for(int i = 0;i<n;i++){ 
    int p; cin>>p; arr.push_back(p);
}
vector<pair<int,int>>seg(4*n);
build(0,0,n-1,arr,seg);
while(t--) {

}
return 0;
}
