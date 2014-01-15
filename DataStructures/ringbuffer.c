/* E1020 芝田 将 */
#include <stdio.h>
#include <stdlib.h>

/* キューのサイズは5 */
#define QUEUE_SIZE 5

int queue[QUEUE_SIZE];
int queuehead,queuetail,queuelength;

/* キューの初期化 */
void init_queue() {
	queuehead = 0;
	queuetail = -1;
	queuelength = 0;
}

int next(int index) {
	return (index + 1) % QUEUE_SIZE;
}

void enqueue(int x) {
	//if (next(queuetail) == queuehead) {
	if (queuelength == QUEUE_SIZE) {
		printf("キューは満杯です.\n");
	}else{
		queue[next(queuetail)] = x;
		queuetail = next(queuetail);
		queuelength++;
	}
}

void dequeue() {
	int x;
	//if (queuehead == queuetail) {
	if (queuelength == 0) {
		printf("キューは空です.\n");
	}else{
		x = queue[queuehead];
		queuehead = next(queuehead);
		printf("%dを取り出しました.\n",x);
		queuelength--;
	}
}

void print_queue(){
	int i;
	for(i=0;i<queuelength;i++){
		printf("%d\n",queue[(queuehead+i)%QUEUE_SIZE]);
	}
}

int main(void){

	printf("文字を一つ入力して下さい\n");
	printf("i： 後に続いて入力されたデータをキューの末尾に挿入する．\n");
	printf("キューが満杯の場合はその旨をディスプレイに出力する．\n");
	printf("d： キューの先頭のデータを削除する．\n");
	printf("キューが空の場合はその旨をディスプレイに出力する．\n");
	printf("p： キューのデータを先頭から順番にディスプレイに出力する．\n");
	printf("q： 実行を終了する．\n");
	printf("上記以外： i，d，p，または q を入力する旨のメッセージをディスプレイに出力する．\n");

	int n;
	char c;
	init_queue();


	while(1){
		printf("\n>>>");
		scanf("%1s", &c);
		switch (c) {
			case 'i':
				scanf("%d", &n);
				enqueue(n);
				break;
			case 'd':
				dequeue();
				break;
			case 'p':
				print_queue();
				break;
			case 'q':
				exit(0);
				break;
			default:
				printf("i,d,p,またはqを入力して下さい。\n");
		}
	}
}
