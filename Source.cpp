#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <crtdbg.h> 

#ifdef DEBUG
#define _CRTDBG_MAP_ALLOC
#endif

using namespace std;

struct TNode
{
	double Data;
	TNode *Left;
	TNode *Right;
};
typedef TNode *PNode;

void Add(PNode &Root, double x)//Добавление элемента
{
	if (!Root)
	{
		Root = new (TNode);
		Root->Data = x;
		Root->Left = NULL;
		Root->Right = NULL;
		return;
	}
	if (x < Root->Data)
		Add(Root->Left, x);
	else
		Add(Root->Right, x);
}

void Print(PNode Root, int lvl)//печать дерева
{
	if (Root)
	{
		Print(Root->Left, lvl + 1);
		for (int i = 0; i < lvl; i++)
			cout << "   ";
		cout << Root->Data << endl;
		Print(Root->Right, lvl + 1);
	}
}

void DeleteRoot(PNode Root)//удаление дерева
{
	if (Root)
	{
		DeleteRoot(Root->Left);
		DeleteRoot(Root->Right);
		delete Root;
	}
}

int main()
{
	PNode Root=NULL;
	int n;
	cin >> n;
	double x = 0;
	srand(time(0));
	for (int i = 0; i < n; i++)//Созднание дерева из n вершин
	{
		x = rand() % 100001 - 50000;
		Add(Root, x);
	}
	Print(Root, 0);
	DeleteRoot(Root);
	_CrtDumpMemoryLeaks();
	return 0;
}