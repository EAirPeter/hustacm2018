#include <cstdio>
#include <regex>

#include <iostream>

using namespace std;

int N, M, K;
int A[200001], B[100001];
int F[200001];

int X[11];

char SA[200001], SB[400001];

int main() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
		SA[i] = (char) (A[i] + 'A');
	}
	SA[N] = '\0';
	scanf("%d", &M);
	int cb = 0, xx = 0;
	for (int i = 0; i < M; ++i) {
		scanf("%d", &B[i]);
		if (X[B[i]]) {
			SB[cb++] = '\\';
			SB[cb++] = (char) (X[B[i]] + '0');
		}
		else {
			SB[cb++] = '(';
			SB[cb++] = '.';
			SB[cb++] = ')';
			X[B[i]] = ++xx;
		}
	}
	SB[cb] = '\0';
	regex rex(SB, SB + cb);
	match_results<char *> mr;
	regex_search(SA, SA + N, mr, rex);
	for (auto &&v : mr) {
		cout << v << endl;
	}
	printf("%d\n", (int) mr.size() - xx);
	return 0;
}
