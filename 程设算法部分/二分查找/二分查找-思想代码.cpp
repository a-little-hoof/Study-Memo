#include<iostream>
#include<set>
using namespace std;

int binary_search1(int a[],int size,int p){
    int s=0,e=size-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==p)
        return mid;
        if(a[mid]>p)
        e=mid-1;
        if(a[mid]<p)
        s=mid+1;
    }
    return -1;
}
int searched=-1;
void binary_search2(int a[],int p,int s,int e){
    if(s>e)
    return;
    int mid=s+(e-s)/2;
    if(a[mid]==p)
    searched=mid;
    if(a[mid]<p)
    binary_search2(a,p,mid+1,e);
    if(a[mid]>p)
    binary_search2(a,p,s,mid-1);
}

int binary_search3(int a[],int size,int p){
    int s=0;
    int e=size-1;
    int lastp=-1;//至今为止找到的最优位置
    while(s<=e){
        int mid=s+(e-s)/2;
        if(a[mid]==p)
        {
            lastp=mid-1;
            break;
        }
        if(a[mid]>p)
        e=mid-1;
        if(a[mid]<p)
        {
            lastp=mid;
            s=mid+1;
        }
    }
    return lastp;
}

int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};

    set<int> st;
    for(int i=0;i<10;i++)
        st.insert(a[i]);
    auto pp=st.lower_bound(5);
    cout<<*pp<<endl;
    //集合做法，返回不小于该数的第一个迭代器

    cout<<binary_search1(a,10,5)<<endl;
    //二分查找
    binary_search2(a,5,0,9);
    cout<<searched<<endl;
    //递归形式

    cout<<binary_search3(a,10,5);
    //二分查找下界

    return 0;
}