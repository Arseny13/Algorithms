#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    int  pr = 113;
    string str;
	cin >> str;
	int len = str.size();

	vector<int> ptab(len, 1);
	for(int i = 1; i < len; ++i)
		ptab[i] = ptab[i-1]*pr;

	vector<int> htab(len+1, 0);
	for (int i = 1; i <= len; i++)
		htab[i] = htab[i-1] + (str[i-1]-'A'+1)*ptab[i-1];

	for(int l = 1; l < len + 1; ++l) {
		int x = 0;
		int hs2 = htab[x + l] - htab[x];
		int hs1 = hs2;
		bool answer = false;
		while(hs1 == hs2) {
			if(len - x < l) {
				answer = true;
				break;
			}
			hs1 = hs2 * ptab[l];
			x += l;
			if(len - x < l) {
				int u = len - x;
				hs1 = htab[x - l + u] - htab[x - l];
				hs1 *= ptab[l];
				hs2 = htab[x + u] - htab[x];
			}
			else
				hs2 = htab[x + l] - htab[x];
		}

		if(answer) {
			cout << l;
			break;
		}

	}

	return 0;
}
