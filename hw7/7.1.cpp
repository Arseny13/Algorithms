#include <vector>
#include <stdio.h>
using namespace std;

const int QWE = 999999;

int f(int m,int n, vector<int> b){
    if (m<0) return QWE;
    if (m==0) return 0;
    int res = 0;
    for(int i=0;i<n;i++){
        int r = f(m-b[i],b,n);

    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> b{1,2,3,4,5,6};


}
