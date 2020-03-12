
#include <bits/stdc++.h>
#include <algorithm>
using ll= long long;
using namespace std;

int solve (vector <long> v,long N,long b){

}




int main()
{
    long  N , M ;
    long long sum=0;
    cin >> N >> M ;
    vector <long>  v(N);
    for(long i=0;i<N;i++){
        long a;
        cin>>a;
        v[i]= a;
        sum+=a;

    }
    for(long i=0;i<M;i++){
        long b;
        int z;
        cin>> b;
        int k=0;
        for ( int i=1 ; i<N ; i++ ) {

            int j, Summ=0;
            for ( j=0 ; j<i ; j++ )
                Summ+=v[j];
            if ( Summ== b )
            {
                cout <<j-i+2<<" "<<j+2<<endl;
                k+=1;
                break;
            }

            if (k==0){
            for ( ; j<N ; j++ ) {
                Summ+=v[j]-v[j-i];
                if ( Summ==b )
                {
                    k+=1;
                    cout <<j-i+2<<" "<<j+2<<endl;
                    break;
                }
            }

        }
    }
    if(k==0) cout<< "Not found"<<endl;




    }
    return 0;
}



