#include <iostream>
using namespace std;

long powmod(long long a, long long k, long M)
{
  a=a%M;
  if (k==0) return 1;
  if (k==1) return a;
  if (k%2 == 0) return powmod(a*a,k/2,M)%M;
  else return (a*powmod(a*a,k/2,M)%M);
}



int main()
{
    cout<<1/2<<endl;
    long long  X , P ;
    long M;
    cin >> X >> P >> M ;
    cout << powmod (X,P,M);

    return 0;
}

