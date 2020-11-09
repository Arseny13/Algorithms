#include <stdio.h>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

int main()
{
	char str[10002];
	int N;
	int res,len;
	set<vector<unsigned short>> S;
	scanf("%d",&N);
	for(int i = 0; i < N; ++i)
	{
		vector<unsigned short> v(26, 0);
		scanf("%s", str);
        len = strlen(str);
		for(int j = 0; j < len; ++j)
			v[str[j]-'A']++;
		S.insert(v);
	}
	res = S.size();
	printf("%ld",res);
	return 0;
}
