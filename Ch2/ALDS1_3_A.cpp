#include <cstdio>

static const int maxn = 100 + 5;
int s[maxn];
char buff[100];

int get_num(){
	int sum = buff[0] - '0';
	for (int i = 1; buff[i] != '\0'; i++) {
		sum = sum * 10 + buff[i] - '0';
	}
	return sum;
}

int main(){
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	int p = 0;
	while(scanf("%s", buff) == 1) {
		if (buff[0] == '+') {
			s[p-2] += s[p-1];
			p--;
		}
		else if (buff[0] == '-') {
			s[p-2] -= s[p-1];
			p--;
		}
		else if (buff[0] == '*') {
			s[p-2] *= s[p-1];
			p--;
		}
		else {
			s[p] = get_num();
			p++;
		}
	}
	printf("%d\n", s[0]);
	return 0;
}
