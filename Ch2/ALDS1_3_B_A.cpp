/*
* 挑战程序设计竞赛2 第四章 第二题 queue
* http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_3_B
*/

# include <cstdio>

static const int maxn = 100000 + 5;
int Q[maxn], n, q, head, tail;

struct Job {
	char name[15];
	int time;
} job[maxn];

void dequeue() {
	head = (head+1) % maxn;
}

void enqueue(int x) {
	Q[tail] = x;
	tail = (tail+1) % maxn;
}

int main() {
	// 输入输出重定向
	// freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	
	scanf("%d%d", &n, &q); 
	for (int i = 0; i < n; i++) {
		scanf("%s%d", job[i].name, &job[i].time);
		Q[i] = i;
	}
	head = 0; tail = n; // 初始化队列的头和尾
	int p, t = 0; // p是正在操作的任务，t是目前的时间
	while (head != tail) {
		// printf("head is %d, tail is %d\n", head, tail);
		p = Q[head];
		dequeue();
		if (job[p].time <= q) {
			t += job[p].time;
			printf("%s %d\n", job[p].name, t);
		}
		else {
			t += q;
			job[p].time -= q;
			enqueue(p);	
		}
	}
	return 0;
}