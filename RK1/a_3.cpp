#include <iostream>
#include <vector>

using namespace std;
using ll = long long;



auto mult(vector<vector<ll>> & mat1, vector<vector<ll>> & mat2, ll m)
{
	auto dot = mat1;
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			dot[i][j] = ((mat1[i][0] * mat2[0][j]) % m + (mat1[i][1] * mat2[1][j]) % m) % m;

	return dot;
}




 vector<vector<ll>> pow_mat(vector<vector<ll>> &mat, ll N,ll M){


	if(N == 1)
		return mat;

	if(N & 1) {

		auto b = pow_mat(mat, N - 1, M);
		return mult(mat, b, M);
	}

	auto b = pow_mat(mat, N/2, M);
	return mult(b, b, M);

 }






int main(){
    ll  A0,A1,N, M;

    vector <ll> w(2,0);
    cin >> A0 >> A1 >> N >> M;
    w[0]=A0%M;
    w[1]=A1%M;
    if (N==0) cout << w[0];
    vector <vector<ll>> v{{0,1},{1,1}};
    auto mat2 = pow_mat(v, N, M);

	cout << ((mat2[0][0] * w[0]) % M + (mat2[0][1] * w[1]) % M) % M << endl;



    return 0;


}
