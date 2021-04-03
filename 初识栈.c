#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Node {
	int data;
	struct Node* next;
}Node, * PNode;
typedef struct Stack {
	PNode ptop;
	PNode pbottom;
}Stack, * PStack;
void init(PStack ps) {
	ps->ptop = (PNode)malloc(sizeof(Node));
	if (ps->ptop == NULL) {
		printf("动态内存分配失败");
		exit(-1);
	}
	else {
		ps->pbottom = ps->ptop;
		ps->ptop->next = NULL;  //ps指向的ptop 所指向的指针域要赋空值
	}
}
void push(PStack ps, int val) {

	PNode pnew = (PNode)malloc(sizeof(Node));
	pnew->data = val;
	pnew->next = ps->ptop;  //ps->ptop不能改成ps->pbottom
	ps->ptop = pnew;
}

void traverse(PStack ps)
{
	PNode p = ps->ptop;  //先定义一个临时变量来存放ptop
	while (p != ps->pbottom)
	{
		printf("%d  ", p->data);
		p = p->next;
	}
	printf("\n");
	return;
}
bool empty(PStack ps) {
	if (ps->ptop == ps->pbottom) {
		return true;
	}
	else {
		return false;
	}
}
bool pop(PStack ps, int *pval) {
	if (empty(ps))  //ps本身存放的就是S的地址
	{
		return false;
	}
	else {
		PNode r = ps->ptop;
		*pval = r->data;
		ps->ptop = r->next;
		free(r);
		r = NULL;  //这是一个习惯，防止r指针乱指
		return  true;
	}
}

void clear(PStack ps) {
	PNode p = ps->ptop;
	if (empty(ps)) {
		return;
	}
	else {
		PNode p = ps->ptop;
		PNode q = NULL;
		while (p != ps->pbottom) {
			q = p->next;
			free(p);
			p = q;
			
		}
		ps->ptop = ps->pbottom;
	}
}
int main() {
	Stack S;
	int val;
	init(&S);  //目的是为了造出一个空栈
	push(&S, 1);//压栈
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	push(&S, 6);
	traverse(&S);//遍历
	clear(&S);
	traverse(&S);//遍历

	if (pop(&S, &val)) {
		printf("出栈成功，出栈的值是%d \n",val);
	}
	else {
		printf("出栈失败");
	}
	traverse(&S);//遍历

	return 0;

}