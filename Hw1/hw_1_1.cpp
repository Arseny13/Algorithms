#include <iostream>
#include <cmath>
using namespace std;

int len_string(int N)
{
    return pow(2,N) -1;
}


int place(int x,int N)
{
    if (x==1 || (len_string(N)==1)) return 1 ; //
    else if (x<(len_string(N-1)+1) && x>1) return 2;
    else if (x>(len_string(N-1)+1) ) return 3;
    else return -9999;
}


void fill_array(int N,char *array)
{
    int index =0;
    for (char A = 'a'; A < 'a'+N; A++)
        {
            array[index]=A;
            index++;
        }

}

int main()
{
    int N,K,L;
    int k=0,n=0;
    cin >> N >> K >> L;
    char title[N];
    fill_array(N, title);
    for (K;K<=L;K++)
        {
            k=K;
            n=N;
            for (int i=0;i<N;i++){
D:\Progi\CodeBlocks\ASD\1sem
                if (place(k,n)==1) {cout<<title[N-i-1]; break;}
                if (place(k,n)==2) k--;
                if (place(k,n)==3) {k-= len_string(n-1)+1;}
                n-- ;
            }


        }

    return 0;

}
