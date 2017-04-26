// prog lab.5(5.1.14).cpp: ���������� ����� ����� ��� ����������� ����������.
//
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
struct List { struct List *prev; struct List *next; unsigned int r; };    

void out(struct List* a, int la) {
	while (a->next != NULL) {
		std::cout << a->r;
		a = a->next;
	}
	std::cout << (a->r / int(powl(10, 8 - la % 8)));
}

void deletin(struct List* a) {
	struct List* t;
	while (a != NULL) {
		t = a;
		a = a->next;
		free(t);
	}
}

bool equal(struct List* a, struct List* b, int la, int lb) {
	if (la != lb) {
		return false;
	}
	while (a != NULL) {
		if (a->r != b->r) {
			return false;
		}
		a = a->next;
		b = b->next;
	}
	return true;
}

void dec(struct List* a) {
	while (a->r == 0) {
		a->r = 99999999;
		a = a->prev;
	}
	a->r--;
	return;
}

bool compare(struct List* a, struct List* b, int la, int lb) {
	if (la>lb) {
		return true;
	}
	if (lb>la) {
		return false;
	}
	while (a->r == b->r) {
		a = a->next;
		b = b->next;
	}
	if (a->r > b->r) {
		return true;
	}
	return false;
}

struct List* convert(struct List* a, char* c, int l) {
	int i = 0, j;
	struct List* news;
	while (i<l) {
		j = 0;
		while (j <= 9999999 && c[i] != '\0') {
			j = j * 10 + c[i++] - 48;
		}
		news = (struct List*)malloc(sizeof(struct List));
		news->r = j;
		news->prev = a;
		news->next = NULL;
		if (a == NULL) {
			a = news;
		}
		else {
			a->next = news;
		}
		a = news;
	}
	while (a->r / 10000000 == 0 && a->r != 0) {
		a->r *= 10;
	}
	while (a->prev != NULL) {
		a = a->prev;
	}
	return a;
}

void algo(struct List* a, struct List* b, int &la, int &lb) {
	struct List* t = a, *tb;
	int tla = la;
	if (la == lb) {
		while (a != NULL) {
			if (a->r >= b->r) {
				a->r -= b->r;
			}
			else {
				a->r -= b->r - 100000000;
				dec(a->prev);
			}
			a = a->next;
			b = b->next;
		}
	}
	else {
		if (lb<8 && la>7) {
			a->r -= b->r / 10;
		}
		if (lb<8 && la<8) {
			a->r -= b->r / 10;
		}
		if (la>7 && lb>7) {
			a->r -= b->r / 10;
			a = a->next;
			b = b->next;
			while (b != NULL) {
				if (a->r >= (b->r / 10) + 10000000 * (b->prev->r % 10)) {
					a->r -= (b->r / 10) + 10000000 * (b->prev->r % 10);
				}
				else {
					a->r -= (b->r / 10) + 10000000 * (b->prev->r % 10) - 100000000;
					dec(a->prev);
				}
				tb = b;
				a = a->next;
				b = b->next;
			}
			if (a != NULL) {
				if (a->r >= 10000000 * ((tb->r) % 10)) {
					a->r -= 10000000 * (tb->r % 10);
				}
				else {
					a->r -= 10000000 * (tb->r % 10) - 100000000;
					dec(a->prev);
				}
			}
		}
	}
	while (t->r / 10000000 == 0) {
		la--;
		a = t;
		while (a->next != NULL) {
			a->r = (a->r % 10000000) * 10 + a->next->r / 10000000;
			a = a->next;
		}
		a->r = (a->r % 10000000) * 10;
	}
	a = t;
	tla = 8;
	while (tla<la) {
		tla += 8;
		a = a->next;
	}
	deletin(a->next);
	a->next = NULL;
}

int main()
{
	std::cout << "Type numbers:\n";
	char a[100], b[100];
	std::cin >> a >> b;
	std::cout << "Result: ";
	struct List* pa = NULL, *pb = NULL;
	int la = strlen(a), lb = strlen(b);
	if (la >= lb) {
		pa = convert(pa, a, la);
		pb = convert(pb, b, lb);
	}
	else {                       
		pa = convert(pa, b, lb);
		pb = convert(pb, a, la);
		la += lb;
		lb = la - lb;
		la -= lb;
	}
	while (!equal(pa, pb, la, lb)) {
		if (compare(pa, pb, la, lb)) {
			algo(pa, pb, la, lb);
		}
		else {
			algo(pb, pa, lb, la);
		}
	}
	out(pa, la);
	deletin(pa);
	deletin(pb);
	getch();
	return 0;
}

/*
#include "stdafx.h"
#include <iostream>


struct comp {
	char name[20]; // ��� ����������
	char value[10]; // �������� ����������
	comp* next; //������ �� �������� ������� ������
};
struct dyn_list {
	comp* head; // ������ ������� (������) ������
	comp* tail; // ��������� ������� (�����) ������
};
void constr_list(dyn_list &l)
{
	l.head = NULL;
}
bool chk_empty(dyn_list l)
{
	return (l.head == NULL);
}
int main()
{
	dyn_list vars;
	constr_list(vars);
    return 0;
}

*/