#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "SortingAlg.h"
using namespace std;

long long compareCounterBubble = 0;
long long changeCounterBubble = 0;
long long compareCounterMixing = 0;
long long changeCounterMixing = 0;

void StartingInfo()
{
	cout << "1) ��������� ������ ������� � ���� ���������� �������" << endl;
	cout << "2) ��������� ������� ���������� �������" << endl;
	cout << "3) ��������� ������� �������������� �������" << endl;
	cout << "4) ������ ������ ������ � �����" << endl;
	cout << "5) ������ ������ ������ � ����" << endl;
	cout << "6) ������������ ������� �������� �����������(�����������)" << endl;
	cout << "7) ������������ ������� ���������� ��������������" << endl;
	cout << "8) ������������ ������������� ����� ����������" << endl;
	cout << "��� ������ ������� -1" << endl;
}

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
		array[i] = rand() % 100001;
}

void SetSortValues(int* array, int size)
{
	for (int i = 0; i < size; i++)
		array[i] = i;
}

void WriteInFile(int* array, int size)
{
	ofstream out;
	out.open("D:\\Repositories\\SortingAlg\\data.txt");
	for (size_t i = 0; i < size; i++)
	{
		out << array[i] << endl;
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
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1; j++)
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
	WriteData(size, t1, t0);
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
	WriteData(size, t1, t0);
	changeCounterMixing = 0;
	compareCounterMixing = 0;
}

void WriteData(int size, const clock_t& t1, const clock_t& t0)
{
	ofstream out("D:\\Repositories\\SortingAlg\\data.txt", std::ios::app);
	if (out.is_open())
	{
		out << "������ �������: " << size << endl;
		out << "����� �������� ���������: " << compareCounterMixing << endl;
		out << "����� �������� ������: " << changeCounterMixing << endl;
		out << "�����: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
	}
	out.close();
}

void PrintArray(int* array, int size)
{
	for (size_t i = 0; i < size; i++)
		cout << array[i] << " ";
	cout << endl;