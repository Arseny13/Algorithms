û #include <iostream>

#include <algorithm>

#include <vector>

using namespace std;

using ll=long long;

int main(void){
    int N,M;
    ll x=0;
    cin>>N>>M;
    vector<ll> vec(N);
    for(int k=0;k<N;k++){
        scanf("%lld", &vec[k]);
    }
    sort( vec.begin(), vec.end());

    //cout<<"y"<<endl;

    int i=0;
    int j=N-1;
    vector<ll> exm(M);


    for(int k=0;k<M;k++){
        scanf("%lld", &exm[k]);
    }

    //cout<<"ex"<<endl;

    for(int k=0;k<M;k++){
        ll z=0;
        i=0;
        j=N-1;
    while(i!=j){
        z=vec[i]+vec[j];

        if( z == exm[k]){
            printf("%lld ",vec[i]);
            printf("%lld\n",vec[j]);
            break;
        }

        if(z > exm[k]){
            j--;
        }
        if(z < exm[k]){
            i++;
        }

    }
    if(z!=exm[k])
        printf("Not found\n");
        continue;
    }


    return 0;
}
