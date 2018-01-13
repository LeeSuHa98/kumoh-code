#pragma once
#include "std.h"
template <class T>
class InsertSort
{
public:
	InsertSort(void) {}

	void getSort_Basic(T* arr, const int count)
	{
		basic(arr, count);
	}

	void getSort_Binary(T *arr, const int count)
	{
		binary(arr, count);
	}
	void getSort_Linked(T *arr, const int count) 
	{
		linked(arr, count);
	}

	void insertElement(T& e, T* a, int i)
	{
		a[0] = e;

		while (e < a[i])
		{
			a[i + 1] = a[i];
			i--;
		}

		a[i + 1] = e;
	}

	void basic(T* D, int count)
	{
		T temp;
		T *data = new T[count];
		for (int i = 0; i < count; i++)
		{
			data[i] = D[i];
		}

		clock_t begin;
		clock_t end;
		begin = clock();

		for (int j = 2; j < count; j++)
		{
			temp = D[j];
			insertElement(temp, data, j - 1);
		}

		end = clock();
		cout << "Insert Sort(" << count << ") : " << ((double)(end - begin)) / CLOCKS_PER_SEC << endl;
	}

	void binary(T* D, int count)
	{
		T *data = new T[count];
		for (int i = 0; i < count; i++)
			data[i] = D[i];

		clock_t begin;
		clock_t end;
		begin = clock();

		for (int i = 0; i < count; i++)
		{
			T temp = data[i];

			int j;
			int right = i;
			int left = 0;
			int index;
			int m;
			while (left <= right)
			{
				m = (left + right) / 2;

				if (temp < data[m])
				{
					right = m - 1;
					index = m;
				}
				else if (temp > data[m])
				{
					left = m + 1;
				}
				else if (data[m] == temp)
				{
					index = m;
					break;
				}
			}
			for (j = i; index < j; j--)
			{
				data[j] = data[j - 1];
			}
			data[j] = temp;
		}
		end = clock();
		cout << "Binary Insert Sort(" << count << ") : " << ((double)(end - begin)) / CLOCKS_PER_SEC << endl;

		delete[] data;
	}

	void linked(T* D, int count)
	{
		clock_t begin;
		clock_t end;
		begin = clock();

		Node<T>* start = new Node<T>();

		Node<T>* temp = new Node<T>(D[0]);
		Node<T>* x;
		Node<T>* y;
		//변형 연결삽입정렬이다. 데이터를 새노드로 옮겨가며 만든다.
		//노드를 옮기는거라 따로 공간이 추가되지는 않는다.
		for (int i = 1; i < count; i++)
		{
			temp = new Node<T>(D[i]);
			bool chack = false;
			for (x = start->link, y = start; x != 0; x = x->link, y = y->link)
			{
				if (x->data > temp->data)
				{
					y->link = temp;
					temp->link = x;
					chack = true;
					break;
				}
			}
			if (!chack)
			{
				y->link = temp;
			}
		}
		end = clock();
		cout << "Linked Insert Sort(" << count << ") : " << ((double)(end - begin)) / CLOCKS_PER_SEC << endl;
	}


private:
	template <class T>
	class Node
	{
	public:
		Node() { link = 0; }
		Node(T d) { link = 0; data = d; }
		Node(Node* x, T d) { link = x; data = d; }

		Node* link;
		T data;
	};

};