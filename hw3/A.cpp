#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
const int len=26;
int main(){
    vector <ll> v(len,0);
    ll buf;
    char c;
    //ifstream cin("input.txt");

    while (cin>>c){
        v[c-'A']++;
    }

    vector <ll> w(len,0);
    for(int i=0;i<len;i++){
        w[i]=v[i];
    }
    bool resort;
	do {
		resort = false;
		for (int i=0; i<len-1; i++) {
			if (w[i+1] > w[i]) {
				resort = true;
				buf = w[i];
				w[i] =w[i+1];
				w[i+1] = buf;
			}
		}
	} while (resort);

	int j = -1;

	for (int i=0; i<26 && w[i]; i++) {
		if (i && w[i-1] != w[i]) j=-1;
		while (v[++j] != w[i]);
		cout << (char)('A'+j) << ' ' << v[j] << "\n";
	}



    return 0;
}
