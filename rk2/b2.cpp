#include <iostream>
#include <queue>

using namespace std;

using ll=long long;

int main() {
    std::priority_queue< long long, std::vector<long long>, std::greater<long long> > pq;
    ll n,k,x=0,z=0;

    cin>>n>>k;
    vector<ll> v;
    for(int i=0;i<k;i++)
        {
        scanf("%lld",&x);
        pq.push(x);
        }

    for(int i=0;i<(n-k);i++){
        z=pq.top();
        scanf("%lld",&x);
        if(x>z){
           pq.pop();
           pq.push(x);
        }
    }


    for(int i=0;i<k;i++){
        ll c=pq.top();
        v.push_back(c);
        pq.pop();
    }


    for(int i=0;i<k;i++){
        printf("%lld\n", v[k-i-1] );

    }

    return 0;
}
