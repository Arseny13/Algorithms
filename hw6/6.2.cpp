#include <stdio.h>
#include <unordered_set>
#include <vector>
#include <algorithm>
using ull = unsigned long long ;
using namespace std;


int main() {
    ull prost = 28813,h =0;
	unordered_set<ull> S;
	int N, M, K;
	ull curr;
	scanf("%d %d %d",&N,&M,&K);
	vector<ull> htable(M);
	htable[0] = 1;
	for (int j = 0; j < M; ++j)
		htable[j] =  prost *htable[j-1];

	for (int i = 0; i < N; ++i) {
        h = 0;
		vector <ull> v(M);
		for (int j = 0; j < M; ++j)
			scanf("%lld",&v[j]);
		sort(v.begin(), v.end());
		for (int j = 0; j < M; ++j)
			h += v[j] * htable[j];
		S.insert(h);
	}

	for (int i = 0; i < K; ++i) {
		h=0;
		vector <ull> v(M);
		for (int j = 0; j < M; ++j)
            scanf("%lld",&v[j]);
		sort(v.begin(), v.end());
		for (int j = 0; j < M; ++j)
			h += v[j] * htable[j];
		if(S.find(h) != S.end())
			printf("1\n");
		else
			printf("0\n");
	}

	return 0;
}
