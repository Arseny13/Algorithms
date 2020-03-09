#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main()
{
    long N;
    cin >>N;
    if (N==0){cout<<0; return 0;}
    vector <double> arr(N);
    for (long i=0;i<N;i++)
        {
            double x;
            cin>>x;
            arr[i]=x;
        }
    sort(arr.begin(),arr.end());
    long count_interval =1;
    long index =1;
    double block =arr[0]+1.001;
    while(index<N)
    {
        if (arr[index]<=block) index++;
        else {count_interval++; block=arr[index]+1.001;index++;}
            }


cout<< count_interval;
return 0;
}
