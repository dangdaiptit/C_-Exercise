#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

//1: Khai bao CTDL DSLK Don cac so nguyen

struct Node {
	int Data;
	struct Node *pNext;
};
typedef struct Node NODE;

struct List {
	NODE *pHead;
	NODE *pTail;
};
typedef struct List LIST;

//2. Khoi tao DSLK Don
void Init(LIST &l) {
	l.pHead = l.pTail = NULL;
}

//3. Tao Node trong danh sach
NODE *GetNode(int x) { //x chinh la du lieu dua vao Data
	//Cap phat 1 Node
	//NODE *p = new NODE;
	NODE *p = (NODE*)malloc(sizeof(NODE));
	
	if(p == NULL){
		return NULL;
	}
	p->Data = x;
	p->pNext = NULL;
	return p;
}



//4. Them Node p vao dau danh sach
void AddHead(LIST &l, NODE *p) {
	
	if (l.pHead == NULL){ //tuc danh sach bi rong
		l.pHead = l.pTail = p;
	}
	else{
		p->pNext = l.pHead; //p quang day de tham gia vao DS
		l.pHead = p; //p chinh thuc da dung dau DS
		
	}
}

void AddTail(LIST &l, NODE *p) {
	if (l.pHead == NULL){
		l.pHead = l.pTail = p;
	}
	else {
		l.pTail->pNext = p;
		l.pTail = p;
	}	
}

//5. Nhap du lieu cho DS
void Input(LIST &l){
	int n;
	printf("Nhap so Node: ");
	scanf("%d", &n);
	Init(l);
	for(int i = 0; i<n; i++){
		
		int x;
		printf("Nhap Data: ");
		scanf("%d", &x);
		
		NODE *p = GetNode(x); //Dua data vao Node p, tao ra Node p
		AddTail(l, p);
//		AddHead(l, p);
		
	}
}

void OutPut(LIST l){
	printf("\n");
	for(NODE *p = l.pHead; p!= NULL; p = p->pNext){
		printf("%4d", p->Data);
	}
}

void timMax(LIST l){
	int max = l.pHead->Data;
	for(NODE *p = l.pHead->pNext; p != NULL; p = p->pNext){
		if(p->Data > max){
			max = p->Data;
		}
	}
	printf("\nMax = %d", max);
}

void swap(int &a, int &b){
	int temp = a;
	a = b;
	b = temp;
}

void Sort(LIST &l){
	for(NODE *p = l.pHead; p!= NULL; p = p->pNext){
		for(NODE *q = l.pHead; q != l.pTail; q = q->pNext){
			if(q->Data > (q->pNext)->Data){
				swap(q->Data, (q->pNext)->Data);
			}
		}
	}
	printf("\n");
	OutPut(l);
}

//them p vao sau q
void themSau(LIST &l, NODE *p, NODE *q){
	for(NODE *k = l.pHead; k != NULL; k = k->pNext){
		if(k->Data == q->Data){
			NODE *g = k->pNext;
			k->pNext = p;
			p->pNext = g;
			return;
		}
	}
}

//xoa dau, xoa cuoi, xoa sau 1 node bat ky

void XoaDau(LIST &l){
	NODE *p = l.pHead;
	l.pHead = l.pHead->pNext;
	free(p);
}

void XoaCuoi(LIST &l){
	NODE *p	; //p se la node nam truoc Tail tim thay
	for(NODE *k = l.pHead; k != NULL; k = k->pNext){
		if(k == l.pTail){
			l.pTail = p;
			l.pTail->pNext = NULL;
			free(k);
			break;
		}
		p = k;
	}
}
//Xoa Node nam sau Node q trong danh sach
void xoaSauMotNode(LIST &l, NODE *q){
	
	NODE*g;
	for(NODE *k = l.pHead; k!=NULL; k = k->pNext){
		if(k->Data == q->Data){
			g = k->pNext;
			k->pNext = g->pNext;
			free(g);
			break;
		}
	}
}

void XoaNodeKHoaBatKy(LIST &l, int data){
	if(l.pHead->Data == data){
		XoaDau(l);
		return;
	}
	if(l.pTail->Data == data){
		XoaCuoi(l);
		return;
	}
	
	//Neu Node can xoa k phai dau hoac cuoi
	//Tim ra Node nam truoc Node co khoa can xoa=> goi ham xoa Node 
	//sau cai Node vua tim thay
	
	NODE *q;
	for(NODE *g = l.pHead; g; g=g->pNext){
		if(g->Data == data){
			xoaSauMotNode(l,q);
			break;
		}
		q = g;
	}
}

//tim kiem
int TimKiem(LIST l, int data){
	for(NODE *q = l.pHead; q; q = q->pNext){
		if(q->Data == data){
			return 1;
		}
	}
	return 0;
}


void giaiPhong(LIST &l){
	NODE *p;
	while(l.pHead != NULL){
		p = l.pHead;
		l.pHead = l.pHead->pNext;
		free(p);
	}
}

int main(){
	LIST l;
	Input(l);
	OutPut(l);
//	timMax(l);
//	Sort(l);
//	
//	int p, q; 
//	printf("\nNhap q: ");
//	scanf("%d", &q);
//	
//	NODE *Q = GetNode(q);
//	
//	printf("\nNhap p: ");
//	scanf("%d", &p);
//	
//	NODE *P = GetNode(p);
//	
//	themSau(l, P, Q);
//	OutPut(l);
	//XoaDau(l);
//	XoaCuoi(l);
	
//	printf("\nXoa gia tri sau: ");
//	int q;
//	scanf("%d", &q);
//	NODE *Q = GetNode(q);
//	
//	xoaSauMotNode(l, Q);

//	printf("\nNhap gia tri can xoa: ");
//	int data;
//	scanf("%d", &data);
//	XoaNodeKHoaBatKy(l,data);

	printf("\nGia tri can tim: ");
	int data;
	scanf("%d", &data);
	int check = TimKiem(l, data);
	if(check == 1){
		printf("\nTim thay");
	}
	else printf("\nKhong tim thay");
	
	OutPut(l);
	getch();
	return 0;
}
