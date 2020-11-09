#include <stdio.h>
#include <vector>
using namespace std;


long long inv(vector<long> &v,long l, long r){

	if(r - l == 1)
		return 0;

	long long res = 0;
	long m = (r + l) / 2;
	res += inv(v, l, m);
	res += inv(v, m, r);
	vector<long> tmp(r - l);
	long a = l, b = m;

	for(long i = 0; i < r - l; ++i)
	{
		if(a < m && b < r)
			if(v[a] <= v[b])
				tmp[i] = v[a++];
			else
			{
				res += m - a;
				tmp[i] = v[b++];
			}
		else
			if(a == m)
				tmp[i] = v[b++];
			else
				tmp[i] = v[a++];
	}


	copy(tmp.begin(), tmp.end(), v.begin() + l);

	return res;
}



int main(){
    long N;
	scanf("%ld", &N);
	vector<long> vec(N);

	for(long i = 0; i < N; ++i)
		scanf("%ld", &vec[i]);

	long long res = inv(vec, 0l, N);

	printf("%lld\n", res);

 	return 0;
}
