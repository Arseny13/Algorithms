#include <iostream>
#include <vector>

using namespace std;

long long fact(long long n){
    if(n == 0) return 1;
    if(n == 1) return 1;
    return n * fact(n - 1);
}


int main(){
    long long n, k, s, t;
    cin >> n >> k;
    s = k - 1;
    vector<long long> seq;
    vector<long long> fac;
    for(long long i = 0; i < n; i++){
     seq.push_back(i + 1);
     fac.push_back(fact(i));
    }
    fac.push_back(fact(n));
    for(long long i = 0; i < n; i++){
        s /= fac[n - 1 - i];
        if(s == 1 && n - 1 - i == 1)
            s = 0;

        if(s == n - i)
            s--;
        if(k == s * fac[n - 1 - i])
            s--;
        cout << seq[s] << ' ';
        seq.erase(seq.begin() + s);
        s = k - s * fac[n - i - 1];
        k = s;

    }
    return 0;
}
