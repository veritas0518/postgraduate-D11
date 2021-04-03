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
		printf("��̬�ڴ����ʧ��");
		exit(-1);
	}
	else {
		ps->pbottom = ps->ptop;
		ps->ptop->next = NULL;  //psָ���ptop ��ָ���ָ����Ҫ����ֵ
	}
}
void push(PStack ps, int val) {

	PNode pnew = (PNode)malloc(sizeof(Node));
	pnew->data = val;
	pnew->next = ps->ptop;  //ps->ptop���ܸĳ�ps->pbottom
	ps->ptop = pnew;
}

void traverse(PStack ps)
{
	PNode p = ps->ptop;  //�ȶ���һ����ʱ���������ptop
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
	if (empty(ps))  //ps�����ŵľ���S�ĵ�ַ
	{
		return false;
	}
	else {
		PNode r = ps->ptop;
		*pval = r->data;
		ps->ptop = r->next;
		free(r);
		r = NULL;  //����һ��ϰ�ߣ���ֹrָ����ָ
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
	init(&S);  //Ŀ����Ϊ�����һ����ջ
	push(&S, 1);//ѹջ
	push(&S, 2);
	push(&S, 3);
	push(&S, 4);
	push(&S, 5);
	push(&S, 6);
	traverse(&S);//����
	clear(&S);
	traverse(&S);//����

	if (pop(&S, &val)) {
		printf("��ջ�ɹ�����ջ��ֵ��%d \n",val);
	}
	else {
		printf("��ջʧ��");
	}
	traverse(&S);//����

	return 0;

}