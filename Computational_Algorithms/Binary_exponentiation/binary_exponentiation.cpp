#include<iostream>
#define ll long long 
using namespace std;

ll power(ll x ,ll n){
    ll ans;
    if(n==0){
        return 1;
    }
    if (n%2==0)
    {
       ans = power(x , n/2)*power(x , n/2);
    }
    else{
        ans = x*power(x,(n-1)/2)*power(x,(n-1)/2); 
    }
    // cout<<ans;
return ans;
 
}
int main()
{
    int x;
    cout<<"Enter the base value"<<endl;
    cin>>x;
    int n;
    cout<<"Enter the exponent value"<<endl;
    cin>>n;
    cout<<power(x,n);
    return 0;
}