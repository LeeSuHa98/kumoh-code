#pragma once

#include <iostream>
#include <string>
#include "Rectangle.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "Etc.h"
#include "QuickSort.h"
#include "InsertSort.h"
#include "MergeSort.h"

class DecreaceSort
{
public:
	void decreaceSort()
	{
		cout << "[ Decrease Sort ]" << endl;
		cout << " 1. BubbleSort" << endl << " 2. SelectionSort" << endl << " 3. HeapSort" << endl << " 4. Std::Sort" << endl << " 5. QuickSort" << endl
			<< " 6. Mid_QuickSort" << endl << " 7. NonR_Mid_QuickSort" << endl << " 8. InsertSort" << endl << " 9. Binary_InsertSort" << endl << " 10. Linked_InsertSort" << endl
			<< " 11. NonR_MergeSort" << endl << " 12. Natural_MergeSort" << endl << " 13. R_MergeSort" << endl << " 14. Exit" << endl;
		cout << " Select -> ";

		int select;
		cin >> select;


		switch (select)
		{
		case 1:
			decrease_BubbleSort();
			break;
		case 2:
			decrease_SelectionSort();
			break;
		case 3:
			decrease_HeapSort();
			break;
		case 4:
			decrease_StdSort();
			break;
		case 5:
			decrease_QuickSort();
			break;
		case 6:
			decrease_Mid_QuickSort();
			break;
		case 7:
			decrease_NonR_Mid_QuickSort();
			break;
		case 8:
			decrease_InsertSort();
			break;
		case 9:
			decrease_Binary_InsertSort();
			break;
		case 10:
			decrease_Linked_InsertSort();
			break;
		case 11:
			decrease_NonR_MergeSort();
			break;
		case 12:
			decrease_Natural_MergeSort();
			break;
		case 13:
			decrease_R_MergeSort();
			break;
		case 14:
			return;
		}

		cout << endl << endl;


	}

	void decrease_BubbleSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			BubbleSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			BubbleSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			BubbleSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			BubbleSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_SelectionSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			SelectionSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			SelectionSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			SelectionSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			SelectionSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_HeapSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			HeapSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			HeapSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			HeapSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			HeapSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_StdSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			Etc<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			Etc<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			Etc<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			Etc<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_QuickSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			QuickSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			QuickSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			QuickSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			QuickSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_Mid_QuickSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			QuickSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			QuickSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			QuickSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			QuickSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_mid(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_NonR_Mid_QuickSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			QuickSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			QuickSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			QuickSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			QuickSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_quick_iter(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_InsertSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			InsertSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			InsertSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			InsertSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			InsertSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Basic(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_Binary_InsertSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			InsertSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			InsertSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			InsertSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			InsertSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Binary(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_Linked_InsertSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			InsertSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			InsertSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			InsertSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			InsertSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Linked(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_NonR_MergeSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			MergeSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			MergeSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			MergeSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			MergeSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_NonR(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_Natural_MergeSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) //int
		{
			int index = 0;

			MergeSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			MergeSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			MergeSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			MergeSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_Natural(circleArr4, 100000);

			delete[] circleArr4;
		}
	}

	void decrease_R_MergeSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		ifstream in;

		if (select == 1) 
		{
			int index = 0;

			MergeSort<int> bi;

			cout << endl << "Decrease Array : Type<Int>" << endl;

			int *intArr0 = new int[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(intArr0, 1000);

			delete[] intArr0;

			///////////////////////////////////////////////////////
			index = 0;

			int *intArr1 = new int[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(intArr1, 5000);

			delete[] intArr1;

			///////////////////////////////////////////////////////
			index = 0;


			int *intArr2 = new int[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(intArr2, 10000);

			delete[] intArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr3 = new int[50000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(intArr3, 50000);

			delete[] intArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			int *intArr4 = new int[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				intArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(intArr4, 100000);

			delete[] intArr4;
		}

		else if (select == 2) //Double
		{
			int index = 0;

			MergeSort<double> bi;

			cout << endl << "Decrease Array : Type<Double>" << endl;

			double *doubleArr0 = new double[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(doubleArr0, 1000);

			delete[] doubleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			double *doubleArr1 = new double[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(doubleArr1, 5000);

			delete[] doubleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			double *doubleArr2 = new double[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(doubleArr2, 10000);

			delete[] doubleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr3 = new double[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(doubleArr3, 50000);

			delete[] doubleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			double *doubleArr4 = new double[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				doubleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(doubleArr4, 100000);

			delete[] doubleArr4;
		}

		else if (select == 3)
		{
			int index = 0;

			MergeSort<string> bi;

			cout << endl << "Decrease Array : Type<String>" << endl;

			string *stringArr0 = new string[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(stringArr0, 1000);

			delete[] stringArr0;

			///////////////////////////////////////////////////////
			index = 0;

			string *stringArr1 = new string[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(stringArr1, 5000);

			delete[] stringArr1;

			///////////////////////////////////////////////////////
			index = 0;


			string *stringArr2 = new string[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(stringArr2, 10000);

			delete[] stringArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr3 = new string[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(stringArr3, 50000);

			delete[] stringArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			string *stringArr4 = new string[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				stringArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(stringArr4, 100000);

			delete[] stringArr4;
		}

		else if (select == 4)
		{
			int index = 0;

			MergeSort<Circle> bi;

			cout << endl << "Decrease Array : Type<Circle>" << endl;

			Circle *circleArr0 = new Circle[1000];

			in.open(to_string(1000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr0[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(circleArr0, 1000);

			delete[] circleArr0;

			///////////////////////////////////////////////////////
			index = 0;

			Circle *circleArr1 = new Circle[5000];

			in.open(to_string(5000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr1[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(circleArr1, 5000);

			delete[] circleArr1;

			///////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr2 = new Circle[10000];

			in.open(to_string(10000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr2[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(circleArr2, 10000);

			delete[] circleArr2;
			/////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr3 = new Circle[50000];

			in.open(to_string(50000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr3[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(circleArr3, 50000);

			delete[] circleArr3;
			//////////////////////////////////////////////////////////////////
			index = 0;


			Circle *circleArr4 = new Circle[100000];

			in.open(to_string(100000) + "_Decreace.txt");

			while (1)
			{
				string x;
				in >> x; if (x == "\0") break;
				circleArr4[index++] = atoi(x.c_str());
				if (in.eof())
					break;
			}
			in.close();

			bi.getSort_Merge_R(circleArr4, 100000);

			delete[] circleArr4;
		}
	}
};