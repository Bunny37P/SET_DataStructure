#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long int
using namespace std;
class SET
{
    public:
    vector<ll> v,v1,v2,v3,v4;
    ll n,n1;
    ll Insert(ll x)
    {
        if(find(v.begin(),v.end(),x)==v.end())
        {
            v.push_back(x);
        }
        n=v.size();
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<n-i-1;j++)
            {
                if(v[j]>v[j+1]) swap(v[j],v[j+1]);
            }
        }
        return v.size();
    }
    ll Delete(ll x)
    {
        for(ll i=0;i<n;i++)
        {
            if(v[i]==x)
            {
                v.erase(v.begin()+i,v.begin()+i+1);
                break;
            }
        }
        return v.size();
    }
    bool Belongs_to(ll x)
    {
        return binary_search(v.begin(),v.end(),x);
    }
    ll Union(SET s2)
    {
        v1=v;
        for(auto i : s2.v)
        {
            if(find(v1.begin(),v1.end(),i)==v1.end()) v1.push_back(i);
        }
        n1=v1.size();
        for(ll i=0;i<n1;i++)
        {
            for(ll j=0;j<n1-i-1;j++)
            {
                if(v1[j]>v1[j+1]) swap(v1[j],v1[j+1]);
            }
        }
        v=v1;
        return v1.size();
    }
    ll Intersection(SET s2)
    {
        for(auto i : v)
        {
            if(find((s2.v).begin(),(s2.v).end(),i)!=(s2.v).end())
            {
                v3.push_back(i);
            }
        }
        n1=v3.size();
        for(ll i=0;i<n1;i++)
        {
            for(ll j=0;j<n1-i-1;j++)
            {
                if(v3[j]>v3[j+1]) swap(v3[j],v3[j+1]);
            }
        }
        v=v3;
        return v3.size();
    }
    ll Size()
    {
        return v.size();
    }
    ll Difference(SET s2)
    {
        for(auto i : v)
        {
            if(find(s2.v.begin(),s2.v.end(),i)==s2.v.end())
            {
                v2.push_back(i);
            }
        }
        v=v2;
        return v.size();
    }
    ll Symmetric_Difference(SET s2)
    {
        for(auto i : v)
        {
            if(find(s2.v.begin(),s2.v.end(),i)==s2.v.end())
            {
                v4.push_back(i);
            }
        }
        for(auto i : s2.v)
        {
            if(find(v.begin(),v.end(),i)==v.end()&&find(v4.begin(),v4.end(),i)==v4.end())
            {
                v4.push_back(i);
            }
        }
        n1=v4.size();
        for(ll i=0;i<n1;i++)
        {
            for(ll j=0;j<n1-i-1;j++)
            {
                if(v4[j]>v4[j+1]) swap(v4[j],v4[j+1]);
            }
        }
        v=v4;
        return v.size();
    }
    void Print()
    {
        for(auto i : v)
        {
            cout<<i<<",";
        }
        cout<<endl;
    }
};
int main()
{
   int a,b,c,m,i;
   vector<SET> s(100001);
   ll arr[100001];
   m=0;
   while(true){
   cin>>a>>b>>c;
   i=b;
     if(a==1)
     {
        cout<<s[i].Insert(c)<<endl;
        arr[i]++;
     }
     else if(a==2)
     {
        if(arr[i]!=0) cout<<s[i].Delete(c)<<endl;
        else cout<<-1<<endl;
     }
     else if(a==3)
     {
        if(arr[i]!=0) cout<<s[i].Belongs_to(c)<<endl;
        else cout<<-1<<endl;
     }
     else if(a==4)
     {
        cout<<s[i].Union(s[c])<<endl;
        arr[i]++;arr[c]++;
     }
     else if(a==5)
     {
        cout<<s[i].Intersection(s[c])<<endl;
        arr[i]++;arr[c]++;
     }
     else if(a==6)
     {
        cout<<s[i].Size()<<endl;
        arr[i]++;
     }
     else if(a==7)
     {
        cout<<s[i].Difference(s[c])<<endl;
        arr[i]++;arr[c]++;
     }
     else if(a==8)
     {
        cout<<s[i].Symmetric_Difference(s[c])<<endl;
        arr[i]++;arr[c]++;
     }
     else if(a==9)
     {
        if(arr[i]!=0) s[i].Print();
        else cout<<endl;
     }
   }
}
