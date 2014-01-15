/* E1020 芝田 将 */
#include <stdio.h>
#include <stdlib.h> //いらないかも
#include <string.h>

typedef struct cell {
    int *item;
    int *next;
} cell_t;


cell_t *push(int x,cell_t *top){
    cell_t *p;
    p = lalloc();
    p->item = x;
    p->next = top;
    return(p);
} /* push */


cell_t *pop(cell_t *top){
    int x;
    if(top!=NULL){
        x = top->item;
        top = top->next;
        printf("データ%dを取り出しました。\n",x);
        return(top);
    }else{
        printf("スタックは空です。\n");
    }
} /* pop */

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
            *top = push(a,*top);
        }else if(stdin=='d'){
            *top = pop(*top);
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
