// Your First C++ Program

#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5;
int t[4*maxn];
void build(int id,int l,int r,int i,int v){
    if(i<l || i>r){
        return;///nam ngoai doan [l,r]
    }
    if(l==r){
        t[id]=v;///l=r thì gán giá trị cho nút thứ id
        return;///điểm dừng
    }
    ///gọi đệ quy
    int mid=(l+r)/2;
    build(id*2,l,mid,i,v);
    build(id*2+1,mid+1,r,i,v);/// => gọi đệ quy 2 nút con có chỉ số 2*u và 2*u+1
    t[id]=max(t[id*2],t[id*2+1]);///cập nhật max nút cha dựa theo nút con
}

int get_sub(int id,int l,int r,int tl,int tr){
    if(tl>r || tr < l){///trường hợp đoạn [tl,tr] ko giao với đoạn [l,r] biểu diễn trên trục tọa độ
        return -maxn;///=>bỏ qua đoạn này và gán= vcb để 0 ảnh hưởng đến truy vấn tìm max
    }
    if(tl<=l && tr>=r){
        return t[id];
    }
    int mid=(l+r)/2;
    return max(get_sub(id*2,l,mid,tl,tr),get_sub(id*2+1,mid+1,r,tl,tr));
}
int main() {
    //std::cout << "Hello World!";
    int n,i,v;
    cout << "nhap n: ";
    cin >> n;
    cout << "nhap index va gia tri muon gan: ";
    cin >> i >> v;
    int a[n];
    cout << "nhap mang a: ";
    for(int i=0;i<n;i++) cin >> a[i];
    for(int id=0;id<n;id++){
        build(1,0,n-1,id,a[id]);///build cây segment ban đầu với giá trị tại mõi nút là max của đoạn nút con
    }
    /// check output
    cout << "mang ban dau:\n";
    for(int i=1;i<2*n;i++) cout << t[i] << " ";
    cout << endl;

    ///thay đổi giá trị phần tử thứ i thành v
    build(1,0,n-1,i,v);
    ///check output
    cout << "mang sau thao tac:\n";
    for(int i=1;i<2*n;i++) cout << t[i] << " ";
    cout << endl;

    int l,r; cout << "nhap doan muon truy van: ";
    cin >> l >> r;
    cout << "max trong doan " << l << " " << r << " la " << get_sub(1,0,n-1,l,r);
    return 0;
}
