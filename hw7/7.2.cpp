#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

int f(int i, int j,int X,int Y, vector<vector<char>> &v) {
	if(v[i][j]+1)
		return v[i][j] == 'w' ? 1 : 0;
	for(int y = 1; y < Y-j; ++y)
		if(!f(i, j+y,X,Y, v)) {
			v[i][j] = 'w';
			return 1;
		}
	for(int x = 1; x < X-i; ++x)
		if(!f(i+x, j,X,Y, v)) {
			v[i][j] = 'w';
			return 1;
		}
	for(int k = 1; k < min(X-i, Y-j); ++k)
		if(!f(i+k, j+k,X,Y, v)) {
			v[i][j] = 'w';
			return 1;
		}
	v[i][j] = 'l';
	return 0;
}

int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    vector<vector<char>> v(x,vector<char> (y,-1));
    if(f(0, 0,x,y, v))
		printf("F");
	else
		printf("S");
    return 0;


}
