/* E1020 芝田 将 */
#include <stdio.h>
#include <stdlib.h>


typedef struct cell{
	int item;
	struct cell *next;
}cell_t;

cell_t *listhead;

cell_t *lalloc(void){
	return((cell_t *) malloc(sizeof(cell_t)));
}

cell_t *initlist(void){
	cell_t *p;
	p = lalloc();
	p->next = NULL;
	return(p);
}

void insert(int x,cell_t *prev){
	cell_t *p;
	p = lalloc();
	p->item = x;
	p->next = prev->next;
	prev->next = p;
}

void delete(cell_t *prev){
	if(prev->next == NULL){
		printf("スタックは空です");
	}else{
		cell_t *q;
		q = prev->next;
		prev->next = prev->next->next;
	}
}

void print_list(cell_t *p){
	if(p!=NULL){
		printf("%d\n",p->item);
		print_list(p->next);
	}
}

cell_t *search(int x,cell_t *p);

int main(void){
	char c;
	int n,i,k;
	listhead = initlist();
	printf("文字を一つ入力して下さい\n");
	printf("i： 後に続いて入力されるデータをスタックに挿入する．\n");
	printf("d： スタックの先頭のデータを削除する．\n");
	printf("スタックが空の場合はその旨をディスプレイに出力する．\n");
	printf("m: 後に続いて入力される正整数をkとし，スタックの先頭からk個のデータを削除する．\n");
	printf("スタックからk個のデータを削除する前にスタックが空になった場合はその旨をディスプレイに出力する．\n");
	printf("p： スタックのデータを先頭から順番にディスプレイに出力する．\n");
	printf("q： 実行を終了する．\n");
	printf("上記以外： i，d，m, p，または q を入力する旨のメッセージをディスプレイに出力する．\n");

	while(1){
		printf("\n>");
		scanf("%1s", &c);
		switch (c) {
			case 'i':
				scanf("%d", &n);
				insert(n,listhead);
				break;
			case 'd':
				delete(listhead);
				break;
			case 'm':
				
				scanf("%d", &k);
				for(i=0;i<k;i++){
					delete(listhead);
				}
				break;
			case 'p':
				print_list(listhead->next);
				break;
			case 'q':
				exit(0);
				break;
			default:
				printf("i,d,m,p,またはqを入力して下さい。\n");
		}
	}
}


