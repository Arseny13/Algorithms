#include <stdio.h>
#include <vector>
#include <unordered_map>

using us = unsigned short;
using ul = unsigned long;

int main()
{
    ul m, n, i = 0, k;
	bool flag = false;
	scanf("%ld %ld", &m, &n);
	printf("0.");
	std::unordered_map<ul, ul> w;
	std::vector<us> x;

	while(1)
	{
	    if(w.find(m) != w.end())
		{
			k = (*w.find(m)).second;
			flag = true;
			break;
		}

		w.insert(std::make_pair(m, i));
		++i;


		x.push_back((m * 10) / n);

		m = (m * 10) % n;

		if(m == 0)
			break;
	}
	if(flag)
	{
		for(ul i = 0; i < x.size(); ++i)
		{
			if(i == k)
				printf("(");
			printf("%d", x[i]);
		}
		printf(")");
	}
	else
		for(us n : x)
			printf("%d", n);
	return 0;
}
