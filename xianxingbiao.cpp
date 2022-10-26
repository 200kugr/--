#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define OK 1  //执行成功
#define NO -1  //不存在
#define ERROR 0  //超出范围or执行失败
bool flag;
#define size 100//线性表存储空间的初始分配量
#define extra 10//分配增量

typedef int ElemType;


typedef struct {
	ElemType* elem; // 存储空间基质
	int length; // 当前长度
	int listsize; // 当前分配的存储容量（以sizeof（ElemType）为单位）
}SqList;

SqList L;
SqList lc;//合并表后的结果

//初始化线性表
int InitList(SqList& L) {
	L.elem = (ElemType*)malloc(size * sizeof(ElemType));//为数据元素开辟一维数组空间
	if (!L.elem) {
		cout << "线性表A存储分配失败，请您重新操作！" << endl;
		return ERROR;
	}
	else
	{
		L.length = 0;
		L.listsize = size;
		cout << "线性表的存储空间分配成功！" << endl;
		return OK;
	}
}

//销毁
int DestroyList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	flag = false;
	return OK;
}

//清空
int ClearList(SqList& L) {
	L.length = 0;
	return OK;
}

//判断是否为空
bool pan_kong(SqList L) {
	if (L.length == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

//求长度
int L_length(SqList L) {
	return L.length;
}

//求元素
int GetElem(SqList L, int i, ElemType& e) {
	if (i >= 0 && i < L.length)
	{
		e = L.elem[i - 1];
		return OK;
	}
	else
	{
		return NO;
	}
}

//求位置
int GetAddress(SqList L, ElemType e, int& j) {
	for (int i = 0; i < L.length; i++)
	{
		if (e == L.elem[i])
		{
			j = j + 1;
			return OK;
		}
	}return NO;
}

//前驱
int PriorElem(SqList L, ElemType elem1, ElemType& elem0) {
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == elem1)
		{
			if (i == 0)
			{
				return ERROR;
			}
			else
			{
				elem0 = L.elem[i - 1];
				return OK;
			}
		}
	}
	return NO;
}

//后继
int NextElem(SqList L, ElemType elem1, ElemType& elem0) {
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == elem1)
		{
			if (i == L.length - 1)
			{
				return ERROR;
			}
			else
			{
				elem0 = L.elem[i - 1];
				return OK;
			}
		}
	}
	return NO;
}

//插入
int ListInsert(SqList& L, int i, ElemType e) {
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}
	if (L.length < L.listsize)
	{
		int* q;
		q = &L.elem[i - 1];
		//将插入位置后的元素全部往后移动
		for (int* p = &(L.elem[L.length - 1]); p >= q; p--)
		{
			*(p + 1) = *p;
		}
		*q = e;
		L.length ++;
		return OK;
	}
}

//删除
int DelElem(SqList& L, int i) {
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}
	int* q = &L.elem[L.length - 1];
	for (int* p = &(L.elem[i - 1]); p < q; p++)
	{
		*p = *(p + 1);
	}
	--L.length;
	return OK;
}

int ShowL(SqList L) {
	cout << "表L";
	for (int i = 0; i < L.length; i++)
	{
		cout << L.elem[i] << " ";
	}
	cout << endl;
	return OK;
}

int hebing(SqList &lc) {
	SqList la;
	SqList lb;
	//初始化表A
	cout << endl;
	la.elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (!la.elem)
	{
		cout << "线性表A存储分配失败，请您重新操作" << endl;
	}
	else {
		la.length = 0;
		la.listsize = size;
		cout << "线性表A的存储空间分配成功！" << endl;
		cout << "请输入A中的元素，以负数结束：" << endl;
		int a;
		cin >> a;
		while (a > 0)
		{
			la.length++;
			la.elem[la.length - 1] = a;
			cin >> a;
		}
	}

	//初始化B
	cout << endl;
	lb.elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (!lb.elem)
	{
		cout << "线性表B存储分配失败，请您重新操作" << endl;
	}
	else {
		lb.length = 0;
		lb.listsize = size;
		cout << "线性表A的存储空间分配成功！" << endl;
		cout << "请输入A中的元素，以负数结束：" << endl;
		int a;
		cin >> a;
		while (a > 0)
		{
			lb.length++;
			lb.elem[lb.length - 1] = a;
			cin >> a;
		}
	}
	lc.elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (!lc.elem)
	{
		cout << "合并线性表C创建失败，请重新创建！" << endl;
	}
	else
	{
		cout << "合并线性表的内存空间分配成功！" << endl;
		cout << "合并线性表：";
		lc.listsize = lc.length = la.length + lb.length;
		ElemType* pa = &la.elem[0];
		ElemType* pb = &lb.elem[0];
		ElemType* pc = &lc.elem[0];
		ElemType* pa_end = &la.elem[la.length - 1];
		ElemType* pb_end = &lb.elem[lb.length - 1];

		while (pa <= pa_end && pb <= pb_end)//合并线性表A，B
		{
			if (*pa <= *pb)//取两者中小的一个
			{
				*pc = *pa;
				pa++;
				pc++;
			}
			else
			{
				*pc = *pb;
				pb++;
				pc++;
			}
		}while (pa <= pa_end)//把表A中的剩余元素插入C
		{
			*pc = *pa;
			pc++;
			pa++;
		}
		while (pb <= pb_end)//把表B中的剩余元素插入C
		{
			*pc = *pb;
			pc++;
			pb++;
		}
		for (int i = 0; i <= lc.length - 1; i++)//查重，去重复值
		{
			for (int j = i + 1; j <= lc.length - 1; j++)
			{
				if (lc.elem[i] == lc.elem[j])
				{
					ElemType* q = &(lc.elem[lc.length - 1]);
					for (ElemType* p = &(lc.elem[i]); p < q; p++)
					{
						*p = *(p + 1);
					}//删除重复元素
					--lc.length;
					j--;
					i--;
				}
			}
		}
		for (int i = 0; i <= lc.length - 1; i++)
		{
			cout << lc.elem[i] << " ";
		}
	}
	return OK;
}

int main() {
	cout << endl;
	int address;//存储地址的值
	ElemType tem;//一个临时元素
	int n = 1;
		cout << "1----初始化一个线性表" << endl;
		cout << "2----销毁线性表" << endl;
		cout << "3----清空线性表" << endl;
		cout << "4----判断线性表是否为空" << endl;
		cout << "5----求线性表长度" << endl;
		cout << "6----获取线性表中指定位置的元素" << endl;
		cout << "7----获取线性表元素的位置" << endl;
		cout << "8----求前驱" << endl;
		cout << "9----求后继" << endl;
		cout << "10---在线性表指定位置插入元素" << endl;
		cout << "11---删除线性表指定位置的元素" << endl;
		cout << "12---显示线性表" << endl;
		cout << "13---合并两个非递减有序的线性表" << endl;
		cout << "输入一个负数退出" << endl;
		cout << endl;
		while (n)
		{
			int i;
			cout << "请输入操作代码：";
			cin >> i;
			switch (i)
			{
			case 1:
				InitList(L);
				flag = true;
				cout << endl;
				break;
			case 2:
				if (flag)
				{
					DestroyList(L);
					cout << "表已销毁。" << endl;
				}
				else
				{
					cout << "请先初始化表。" << endl;
					break;
			case 3:
				if (flag)
				{
					ClearList(L);
					cout << "表已清空。" << endl;
				}
				else
				{
					cout << "请先初始化表。" << endl;
					break;
			case 4:
				if (flag)
				{
					if (pan_kong(L))
					{
						cout << "表为空" << endl;
					}
					else
					{
						cout << "表不为空" << endl;
					}
				}
				else
				{
					cout << "请先初始化表。" << endl;
				}
				break;
			case 5:
				if (flag)
				{
					cout << "表的长度为" << L_length(L) << endl;
				}
				else
				{
					cout << "请先初始化表" << endl;
				}
				break;
			case 6:
				if (flag)
				{
					cout << "请输入元素在表中的位置：" << endl;
					cin >> address;
					if (GetElem(L, address, tem) == OK)
					{
						cout << "元素为:" << tem << endl;
					}
					else if (GetElem(L, address, tem) == NO)
					{
						cout << "不存在。" << endl;
					}
					break;
				}
				else
				{
					cout << "请先初始化表。" << endl;
				}
			case 7:
				if (flag)
				{
					cout << "请输入元素：" << endl;
					cin >> tem;
					if (GetAddress(L, tem, address) == OK)
					{
						cout << "元素位置为:" << address << endl;
					}
					else if (GetAddress(L, address, tem) == NO)
					{
						cout << "不存在。" << endl;
					}
					break;
				}
				else
				{
					cout << "请先初始化表。" << endl;
				}
			case 8:
				if (flag)
				{
					ElemType qianqu;
					cout << "请输入元素" << endl;
					cin >> tem;
					PriorElem(L, tem, qianqu);
					if (PriorElem(L, tem, qianqu)==ERROR)
					{
						cout << "第一个元素没有前驱。" << endl;
					}
					else if (PriorElem(L, tem, qianqu) == OK) {
						cout << "该元素的前驱为：" << qianqu << endl;
					}
					else
					{
						cout << "不存在。" << endl;
					}
				}
				else
					{
						cout << "请先初始化表。" << endl;
					}
				break;
			case 9:
				if (flag)
				{
					ElemType houji;
					cout << "请输入元素" << endl;
					cin >> tem;
					NextElem(L, tem, houji);
					if (NextElem(L, tem, houji) == ERROR)
					{
						cout << "最后一个元素没有后继。" << endl;
					}
					else if (NextElem(L, tem, houji) == OK) {
						cout << "该元素的后继为：" << houji << endl;
					}
					else
					{
						cout << "不存在。" << endl;
					}
				}
				else
				{
					cout << "请先初始化表。" << endl;
				}
				break;
			case 10:
				if (flag)
				{
					cout << "请输入位置：" << endl;
					cin >> address;
					cout << "请输入元素：" << endl;
					cin >> tem;
					if (ListInsert(L, address, tem) == OK)
						cout << "插入成功。" << endl;
					else
						cout << "位置超出范围。" << endl;
				}
				else {
					cout << "请先初始化表。" << endl;
				}
				break;
				}
			case 11:
				if (flag)
				{
					cout << "请输入位置：" << endl;
					cin >> address;
					if (DelElem(L,address)==OK)
					{
						cout << "删除成功" << endl;
					}
					else 
					{
						cout << "位置超出范围" << endl;
					}
				}
				else
				{
					cout << "请先初始化表" << endl;
				}
			case 12:
				if (flag)
				{
					ShowL(L);
				}
				else
				{
					cout << "请先初始化表" << endl;
				}
				break;
			case 13:
				hebing(lc);
				break;
			default:
				if (i < 0)
				{
					n = 0;
					cout << "已经退出程序" << endl;
					break;
				}
			}
		}
}

