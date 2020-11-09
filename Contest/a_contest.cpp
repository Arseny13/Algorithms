
#include <iostream>

using namespace std;

int main()
{   int N,a ;
    int min=0 ,k=0, x =0;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a;
        if (a!=5) x = -(a-5)/5 ;
        else x=1;
        k+=x;
        if (k<min) min=k;

    }

    cout<< -min;
    return 0;
}

