#include <iostream>
#include <vector>

using namespace std;
using ll = long long;


int main(){
    ll  A0,A1,N, M,sum;
    vector <long long> w(3,0);
    cin >> A0 >> A1 >> N >> M;
    w[0]=A0%M;
    w[1]=A1%M;
    for (ll i =2;i<=N;i++){
        sum +=(w[0]+w[1])%M;
        w[0]=w[1];
        w[1] = sum;
    }
    cout << sum;
    return 0;


}
