#include <stdio.h>
#include <stdlib.h>

struct cell *stack = NULL;

struct cell{
	char c;
	struct cell *next;
};

void push(char c)
{
	struct cell *p = malloc(sizeof(struct cell));

	if(!p) exit(EXIT_FAILURE);
	p->c = c;
	p->next = stack;
	stack = p;
}

char pop(void)
{
	struct cell *p = stack;
	char c;

	if(!stack) return '\0';
	c = stack->c;
	stack = stack->next;
	free(p);
	return c;
}

void printstack(void)
{
	struct cell *p = stack;

	while(p){
		printf("%c", p->c);
		p = p->next;
	}
	putchar('\n');
}

void freestack(void)
{
	while(stack){
		struct cell *p = stack;

		stack = stack->next;
		free(p);
	}
}

int main(void){
    cell_t *top = NULL;
    printf("文字を一つ入力して下さい");
    char stdin,a;
    int k,i;
    while(1){
        scanf("%c",&stdin);
        if(stdin=='i'){
            printf("スタックに格納する数値を入力して下さい。\n");
            scanf("%c",&a);
			push(a);
            //*top = push(a,*top);
        }else if(stdin=='d'){
			printf("%cを削除しました",pop());
            //*top = pop(*top);
        }else if(stdin=='m'){
            printf("スタックから削除するデータ数を入力して下さい。\n");
            scanf("%d",&k);
            for(i=0,i<k;i++){
                *top = pop(*top);
            }
        }else if(stdin=='q'){
            printf("プログラムを終了します。\n");
            break;
        }else{
            printf("i,d,m,p,qのどれかを入力して下さい。\n");
        }
    }
}

/*
int main(void)
{
	const char *s = "Stack Test";

	while(*s){
		push(*s);
		printf("%c > ", *s ++);
		printstack();
	}
	while(stack){
		printf("%c < ", pop());
		printstack();
	}
	freestack();
	return 0;
}
*/
