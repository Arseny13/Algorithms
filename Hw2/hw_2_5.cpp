#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
const unsigned long MAX = 20000000;

int main()
{
    unsigned long m, n;
    vector<bool> w(MAX, true);

	long k = -1;

	scanf("%ld %ld", &m, &n);

	for(unsigned long p = 2; p*p < MAX; ++p){
		if(w[p])
			for(unsigned long j = p*p; j < MAX; j += p)
				w[j] = false;
	}

	unsigned long l = 2, r = n + 1, count = 0;

	for(unsigned long i = l; i <= r; ++i)
		if(w[i]) ++count;


	for(unsigned long i = l; i < MAX - n; ++i)
	{
		if(count == m)
		{
			k = i;
			break;
		}
        if(w[++r]) ++count;
		if(w[l++]) --count;
	}


	printf("%ld", k);


	return 0;

}
