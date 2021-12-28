#include<iostream>
using namespace std;
typedef struct node
{
	int info;
	node* next;
};
typedef struct listnode
{
	node* head;
	node* tail;
};
node* createnode(int x) {
	node* p;
	p = new node;
	if (p == NULL)
	{
		cout << "\nkhong du bo nho:";
		exit(1);
	}
	p->info = x;
	p->next = NULL;
	return p;
}
void inserttail(listnode& l, int x) {
	node *p = createnode(x);
	if (p==NULL)
	{
		cout << "\nKhong tao duoc nut moi:";
		exit(1);
	}
	else if (l.head == NULL)
	{
		l.head = l.tail = p;
	}
	else {
		l.tail->next = p;
		l.tail = p;
	}
}
void deletehead(listnode& l) {
	node* p;
	if (l.head != NULL) {
		p = l.head;
		l.head = l.head->next;
		delete p;
		if (l.head == NULL) l.tail = NULL;
	}
}
void deleteafter(listnode& l, node* q) {
	node* p;
	if (q != NULL)
	{
		p = q->next;
		if (p != NULL) {
			if (p == l.tail) l.tail = q;
			q->next = p->next;
			delete p;
		}
	}
}
void xoaphantuk(listnode &l, int k) {
	node* p;
	p = l.head;
	if (k > 0) {
		if (k == 1) deletehead(l);
		else {
			int i = 1;
			while (p != NULL && i <= k - 2) {
				i++;
				p = p->next;
			}
			if (p != NULL) deleteafter(l, p);
		}
	}
}
void output(listnode& l) {
	node* p;
	p = l.head;
	while (p!= NULL)
	{
		cout << p->info << " ";
		p = p->next;
	}
}
int main() {
	listnode l;
	l.head = l.tail = NULL;
	int x;
	cout << "\nNhap Gia Tri nut, Nhap 0 de Thoat:";
	cin >> x;
	while (x!=0)
	{
		inserttail(l, x);
		cout << "\nNhap Gia Tri nut, Nhap 0 de Thoat:";
		cin >> x;
	}
	cout << "\nDanh sach moi tao:";
	output(l);
	cout << "\nThem vao cuoi danh sach:";
	cout << "\nNhap Gia Tri nut, Nhap 0 de Thoat:";
	cin >> x;
	while (x != 0)
	{
		inserttail(l, x);
		cout << "\nNhap Gia Tri nut, Nhap 0 de Thoat:";
		cin >> x;
	}
	cout << "\nDanh sach lien ke sau ke chen:";
	output(l);
	cout << "\nXoa Phan tu X trong danh sach:";
	cout << "\nNhap vao vi tri muon xoa:";
	cin >> x;
	xoaphantuk(l, x);
	cout << "\nDanh sach lien ke sau khi xoa:";
	output(l);
	return 0;
}