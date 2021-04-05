#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct SinhVien{
	int id;
	char name[20];
};
typedef struct SinhVien SINHVIEN;

struct node{
	SinhVien data;
	struct node *pNext;
};
typedef struct node NODE;

struct List{
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

void Init(LIST &l){
	l.pHead = l.pTail = NULL;
}

NODE *getNode(SINHVIEN x){
	NODE *p = (NODE*)malloc(sizeof(NODE));
	if(p == NULL){
		return NULL;
	}
	else{
		p->data = x;
		p->pNext = NULL;
	}
}

void addHead(LIST &l, NODE *p){
	if(l.pHead == NULL){
		l.pHead = l.pTail = p;
	}
	p->pNext = l.pHead;
	l.pHead = p;
}

void addTail(LIST &l, NODE *p){
	if(l.pHead == NULL){
		l.pHead = l.pTail = p;
	}
	l.pTail->pNext = p;
	l.pTail = p;
}

void Input(LIST &l){
	int n;
	SINHVIEN x;
	printf("Nhap so luong SV: ");
	scanf("%d", &n);
	Init(l);
	for(int i = 0; i < n; i++){
		printf("Nhap id: ");
		scanf("%d", &x.id); fflush(stdin);
		printf("Nhap ten: ");
		gets(x.name);
		NODE *p = getNode(x);
		addTail(l, p);
	}	
}

void Ouput(LIST l){
	for(NODE *p = l.pHead; p; p = p->pNext){
		printf("\n%4d - %-8s", p->data.id, p->data.name);
	}
//	NODE *p = l.pHead;
//	while(p != NULL){
//		printf("\n%4d - %-8s", p->data.id, p->data.name);
//		p->pNext;
//		
//	}
}



int main(){
	LIST l;
	Input(l);
	Ouput(l);
	getch();
	return 0;
}
