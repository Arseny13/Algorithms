#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
	double x, y;
	point(double x = 0, double y = 0): x(x), y(y) {}
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


int main ()
{
    int N,R;
    scanf("%d %d",&N,&R);
    vector<point> points(N);
    for(int i=0;i<N;i++){
        double x,y;
        scanf("%lf %lf", &x, &y);
		points[i].x = x;
		points[i].y = y;
    }

}
