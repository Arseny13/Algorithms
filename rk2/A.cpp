#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int w,h,n;
    cin >> w >> h >> n ;
    long long s = pow(w*h*n,0.5);

    while (n > (s/w) * (s / h)){
        if ((w - s % w) < (h - s % h))
            { s += (w - s % w);}
        else s += (h - s % h);
    }
    cout << s;
    return 0;

}


