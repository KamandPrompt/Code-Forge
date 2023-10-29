#include<iostream>
#define ll long long //we define ll for long long data type
using namespace std;

ll power(ll x ,ll n){
    //we consider x as base and n as exponent
    ll ans;
    if(n==0){
        return 1; //if exponent is 0 then result will be 1
    }
    if (n%2==0)
    {
        // if n is then the property 4^4 = (4^2)*(4^2) can be used  
       ans = power(x , n/2)*power(x , n/2);
    }
    else{
        // if n is odd then the property 4^5 = 4*(4^2)*(4^2) can be used
        ans = x*power(x,(n-1)/2)*power(x,(n-1)/2); 
    }
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