#include <vector>
#include <stdio.h>
using namespace std;

int main(){
    unsigned int N,K,M,L;
    unsigned long long sum=0;
    scanf("%d %d %d %d",&N,&K,&M,&L);
    vector<unsigned int> v(N);
    vector<unsigned int> b(N,0);
    vector<vector<unsigned int>> k1(2,vector<unsigned int>(256,0));
    vector<vector<unsigned int>> k2(2,vector<unsigned int>(256,0));
    vector<vector<unsigned int>> k3(2,vector<unsigned int>(256,0));
    vector<vector<unsigned int>> k4(2,vector<unsigned int>(256,0));
    v[0] = K;

    for (int i = 0; i < N-1; i++) {
            v[i+1] = (unsigned int)((v[i]*(unsigned long long)M)&0xFFFFFFFFU)%L;
        }

    for (long i=0; i<N; i++) {
            k1[0][v[i] & 0x000000FFU]++;
            k2[0][(v[i] >> 8) & 0x000000FFU]++;
            k3[0][(v[i] >> 16) & 0x000000FFU]++;
            k4[0][(v[i] >> 24)]++;
        }

	for (int i=1; i<256; i++) {
            k1[1][i] = k1[0][i-1] + k1[1][i-1];
            k2[1][i] = k2[0][i-1] + k2[1][i-1];
            k3[1][i] = k3[0][i-1] + k3[1][i-1];
            k4[1][i] = k4[0][i-1] + k4[1][i-1];
        }

	for (long i=0; i<N; i++) {
            b[k1[1][v[i] & 0x000000FFU]++] = v[i];
        }

	for (long i=0; i<N; i++) {
            v[k2[1][(v[i] >> 8) & 0x000000FFU]++] = b[i];
        }

	for (long i=0; i<N; i++) {
            b[k3[1][(v[i] >> 16) & 0x000000FFU]++] = v[i];
        }

	for (long i=0; i<N; i++) {
            if ((k4[1][b[i] >> 24]++) % 2 == 0) sum+= b[i];
        }

    sum %=L;
    printf("%llu",sum);
    return 0;

}
