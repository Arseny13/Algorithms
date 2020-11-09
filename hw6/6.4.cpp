#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main () {
	string s;
	cin >> s;

	int max = 0;

	for (int len = 1; len<=s.length(); ++len) {

		unordered_map <string, int> m;
		for (int i=0; i<=s.length()-len; ++i) {
			if (m.find(s.substr(i, len))==m.end())
                m[s.substr(i, len)]=1;
			else {m[s.substr(i, len)] += 1;}
        for(auto x: m){
            if (x.second*len > max)
                max  = x.second*len;
        }
        m.clear();

		}
	}

	cout << max;

	return 0;
}
