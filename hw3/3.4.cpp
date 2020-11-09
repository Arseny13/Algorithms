#include <cstdio>
#include <vector>

using namespace std;

union two_number{
	unsigned int a;
	unsigned short c[2];
};

int main()
{
	unsigned int N, K, M, L,NN = 65536;
	unsigned long long res = 0, totalcount = 0;
    vector<unsigned short> v[NN];
	scanf("%d %d %d %d", &N, &K, &M, &L);

	two_number x;

	x.a = K;
	v[x.c[1]].push_back(x.c[0]);

	for (unsigned int i = 0; i < N-1; ++i)
	{
		x.a = (unsigned int)((x.a*(unsigned long long)M)&0xFFFFFFFFU)%L;
		v[x.c[1]].push_back(x.c[0]);
	}

	for (unsigned int i = 0; i < NN; ++i)
		if(!v[i].empty())
		{
			vector<unsigned int> count(NN, 0);
			for(unsigned short elem: v[i])
				++count[elem];
			for (unsigned int j = 0; j < NN; ++j)
				if(count[j])
				{
					x.c[1] = i;
					x.c[0] = j;
					res += (((count[j] - (totalcount & 1u)) + 1u) >> 1u) * x.a;
					totalcount += count[j];
				}
		}
	printf("%llu ", res % L);
	return 0;
}
