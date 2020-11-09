#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
	int x, y;
	point(int x = 0, int y = 0): x(x), y(y) {}
};

double dist(const point &p1, const point &p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

bool isInside(const point &p1, const point &p, const point &p2)
{
    double d1 =  dist(p1, p);
    double d2 =  dist(p1, p2);
    return d2 > d1;
}

int scalar_prod(const point &p1,const point &p2,const point &p3){
    return (p1.x-p2.x)*(p3.y-p2.y) - (p1.y-p2.y)*(p3.x-p2.x);
    }



int main()
{
	int N;
	double res = 0;
	int P = 0;
	scanf("%d", &N);
	vector<point> points(N);
	vector<int> shell;
	for(int i = 0; i < N; ++i)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		points[i].x = x;
		points[i].y = y;
		if(y < points[P].y)
			P = i;
		else if(y == points[P].y && x < points[P].x)
			P = i;
	}

	shell.push_back(P);

	int first = P;
 	int cur = P;
	do
  	{
    	int next = (cur + 1) % N;
    	for (int i = 0; i < N; i++)
    	{
    		int sign = scalar_prod(points[cur],points[next],points[i]);
		    if (sign < 0)
		        next = i;
     		else if (sign == 0)
      		{
        		if (isInside(points[cur],points[next],points[i]))
          		next = i;
      		}
    	}
    	cur = next;
    	shell.push_back(next);
	}
  	while (cur != first);

	for(int i = 0; i < shell.size()-1; ++i)
		res += dist(points[shell[i]],points[shell[i+1]]);
	printf("%.2f\n", res);

	return 0;
}
