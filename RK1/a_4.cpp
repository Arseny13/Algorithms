
/*#include <bits/stdc++.h>
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



*/

#include <iostream>
#include <vector>


using namespace std;

int main()
{

	size_t n, m, a;

	cin >> n >> m;
	vector<size_t> mas(n);

	for(size_t i = 0; i < n; ++i)
		cin >> mas[i];

	for(size_t i = 0; i < m; ++i)
	{
		cin >> a;
		size_t sum = 0, l = 0, r = 0;

		bool flag = false;

		while(l < n && r < n)
		{
			if(sum == a)
			{
				cout << l + 1 << ' ' << r + 1 << endl;
				flag = true;
				break;
			}

			if(sum < a)
				sum += mas[r++];
			else if(sum > a)
				sum -= mas[l++];

		}

		if(!flag)
			cout << "Not found" << endl;

	}

	return 0;
}
