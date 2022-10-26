#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define OK 1  //ִ�гɹ�
#define NO -1  //������
#define ERROR 0  //������Χorִ��ʧ��
bool flag;
#define size 100//���Ա�洢�ռ�ĳ�ʼ������
#define extra 10//��������

typedef int ElemType;


typedef struct {
	ElemType* elem; // �洢�ռ����
	int length; // ��ǰ����
	int listsize; // ��ǰ����Ĵ洢��������sizeof��ElemType��Ϊ��λ��
}SqList;

SqList L;
SqList lc;//�ϲ����Ľ��

//��ʼ�����Ա�
int InitList(SqList& L) {
	L.elem = (ElemType*)malloc(size * sizeof(ElemType));//Ϊ����Ԫ�ؿ���һά����ռ�
	if (!L.elem) {
		cout << "���Ա�A�洢����ʧ�ܣ��������²�����" << endl;
		return ERROR;
	}
	else
	{
		L.length = 0;
		L.listsize = size;
		cout << "���Ա�Ĵ洢�ռ����ɹ���" << endl;
		return OK;
	}
}

//����
int DestroyList(SqList& L) {
	free(L.elem);
	L.elem = NULL;
	L.length = 0;
	L.listsize = 0;
	flag = false;
	return OK;
}

//���
int ClearList(SqList& L) {
	L.length = 0;
	return OK;
}

//�ж��Ƿ�Ϊ��
bool pan_kong(SqList L) {
	if (L.length == 0) {
		return true;
	}
	else
	{
		return false;
	}
}

//�󳤶�
int L_length(SqList L) {
	return L.length;
}

//��Ԫ��
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

//��λ��
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

//ǰ��
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

//���
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

//����
int ListInsert(SqList& L, int i, ElemType e) {
	if (i < 1 || i > L.length + 1)
	{
		return ERROR;
	}
	if (L.length < L.listsize)
	{
		int* q;
		q = &L.elem[i - 1];
		//������λ�ú��Ԫ��ȫ�������ƶ�
		for (int* p = &(L.elem[L.length - 1]); p >= q; p--)
		{
			*(p + 1) = *p;
		}
		*q = e;
		L.length ++;
		return OK;
	}
}

//ɾ��
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
	cout << "��L";
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
	//��ʼ����A
	cout << endl;
	la.elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (!la.elem)
	{
		cout << "���Ա�A�洢����ʧ�ܣ��������²���" << endl;
	}
	else {
		la.length = 0;
		la.listsize = size;
		cout << "���Ա�A�Ĵ洢�ռ����ɹ���" << endl;
		cout << "������A�е�Ԫ�أ��Ը���������" << endl;
		int a;
		cin >> a;
		while (a > 0)
		{
			la.length++;
			la.elem[la.length - 1] = a;
			cin >> a;
		}
	}

	//��ʼ��B
	cout << endl;
	lb.elem = (ElemType*)malloc(size * sizeof(ElemType));
	if (!lb.elem)
	{
		cout << "���Ա�B�洢����ʧ�ܣ��������²���" << endl;
	}
	else {
		lb.length = 0;
		lb.listsize = size;
		cout << "���Ա�A�Ĵ洢�ռ����ɹ���" << endl;
		cout << "������A�е�Ԫ�أ��Ը���������" << endl;
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
		cout << "�ϲ����Ա�C����ʧ�ܣ������´�����" << endl;
	}
	else
	{
		cout << "�ϲ����Ա���ڴ�ռ����ɹ���" << endl;
		cout << "�ϲ����Ա�";
		lc.listsize = lc.length = la.length + lb.length;
		ElemType* pa = &la.elem[0];
		ElemType* pb = &lb.elem[0];
		ElemType* pc = &lc.elem[0];
		ElemType* pa_end = &la.elem[la.length - 1];
		ElemType* pb_end = &lb.elem[lb.length - 1];

		while (pa <= pa_end && pb <= pb_end)//�ϲ����Ա�A��B
		{
			if (*pa <= *pb)//ȡ������С��һ��
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
		}while (pa <= pa_end)//�ѱ�A�е�ʣ��Ԫ�ز���C
		{
			*pc = *pa;
			pc++;
			pa++;
		}
		while (pb <= pb_end)//�ѱ�B�е�ʣ��Ԫ�ز���C
		{
			*pc = *pb;
			pc++;
			pb++;
		}
		for (int i = 0; i <= lc.length - 1; i++)//���أ�ȥ�ظ�ֵ
		{
			for (int j = i + 1; j <= lc.length - 1; j++)
			{
				if (lc.elem[i] == lc.elem[j])
				{
					ElemType* q = &(lc.elem[lc.length - 1]);
					for (ElemType* p = &(lc.elem[i]); p < q; p++)
					{
						*p = *(p + 1);
					}//ɾ���ظ�Ԫ��
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
	int address;//�洢��ַ��ֵ
	ElemType tem;//һ����ʱԪ��
	int n = 1;
		cout << "1----��ʼ��һ�����Ա�" << endl;
		cout << "2----�������Ա�" << endl;
		cout << "3----������Ա�" << endl;
		cout << "4----�ж����Ա��Ƿ�Ϊ��" << endl;
		cout << "5----�����Ա���" << endl;
		cout << "6----��ȡ���Ա���ָ��λ�õ�Ԫ��" << endl;
		cout << "7----��ȡ���Ա�Ԫ�ص�λ��" << endl;
		cout << "8----��ǰ��" << endl;
		cout << "9----����" << endl;
		cout << "10---�����Ա�ָ��λ�ò���Ԫ��" << endl;
		cout << "11---ɾ�����Ա�ָ��λ�õ�Ԫ��" << endl;
		cout << "12---��ʾ���Ա�" << endl;
		cout << "13---�ϲ������ǵݼ���������Ա�" << endl;
		cout << "����һ�������˳�" << endl;
		cout << endl;
		while (n)
		{
			int i;
			cout << "������������룺";
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
					cout << "�������١�" << endl;
				}
				else
				{
					cout << "���ȳ�ʼ����" << endl;
					break;
			case 3:
				if (flag)
				{
					ClearList(L);
					cout << "������ա�" << endl;
				}
				else
				{
					cout << "���ȳ�ʼ����" << endl;
					break;
			case 4:
				if (flag)
				{
					if (pan_kong(L))
					{
						cout << "��Ϊ��" << endl;
					}
					else
					{
						cout << "��Ϊ��" << endl;
					}
				}
				else
				{
					cout << "���ȳ�ʼ����" << endl;
				}
				break;
			case 5:
				if (flag)
				{
					cout << "��ĳ���Ϊ" << L_length(L) << endl;
				}
				else
				{
					cout << "���ȳ�ʼ����" << endl;
				}
				break;
			case 6:
				if (flag)
				{
					cout << "������Ԫ���ڱ��е�λ�ã�" << endl;
					cin >> address;
					if (GetElem(L, address, tem) == OK)
					{
						cout << "Ԫ��Ϊ:" << tem << endl;
					}
					else if (GetElem(L, address, tem) == NO)
					{
						cout << "�����ڡ�" << endl;
					}
					break;
				}
				else
				{
					cout << "���ȳ�ʼ����" << endl;
				}
			case 7:
				if (flag)
				{
					cout << "������Ԫ�أ�" << endl;
					cin >> tem;
					if (GetAddress(L, tem, address) == OK)
					{
						cout << "Ԫ��λ��Ϊ:" << address << endl;
					}
					else if (GetAddress(L, address, tem) == NO)
					{
						cout << "�����ڡ�" << endl;
					}
					break;
				}
				else
				{
					cout << "���ȳ�ʼ����" << endl;
				}
			case 8:
				if (flag)
				{
					ElemType qianqu;
					cout << "������Ԫ��" << endl;
					cin >> tem;
					PriorElem(L, tem, qianqu);
					if (PriorElem(L, tem, qianqu)==ERROR)
					{
						cout << "��һ��Ԫ��û��ǰ����" << endl;
					}
					else if (PriorElem(L, tem, qianqu) == OK) {
						cout << "��Ԫ�ص�ǰ��Ϊ��" << qianqu << endl;
					}
					else
					{
						cout << "�����ڡ�" << endl;
					}
				}
				else
					{
						cout << "���ȳ�ʼ����" << endl;
					}
				break;
			case 9:
				if (flag)
				{
					ElemType houji;
					cout << "������Ԫ��" << endl;
					cin >> tem;
					NextElem(L, tem, houji);
					if (NextElem(L, tem, houji) == ERROR)
					{
						cout << "���һ��Ԫ��û�к�̡�" << endl;
					}
					else if (NextElem(L, tem, houji) == OK) {
						cout << "��Ԫ�صĺ��Ϊ��" << houji << endl;
					}
					else
					{
						cout << "�����ڡ�" << endl;
					}
				}
				else
				{
					cout << "���ȳ�ʼ����" << endl;
				}
				break;
			case 10:
				if (flag)
				{
					cout << "������λ�ã�" << endl;
					cin >> address;
					cout << "������Ԫ�أ�" << endl;
					cin >> tem;
					if (ListInsert(L, address, tem) == OK)
						cout << "����ɹ���" << endl;
					else
						cout << "λ�ó�����Χ��" << endl;
				}
				else {
					cout << "���ȳ�ʼ����" << endl;
				}
				break;
				}
			case 11:
				if (flag)
				{
					cout << "������λ�ã�" << endl;
					cin >> address;
					if (DelElem(L,address)==OK)
					{
						cout << "ɾ���ɹ�" << endl;
					}
					else 
					{
						cout << "λ�ó�����Χ" << endl;
					}
				}
				else
				{
					cout << "���ȳ�ʼ����" << endl;
				}
			case 12:
				if (flag)
				{
					ShowL(L);
				}
				else
				{
					cout << "���ȳ�ʼ����" << endl;
				}
				break;
			case 13:
				hebing(lc);
				break;
			default:
				if (i < 0)
				{
					n = 0;
					cout << "�Ѿ��˳�����" << endl;
					break;
				}
			}
		}
}

