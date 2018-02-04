#pragma once

#include "std.h"
#include "Circle.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "HeapSort.h"
#include "Etc.h"
#include "QuickSort.h"
#include "InsertSort.h"
#include "MergeSort.h"
#include "HexRadixSort.h"
#include "BitwiseRadixSort.h"
#include "DecimalRadixSort.h"
class RandomSort
{
public:
	void randomSort()
	{
		cout << "[ Random Sort ]" << endl;
		cout << " 1. BubbleSort" << endl << " 2. SelectionSort" << endl << " 3. HeapSort" << endl << " 4. Std::Sort" << endl << " 5. QuickSort" << endl
			<< " 6. Mid_QuickSort" << endl << " 7. NonR_Mid_QuickSort" << endl << " 8. InsertSort" << endl << " 9. Binary_InsertSort" << endl << " 10. Linked_InsertSort" << endl
			<< " 11. NonR_MergeSort" << endl << " 12. Natural_MergeSort" << endl << " 13. R_MergeSort" << endl << " 14. RadixSort(16진수,modulo)" << endl
			<< " 15. RadixSort(16진수,masking,shift)" << endl << " 16. RadixSort(10진수,modulo) " << endl << " 17. Exit" << endl;
		cout << " Select -> ";

		int select;
		cin >> select;

		switch (select)
		{
		case 1:
			random_BubbleSort();
			break;
		case 2:
			random_SelectionSort();
			break;
		case 3:
			random_HeapSort();
			break;
		case 4:
			random_StdSort();
			break;
		case 5:
			random_QuickSort();
			break;
		case 6:
			random_Mid_QuickSort();
			break;
		case 7:
			random_NonR_Mid_QuickSort();
			break;
		case 8:
			random_InsertSort();
			break;
		case 9:
			random_Binary_InsertSort();
			break;
		case 10:
			random_Linked_InsertSort();
			break;
		case 11:
			random_NonR_MergeSort();
			break;
		case 12:
			random_Natural_MergeSort();
			break;
		case 13:
			random_R_MergeSort();
			break;
		case 14:
			random_RadixSort_log16_modulo();
			break;
		case 15:
			random_RadixSort_log16_masking();
			break;
		case 16:
			random_RadixSort_log10_modulo();
			break;
		case 17:
			return;
		}

		cout << endl << endl;
	}

	void random_BubbleSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		int index = 0;
		cout << "[ 테스트 갯수 ] : ";
		cin >> index;

		if (select == 1) //정수
		{
			BubbleSort<unsigned int> bs;
			//fstream fout;
			cout << "Random Array : Type<Int>" << endl << endl;

			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}
			
			bs.getSort(intArr, index);
		}
		else if (select == 2) //실수
		{
			BubbleSort<double> bs;
			//fstream fout;
			cout << "Random Array : Type<Double>" << endl << endl;

			double *doubleArr = new double[index];
			srand((double)time(NULL));
			for (int i = 0; i < index; i++)
			{
				doubleArr[i] = rand() % index + 1;
			}
			
			bs.getSort(doubleArr, index);

		}
		else if (select == 3) //문자열
		{
			BubbleSort<string> bs;
			//fstream fout;
			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[index];
			string* l_strArr = new string[index];

			for (int i = 0; i < index; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; //영문 대문자 난수 추출하기
					l_strArr[i] += strArr[z];
				}
			}
			
			bs.getSort(strArr, index);

		}

		else if (select == 4) 
		{
		   BubbleSort<Circle> bs;

		   cout << "Random Array : Type<Circle>" << endl << endl;
		   
		   Circle *circleArr = new Circle[index];

		   for(int i = 0; i < index; i++)
		   {
			   circleArr[i] = Circle(rand() % index + 1);
		   }

		   bs.getSort(circleArr, index);
		  
		}

		else
			return;
	}
	void random_SelectionSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		int index;
		cout << "[ 테스트 갯수 ] : ";
		cin >> index;
		if (select == 1) //정수
		{
			SelectionSort<unsigned int> bi;

			cout << "Random Array : Type<Int>" << endl << endl;
			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}
			
			bi.getSort(intArr, index);

		}
		else if (select == 2) //실수
		{
			SelectionSort<double> bd;

			cout << "Random Array : Type<Double>" << endl << endl;
			double *doubleArr = new double[index];
			srand((double)time(NULL));
			for (int i = 0; i < index; i++)
			{
				doubleArr[i] = rand() % index + 1;
			}
			
			bd.getSort(doubleArr, index);

		}
		else if (select == 3) //문자열
		{
			SelectionSort<string> bs;
			
			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[index];
			string* l_strArr = new string[index];

			for (int i = 0; i < index; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			
			bs.getSort(strArr, index);

		}

		else if (select == 4) 
		{
			SelectionSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[index];

			for (int i = 0; i < index; i++)
			{
				circleArr[i] = Circle(rand() % index + 1);
			}

			bs.getSort(circleArr, index);
		}

		else
			return;
	}
	void random_HeapSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		int index;
		cout << "[ 테스트 갯수 ] : ";
		cin >> index;
		
		if (select == 1) //정수
		{
			HeapSort<unsigned int> bi;

			cout << "Random Array : Type<Int>" << endl << endl;
			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}
			
			bi.getSort(intArr, index);
		}
		else if (select == 2) //실수
		{
			HeapSort<double> bd;

			cout << "Random Array : Type<Double>" << endl << endl;
			double *doubleArr = new double[index];
			srand((double)time(NULL));
			for (int i = 0; i < index; i++)
			{
				doubleArr[i] = rand() % index + 1;
			}

			bd.getSort(doubleArr, index);
		}
		else if (select == 3) //문자열
		{
			HeapSort<string> bs;

			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[index];
			string* l_strArr = new string[index];

			for (int i = 0; i < index; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			
			bs.getSort(strArr, index);

		}

		else if (select == 4) 
		{
			HeapSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[index];

			for (int i = 0; i < index; i++)
			{
				circleArr[i] = Circle(rand() % index + 1);
			}

			bs.getSort(circleArr, index);
			
		}

		else
			return;
	}
	void random_StdSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		int index;
		cout << "[ 테스트 갯수 ] : ";
		cin >> index;

		if (select == 1) //정수
		{
			Etc<unsigned int> bi;

			//fstream fout;
			cout << "Random Array : Type<Int>" << endl << endl;
			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}
			

			bi.getSort(intArr, index);

			
		}
		else if (select == 2) //실수
		{
			Etc<double> bd;

			//fstream fout;
			cout << "Random Array : Type<Double>" << endl << endl;
			double *doubleArr = new double[index];
			srand((double)time(NULL));
			for (int i = 0; i < index; i++)
			{
				doubleArr[i] = rand() % index + 1;
			}
			

			bd.getSort(doubleArr, index);
		}
		else if (select == 3) //문자열
		{
			Etc<string> bs;

			//fstream fout;
			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[index];
			string* l_strArr = new string[index];

			for (int i = 0; i < index; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			
			bs.getSort(strArr, index);

		}

		else if (select == 4) 
		{
			Etc<Circle> br;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[index];

			for (int i = 0; i < index; i++)
			{
				circleArr[i] = Circle(rand() % index + 1);

			}

			br.getSort(circleArr, index);
			
		}

		else
			return;
	}

	void random_QuickSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		cout << "[ 테스트 갯수 ] : ";
		int index;
		cin >> index;


		if (select == 1) //정수
		{
			QuickSort<unsigned int> bi;

			//fstream fout;
			cout << "Random Array : Type<Int>" << endl << endl;
			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}
			
			bi.getSort_quick(intArr, index);

		}
		else if (select == 2) //실수
		{
			QuickSort<double> bd;

			cout << "Random Array : Type<Double>" << endl << endl;
			double *doubleArr = new double[index];
			srand((double)time(NULL));
			for (int i = 0; i < index; i++)
			{
				doubleArr[i] = rand() % index + 1;
			}
			
			bd.getSort_quick(doubleArr, index);

		
		}
		else if (select == 3) //문자열
		{
			QuickSort<string> bs;

			//fstream fout;
			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[index];
			string* l_strArr = new string[index];

			for (int i = 0; i < index; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			
			bs.getSort_quick(strArr, index);

		}

		else if (select == 4) 
		{
			QuickSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[index];

			for (int i = 0; i < index; i++)
			{
				circleArr[i] = Circle(rand() % index + 1);

			}

			bs.getSort_quick(circleArr, index);
			
		}

		else
			return;
	}
	void random_Mid_QuickSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		cout << "[ 테스트 갯수 ] : ";
		int index;
		cin >> index;
		cout << endl;


		if (select == 1) //정수
		{
			QuickSort<unsigned int> bi;

			cout << "Random Array : Type<Int>" << endl;
			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}
			

			bi.getSort_quick_mid(intArr, index);

		}
		else if (select == 2) //실수
		{
			QuickSort<double> bd;

			cout << "Random Array : Type<Double>" << endl;
			double *doubleArr = new double[index];
			srand((double)time(NULL));
			for (int i = 0; i < index; i++)
			{
				doubleArr[i] = rand() % index + 1;
			}
			

			bd.getSort_quick_mid(doubleArr, index);

		}
		else if (select == 3) //문자열
		{
			QuickSort<string> bs;

			//fstream fout;
			cout << "Random Array : Type<String>" << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[index];
			string* l_strArr = new string[index];

			for (int i = 0; i < index; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			

			bs.getSort_quick_mid(strArr, index);

		}
		
		else if (select == 4) 
		{
			QuickSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl;

			Circle *circleArr = new Circle[index];

			for (int i = 0; i < index; i++)
			{
				circleArr[i] = Circle(rand() % index + 1);

			}

			bs.getSort_quick_mid(circleArr, index);
			
		}

		else
			return;
	}
	void random_NonR_Mid_QuickSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		cout << "[ 테스트 갯수 ] : ";
		int index;
		cin >> index;
		cout << endl;


		if (select == 1) //정수
		{
			QuickSort<unsigned int> bi;

			cout << "Random Array : Type<Int>"  << endl;
			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}
			

			bi.getSort_quick_iter(intArr, index);

		}
		else if (select == 2) //실수
		{
			QuickSort<double> bd;


			//fstream fout;
			cout << "Random Array : Type<Double>"  << endl;
			double *doubleArr = new double[index];
			srand((double)time(NULL));
			for (int i = 0; i < index; i++)
			{
				doubleArr[i] = rand() % index + 1;
			}
			

			bd.getSort_quick_iter(doubleArr, index);

		}
		else if (select == 3) //문자열
		{
			QuickSort<string> bs;

			cout << "Random Array : Type<String>"  << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[index];
			string* l_strArr = new string[index];

			for (int i = 0; i < index; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			
			bs.getSort_quick_iter(strArr, index);
		}
		

		else if (select == 4) 
		{
			QuickSort<Circle> bs;

			cout << "Random Array : Type<Circle>"  << endl;

			Circle *circleArr = new Circle[index];

			for (int i = 0; i < index; i++)
			{
				circleArr[i] = Circle(rand() % index + 1);

			}

			bs.getSort_quick_iter(circleArr, index);
		}

		else
			return;
	}

	void random_InsertSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		cout << "[ 테스트 갯수 ] : ";
		int index;
		cin >> index;

		if (select == 1) 
		{
			InsertSort<unsigned int> bi;

			cout << "Random Array : Type<Int>" <<endl<< endl;
			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}
			

			bi.getSort_Basic(intArr, index);

			
		}
		else if (select == 2) //실수
		{
			InsertSort<double> bd;

			cout << "Random Array : Type<Double>" <<endl<< endl;
			double *doubleArr = new double[index];
			srand((double)time(NULL));
			for (int i = 0; i < index; i++)
			{
				doubleArr[i] = rand() % index + 1;
			}
			
			bd.getSort_Basic(doubleArr, index);

		}
		else if (select == 3) 
		{
			InsertSort<string> bs;

			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[index];
			string* l_strArr = new string[index];

			for (int i = 0; i < index; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			

			bs.getSort_Basic(strArr, index);

			
		}

		else if (select == 4) 
		{
			InsertSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[index];

			for (int i = 0; i < index; i++)
			{
				circleArr[i] = Circle(rand() % index + 1);
			}

			bs.getSort_Basic(circleArr, index);
			
		}

		else
			return;
	}

	void random_Binary_InsertSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		cout << "[ 테스트 갯수 ] : ";
		int index;
		cin >> index;


		if (select == 1) 
		{
			InsertSort<unsigned int> bi;

		
			cout << "Random Array : Type<Int>"  << endl;
			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}

			bi.getSort_Binary(intArr, index);

		}
		else if (select == 2) 
		{
			InsertSort<double> bd;

			
			cout << "Random Array : Type<Double>" << endl;
			double *doubleArr = new double[index];
			srand((double)time(NULL));
			for (int i = 0; i < index; i++)
			{
				doubleArr[i] = rand() % index + 1;
			}
			

			bd.getSort_Binary(doubleArr, index);

		}
		else if (select == 3) 
		{
			InsertSort<string> bs;

			
			cout << "Random Array : Type<String>" << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[index];
			string* l_strArr = new string[index];

			for (int i = 0; i < index; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			
			bs.getSort_Binary(strArr, index);
		}
		
		else if (select == 4) 
		{
			InsertSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[index];

			for (int i = 0; i < index; i++)
			{
				circleArr[i] = Circle(rand() % index + 1);

			}

			bs.getSort_Binary(circleArr, index);
		}

		else
			return;
	}
	void random_Linked_InsertSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		cout << "[ 테스트 갯수 ] : ";
		int select2;
		cin >> select2;
	
		if (select == 1) 
		{
			InsertSort<unsigned int> bi;

			cout << "Random Array : Type<Int>" << endl << endl;
			unsigned int *intArr = new unsigned int[select2];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < select2; i++)
			{
				intArr[i] = rand() % select2 + 1;
			}

			bi.getSort_Linked(intArr, select2);

		}
		else if (select == 2) 
		{
			InsertSort<double> bd;

			cout << "Random Array : Type<Double>" << endl << endl;
			double *doubleArr = new double[select2];
			srand((double)time(NULL));
			for (int i = 0; i < select2; i++)
			{
				doubleArr[i] = rand() % select2 + 1;
			}
			
			bd.getSort_Linked(doubleArr, select2);

		}
		else if (select == 3) 
		{
			InsertSort<string> bs;

			//fstream fout;
			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[select2];
			string* l_strArr = new string[select2];

			for (int i = 0; i < select2; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			
			bs.getSort_Linked(strArr, select2);

		}
		
		else if (select == 4) 
		{
			InsertSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[select2];

			for (int i = 0; i < select2; i++)
			{
				circleArr[i] = Circle(rand() % select2 + 1);

			}

			bs.getSort_Linked(circleArr, select2);
		}

		else
			return;
	}

	void random_NonR_MergeSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		cout << "[ 테스트 갯수 ] : ";
		int select2;
		cin >> select2;

		if (select == 1) 
		{
			MergeSort<unsigned int> bi;

			//fstream fout;
			cout << "Random Array : Type<Int>" << endl << endl;
			unsigned int *intArr = new unsigned int[select2];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < select2; i++)
			{
				intArr[i] = rand() % select2 + 1;
			}
			

			bi.getSort_Merge_NonR(intArr, select2);

		}
		else if (select == 2) 
		{
			MergeSort<double> bd;

			//fstream fout;
			cout << "Random Array : Type<Double>" << endl << endl;
			double *doubleArr = new double[select2];
			srand((double)time(NULL));
			for (int i = 0; i < select2; i++)
			{
				doubleArr[i] = rand() % select2 + 1;
			}

			bd.getSort_Merge_NonR(doubleArr, select2);

		}
		else if (select == 3) 
		{
			MergeSort<string> bs;

			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[select2];
			string* l_strArr = new string[select2];

			for (int i = 0; i < select2; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			

			bs.getSort_Merge_NonR(strArr, select2);

			
		}
		
		else if (select == 4) 
		{
			MergeSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[select2];

			for (int i = 0; i < select2; i++)
			{
				circleArr[i] = Circle(rand() % select2 + 1);

			}

			bs.getSort_Merge_NonR(circleArr, select2);
		}

		else
			return;
	}
	void random_Natural_MergeSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		cout << "[ 테스트 갯수 ] : ";
		int select2;
		cin >> select2;

		if (select == 1) 
		{
			MergeSort<unsigned int> bi;

			
			cout << "Random Array : Type<Int>"  <<endl<< endl;
			unsigned int *intArr = new unsigned int[select2];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < select2; i++)
			{
				intArr[i] = rand() % select2 + 1;
			}
			
			bi.getSort_Merge_Natural(intArr, select2);

			//delete[] intArr0;
		}
		else if (select == 2) //실수
		{
			MergeSort<double> bd;

			
			cout << "Random Array : Type<Double>" << endl << endl;
			double *doubleArr = new double[select2];
			srand((double)time(NULL));
			for (int i = 0; i < select2; i++)
			{
				doubleArr[i] = rand() % select2 + 1;
			}
			
			bd.getSort_Merge_Natural(doubleArr, select2);

			
		}
		else if (select == 3) //문자열
		{
			MergeSort<string> bs;

			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[select2];
			string* l_strArr = new string[select2];

			for (int i = 0; i < select2; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			bs.getSort_Merge_Natural(strArr, select2);

		}
		
		else if (select == 4) 
		{
			MergeSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[select2];

			for (int i = 0; i < select2; i++)
			{
				circleArr[i] = Circle(rand() % select2 + 1);
			}

			bs.getSort_Merge_Natural(circleArr, select2);
		}

		else
			return;
	}
	void random_R_MergeSort()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Double\n" << " 3. String\n" << " 4. Circle\n" << " 5. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;

		cout << endl;

		cout << "[ 테스트 갯수 ] : ";
		int select2;
		cin >> select2;


		if (select == 1) 
		{
			MergeSort<unsigned int> bi;

			cout << "Random Array : Type<Int>" << endl << endl;
			unsigned int *intArr = new unsigned int[select2];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < select2; i++)
			{
				intArr[i] = rand() % select2 + 1;
			}
			

			bi.getSort_Merge_R(intArr, select2);

		}
		else if (select == 2) 
		{
			MergeSort<double> bd;

			cout << "Random Array : Type<Double>" << endl << endl;
			double *doubleArr = new double[select2];
			srand((double)time(NULL));
			for (int i = 0; i < select2; i++)
			{
				doubleArr[i] = rand() % select2 + 1;
			}

			bd.getSort_Merge_R(doubleArr, select2);

		}
		else if (select == 3) 
		{
			MergeSort<string> bs;

			cout << "Random Array : Type<String>" << endl << endl;

			srand((unsigned)time(NULL));
			string* strArr = new string[select2];
			string* l_strArr = new string[select2];

			for (int i = 0; i < select2; i++)
			{
				for (int z = 0; z < 20; z++)
				{
					strArr[z] = rand() % 21 + 65; 
					l_strArr[i] += strArr[z];
				}
			}
			

			bs.getSort_Merge_R(strArr, select2);

		}
		
		else if (select == 4) 
		{
			MergeSort<Circle> bs;

			cout << "Random Array : Type<Circle>" << endl << endl;

			Circle *circleArr = new Circle[select2];

			for (int i = 0; i < select2; i++)
			{
				circleArr[i] = Circle(rand() % select2 + 1);
			}

			bs.getSort_Merge_R(circleArr, select2);
		}


		else
			return;
	}

	void random_RadixSort_log16_modulo()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		int index = 0;
		cout << "[ 테스트 갯수 ] : ";
		cin >> index;

		if (select == 1) 
		{
			HexRadixSort hx;
			cout << "Random Array : Type<Int>" << endl << endl;

			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}
			
			hx.Hex_RadixSort(intArr, index);
		}

		else
			return;
	}

	void random_RadixSort_log16_masking()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		int index = 0;
		cout << "[ 테스트 갯수 ] : ";
		cin >> index;

		if (select == 1) 
		{
			BitwiseRadixSort bs;
			cout << "Random Array : Type<Int>" << endl << endl;

			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}

			bs.Bitwise_RadixSort(intArr, index);
		}
	}

	void random_RadixSort_log10_modulo()
	{
		cout << "[ 테스트 타입 ]" << endl;
		cout << " 1. Integer\n" << " 2. Exit " << endl;
		cout << " : ";

		int select;
		cin >> select;
		cout << endl;

		int index = 0;
		cout << "[ 테스트 갯수 ] : ";
		cin >> index;

		if (select == 1)
		{
			DecimalRadixSort ds;
			cout << "Random Array : Type<Int>" << endl << endl;

			unsigned int *intArr = new unsigned int[index];
			srand((unsigned int)time(NULL));
			for (int i = 0; i < index; i++)
			{
				intArr[i] = rand() % index + 1;
			}

			ds.RadixSort(intArr, index);
		}
	}
};