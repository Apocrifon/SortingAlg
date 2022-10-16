#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
using namespace std;

int* SetArraySizes()
{
	int arr[2];
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
	cout << "������� ������ ����:";
	cin >> result;
	cout << endl;
	return result;
}

void SetRandValues(int* array, int size)
{
	srand(time(NULL));
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
	for (int i = 0; i < size-1; i++)
	{
		for (int j = 0; j < size-1; j++)
		{
			if (array[j] > array[j + 1])
				swap(array[j], array[j + 1]);
		}
	}
}

void MixingSort(int* array, int size)
{
	int left, right, i;
	left = 0;
	right = size - 1;
	while (left <= right) 
	{
		for (i = right; i >= left; i--) {
			if (array[i - 1] > array[i]) {
				swap(array[i - 1], array[i]);
			}
		}
		left++;
		for (i = left; i <= right; i++) {
			if (array[i - 1] > array[i]) {
				swap(array[i - 1], array[i]);
			}
		}
		right--;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	auto minSize= SetArraySizes()[0];
	auto maxSize= SetArraySizes()[1];
	auto step = SetArrayStep();
	bool flag = true;
	cout << "1) ��������� ������ �������" << endl;
	cout << "2) ��������� ���� ���������� �������" << endl;
	cout << "3) ��������� ������� ���������� �������" << endl;
	cout << "4) ��������� ������� �������������� �������" << endl;
	cout << "5) ������ ������ ������ � �����" << endl;
	cout << "6) ������ ������ ������ � ����" << endl;
	cout << "7) ������������ ������� �������� �����������" << endl;
	cout << "8) ������������ ������� ���������� ��������������" << endl;
	cout << "��� ������ ������� -1" << endl;
	while (flag)
	{
		int funk;
		cin >> funk;
		switch (funk)
		{
		case 1:
			//
			break;
		case 2:
			//
			break;
		case 3:
			//
			break;
		case 4:
			//
			break;
		case 5:
			//
			break;
		case 6:
			//
			break;
		case 7:
			//
			break;
		case 8:
			//
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
