long long sum_mod(long x,long degree,long *coefficient,long mod, long long sum0)
{
    long x_mod[2];


    if (x!=0)
        {
            x_mod[0]=1;
        for(int j=1;j<degree+1 ;j++)
            {
                x_mod[1]=(x_mod[0]*x)%mod;
                if (coefficient[j]!=0) sum0+= (x_mod[1]*(coefficient[j]));
                x_mod[0]=x_mod[1];
            }
        }
    return sum0%mod;
}

long long gorner(long x,long degree,long *coefficient,long mod)
{
    long long y=coefficient[degree];
    for (long i = degree ; i >= 1; i--)
    {
        y = (x*y + coefficient[i])%mod;
    }
    return y%mod;
}


#include <bits/stdc++.h>
using namespace std;



int main()
{
    long  N , M, MOD ;

    ifstream cin("imput_4.txt");
    ofstream cout("out.txt");
    cin >> N >> M >> MOD ;

    long a_k[N+1];

    for (long i=0;i<N+1;i++)
    {
        long a;
        cin>>a ;

        a_k[N-i]=a%MOD;

    }
    long long sum0=a_k[0];
    for (long index=0;index<M;index++)
    {
        long x;
        cin>> x;
        x%=MOD;
        cout << gorner(x,N,a_k,MOD)<<endl;
    }
unsigned int end_time = clock();

    return end_time/1000;
}
