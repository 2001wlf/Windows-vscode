#include<iostream>
#include<cstdio>
#include<iterator>
#include<cstring>
#include<string>
#include<stack>
#include<algorithm>
#include<set>
#include<cmath>
#include<map>
#include<deque>
#include<queue>
#include<vector>
#include<iomanip>
#include<unordered_map>
#include<unordered_set>
using namespace std;
#define endl '\n'
#define sin scanf
#define sout printf
#define int long long
#define all(x) (x).begin(),(x).end() 
#define PII pair<int,int> 
typedef long long ll;
typedef unsigned long long ull;
const int INF=0x3f3f3f3f;
const int Mod=1e9+7;
const int maxn = 1e6+10;
template<class T>
inline void read(T &x)
{
    x=0;bool f=0;char ch=getchar();
    while(ch<'0'||ch>'9') {f|=(ch=='-');ch=getchar();}
    while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    x=f?-x:x;
    return;
}
string hxkc[10001]={"高等数学A（二）","C++程序设计","数据库系统原理及应用","离散数学","数据结构","计算机组成原理","操作系统","计算机网络","编译原理"};
struct kc{
      string name;
      double xf;
      double cj;
};
struct node
{
      string name;
      double totalhx;
      double xuefenhx;
      double totalcj;
      double totalxf;
      vector<kc>perkc;    
}no[maxn];
bool cmp(node a,node b)
{
      return a.totalcj*b.totalxf>b.totalcj*a.totalxf;
}
signed main()
{
      ios::sync_with_stdio(false);
      cin.tie(0),cout.tie(0);
      freopen("input.txt","r",stdin);
      int cnt=0;
      string name,kcm;
      double xf,cj;
      string lastname="";
      while(cin>>name)
      {
            if(name!=lastname)
                  cnt++;
            lastname=name;
            cin>>kcm;
            if(kcm=="国防教育")
            {
                  cin>>xf>>kcm;
                  continue;
            }
            cin>>xf>>cj;
            no[cnt].name=name;
            no[cnt].totalcj+=xf*cj;
            no[cnt].totalxf+=xf;
            no[cnt].perkc.push_back({kcm,xf,cj});
            for(auto x:hxkc)
            {
                  if(kcm==x)
                  {
                        no[cnt].totalhx+=xf*cj;
                        no[cnt].xuefenhx+=xf;
                  }
            }
           // cout<<name<<" "<<kcm<<" "<<xf<<" "<<cj<<endl;
      }
      sort(no+1,no+cnt+1,cmp);
      for(int i=1;i<=cnt;i++)
      {
            cout<<no[i].name<<" "<<no[i].totalcj/no[i].totalxf<<" "<<(no[i].totalhx/no[i].xuefenhx)*0.03<<endl;
            for(auto y:no[i].perkc)
            for(auto x:hxkc)
            {
                  if(y.name==x)
                  {
                        cout<<y.name<<"\t"<<y.xf<<"\t"<<y.cj<<endl;
                  }
            }
            cout<<endl;
      }
      return 0;
}