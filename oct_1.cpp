#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int const maxn=200005;
int n,q;
ll t[maxn*4];

ll get(int id,int l, int r, int u, int v){
    if(r<u || l>v) return 0;
    if(l>=u && r<=v) return t[id];
    ///de quy
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v) + get(id*2+1,mid+1,r,u,v);
}

void update(int id,int l, int r, int pos, int val){
    if(pos<l || pos>r) return;
    if(l==r){
        t[id]=val;
        return;
    }
    int mid=(l+r)/2;
    update(id*2,l,mid,pos,val);
    update(id*2+1,mid+1,r,pos,val);

    t[id]=t[id*2]+t[id*2+1];

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("ouput.txt","w",stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for(int i=0;i<n;i++){
        int x;cin >> x;
        update(1,0,n-1,i,x);
    }
    while(q--){
        int t;cin >> t;
        if(t==1){
            int x,v; cin >> x >> v;
            x--;
            update(1,0,n-1,x,v);
        }
        else{
            int l,r; cin >> l >> r;
            l--;r--;
            cout << get(1,0,n-1,l,r) << endl;
        }
    }

    return 0;
}
