#include <cstdio>

using namespace std;

long long N, M;

int main() {
	while (scanf("%lld%lld", &N, &M) == 2) {
		long long w = 0;
		auto K = N * M;
		long long f = N & 1 ? N : N - 1;
		long long t = 1;
		long long s = 1;
		long long i = 0;
		while (K > 0) {
			if (K > N * t) {
				K -= N * t;
				w += N;
			}
			else {
				auto p = (K + t - 1) / t;
				K -= p * t;
				w += p;
			}
			t += s;
			if (!(++i % f))
				s *= f + 1;
		}
		printf("%lld\n", w);
	}
	return 0;
}
