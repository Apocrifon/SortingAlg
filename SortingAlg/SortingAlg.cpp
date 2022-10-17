#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

long long compareCounterBubble = 0;
long long changeCounterBubble = 0;
long long compareCounterMixing = 0;
long long changeCounterMixing = 0;

void SetArraySizes(int* arr)
{
	cout << "������� ����� ����� �������" << endl;
	cout << "����� �������: ";
	cin >> arr[0];
	cout << endl;
	cout << "������ �������: ";
	cin >> arr[1];
	cout << endl;
}

int SetArrayStep()
{
	int result;
	cout << "������� ������ ����: ";
	cin >> result;
	cout << endl;
	return result;
}

void SetRandValues(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = rand() % 100001;
	}
}

void SetSortValues(int* array, int size)
{
	for (int i = 0; i < size; i++)
	{
		array[i] = i;
	}
}

void WriteInFile(int* array, int size)
{
	ofstream out;
	out.open("D:\\Repositories\\SortingAlg\\data.txt");
	for (size_t i = 0; i < size; i++)
	{
		out << array[i];
	}
	out.close();
}

void ReadFromFile(int* array, int size)
{
	ifstream in("D:\\Repositories\\SortingAlg\\data.txt");
	for (int i = 0; i < size; i++)
	{
		in >> array[i];
	}
	in.close();
}

void BubbleSort(int* array, int size)
{
	auto t0 = clock();
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
				changeCounterBubble++;
			}
			compareCounterBubble++;
		}
	}
	auto t1 = clock();
	cout << "������ �������: " << size << endl;
	cout << "����� �������� ���������: " << compareCounterBubble << endl;
	cout << "����� �������� ������: " << changeCounterBubble << endl;
	cout << "�����: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
	changeCounterBubble = 0;
	compareCounterBubble = 0;
	
}

void MixingSort(int* array, int size)
{
	auto t0 = clock();
	int left, right, i;
	left = 0;
	right = size - 1;
	while (left <= right) 
	{
		for (i = right; i >= left; i--) {
			if (array[i - 1] > array[i]) {
				swap(array[i - 1], array[i]);
				changeCounterMixing++;
			}
			compareCounterMixing++;
		}
		left++;
		for (i = left; i <= right; i++) {
			if (array[i - 1] > array[i]) {
				swap(array[i - 1], array[i]);
				changeCounterMixing++;
			}
			compareCounterMixing++;
		}
		right--;
	}
	auto t1 = clock();
	cout << "������ �������: " << size << endl;
	cout << "����� �������� ���������: " << compareCounterMixing << endl;
	cout << "����� �������� ������: " << changeCounterMixing << endl;
	cout << "�����: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
	changeCounterMixing = 0;
	compareCounterMixing = 0;
}

void PrintArray(int* array, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	auto minSize = 0;
	auto maxSize = 0;
	auto currentSize = 0;
	auto array = new int[minSize];
	auto step=0;
	bool flag = true;
	bool typeOfSorting=false;
	int funk;
	int arr[2];
	cout << "1) ��������� ������ ������� � ���� ���������� �������" << endl;
	cout << "2) ��������� ������� ���������� �������" << endl;
	cout << "3) ��������� ������� �������������� �������" << endl;
	cout << "4) ������ ������ ������ � �����" << endl;
	cout << "5) ������ ������ ������ � ����" << endl;
	cout << "6) ������������ ������� �������� �����������(�����������)" << endl;
	cout << "7) ������������ ������� ���������� ��������������" << endl;
	cout << "8) ������������ ������������� ����� ����������" << endl;
	cout << "��� ������ ������� -1" << endl;
	while (flag)
	{
		cin >> funk;
		switch (funk)
		{
		case 1:
			SetArraySizes(arr);
			minSize= arr[0];
			maxSize = arr[1];
			step= SetArrayStep();
			cout << "���������� ����" << endl;
			break;
		case 2:
			typeOfSorting = false;
			cout << "���������� ����" << endl;
			break;
		case 3:
			typeOfSorting = true;
			cout << "���������� ����" << endl;
			break;
		case 4:
			ReadFromFile(array, currentSize);
			cout << "���������� ����" << endl;
			break;
		case 5:
			WriteInFile(array, currentSize);
			cout << "���������� ����" << endl;
			break;
		case 6:
			for (int i = minSize; i <= maxSize; i+=step)
			{
				array = new int[i];
				if (!typeOfSorting)
					SetRandValues(array, i);
				else
					SetSortValues(array, i);
				//PrintArray(array, i);
				BubbleSort(array, i);
				//PrintArray(array, i);
				delete[] array;

			}
			cout << "���������� ����" << endl;
			break;
		case 7:
			for (int i = minSize; i <= maxSize; i += step)
			{
				array = new int[i];
				if (!typeOfSorting)
					SetRandValues(array, i);
				else
					SetSortValues(array, i);
				//PrintArray(array, i);
				MixingSort(array, i);
				//PrintArray(array, i);
			}
			cout << "���������� ����" << endl;
			break;
		case 8:
			for (int i = minSize; i <= maxSize; i += step)
			{
				auto arr1 = new int[i];
				auto arr2 = new int[i];
				if (!typeOfSorting)
				{
					SetRandValues(arr1, i);
					memcpy(arr2, arr1, sizeof(int) * i);

				}
				else
				{
					SetSortValues(arr1, i);
					memcpy(arr2, arr1, sizeof(int) * i);
				}
				BubbleSort(arr1, i);
				//PrintArray(arr1, i);
				MixingSort(arr2, i);
				//PrintArray(arr2, i);
			}
			cout << "���������� ����" << endl;
			break;
		case -1:
			flag = false;
			break;
		default:
			cout << "�������� ���� �� ����������� ��������� ��� ������� �� ����������" << endl;
			break;
		}

	}
}
