/*
	�������
�� ���� ������� ����� N, ������ �������� ���� ����������� �������������������.
����� ������� N ��������� ������ ������������������ � N ��������� ������ ������������������.
��������� ������� ��������� ������ ���� ����� ��������� ������������������, ������� ���������� �� �� ���� ��������� ������ � ������ �������������������, ������� �� �������� ������.
	Input format
N
A1
A2
...
AN
B1
B2
...
BN
	Output format
Result
	Examples
Input	Output
5
1
1
3
7
9
3
7
8
9
10
	28
*/

#include <iostream>
#include <vector>

using namespace std;

const int M=1000000000;

int main () {
	vector <int> arr;
	int N, num, ans = 0, iter = 0;

	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> num;
		arr.push_back(num);
	}

	for (int i=0; i<N; i++) {
		cin >> num;
		while (iter < N && arr[iter] <= num) {
			if ((iter+i+1)%2) {ans = (ans + arr[iter] % M) % M;}
			iter++;
		}
		if ((iter+i+1)%2) {ans = (ans + num % M) % M;}
	}

	while (iter < N) {
		if ((iter+N+1)%2) {ans = (ans + arr[iter] % M) % M;}
		iter++;
	}

	ans = ans % M;

	cout << ans;

	return 0;
}
