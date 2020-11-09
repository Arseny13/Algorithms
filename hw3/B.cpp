#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	short N, M;
	cin >> N >> M;
    vector< vector<size_t> > Matrix;
	for(size_t i = 0; i < N; ++i)
		{
			Matrix.push_back(vector<size_t> (M));
			for(size_t j = 0; j < M; ++j)
				cin >> Matrix[i][j];
		}
    size_t min = (1u<<31) -1;
		short min_i = 0;
		short min_j = 0;
		for(short i = 0; i < N; ++i)
		{
			for(short j = 0; j < M; ++j)
				if(Matrix[i][j] < min)
				{
					min = Matrix[i][j];
					min_i = i;
					min_j = j;
				}
		}

		vector<pair<size_t, short>> seq_i(N);
		vector<pair<size_t, short>> seq_j(M);

		for(short i = 0; i < N; ++i)
			seq_i[i] = {Matrix[i][min_j], i};

		for(short j = 0; j < M; ++j)
			seq_j[j] = {Matrix[min_i][j], j};

		sort(seq_j.begin(), seq_j.end());
		sort(seq_i.begin(), seq_i.end());

		for(size_t i = 0; i < N; ++i)
		{
			for(size_t j = 0; j < M; ++j)
				cout << Matrix[seq_i[i].second][seq_j[j].second] << ' ';
			cout << '\n';
		}


	return 0;
}
