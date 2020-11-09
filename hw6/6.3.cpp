#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n,m,max=0;
    long long x;
    scanf("%d %d",&n,&m);
    vector<int> v(n, 0);
    unordered_map<int, vector<unsigned short>> map;
	for (int j = 0; j < m; ++j) {
		scanf("%lld",&x);
		map[x].push_back(0);
	}
    for (int i = 1; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			scanf("%ull",&x);

			if(map.find(x) == map.end())
				map[x].push_back(i);
			else {
				for (int k = 0; k < map[x].size(); ++k)
					++v[map[x][k]];
				map[x].push_back(i);
			}
		}
		for (unsigned short k = 0; k < i; ++k) {
			if(v[k] > max)
				max = v[k];
			v[k] = 0;
		}
	}
	printf("%d",max);
	return 0;
}
