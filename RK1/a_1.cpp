#include <iostream>
#include <vector>
using namespace std;

int main () {

	int N1, N2, count=0, i=0, j=0;

	cin >> N1 >> N2;
    vector <int> arr1(N1,0);
	vector <int> arr2(N2,0);

	for (int i=0; i<N1; i++) cin >> arr1[i];
	for (int i=0; i<N2; i++) cin >> arr2[i];

	while (i<N1 && j<N2) {
		if (arr1[i] == arr2[j]) {count++; i++; j++;}
		if (arr1[i] > arr2[j]) j++;
		if (arr1[i] < arr2[j]) i++;
	}

	cout << count;

	return 0;
}
