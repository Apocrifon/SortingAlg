#include "funk.h";

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	auto minSize = 0;
	auto maxSize = 0;
	auto currentSize = 0;
	auto array = new int[minSize];
	auto step=0;
	auto flag = true;
	auto typeOfSorting=false;
	int funk;
	int arr[2]; 
	StartingInfo();
	while (flag)
	{
		ofstream out("D:\\Repositories\\SortingAlg\\data.txt", ios::app);
		cin >> funk;
		switch (funk)
		{
		case 1:
			SetArraySizes(arr);
			minSize= arr[0];
			maxSize = arr[1];
			step= SetArrayStep();
			cout << "Продолжите ввод" << endl;
			break;
		case 2:
			typeOfSorting = false;
			cout << "Продолжите ввод" << endl;
			break;
		case 3:
			typeOfSorting = true;
			cout << "Продолжите ввод" << endl;
			break;
		case 4:
			ReadFromFile(array, currentSize);
			cout << "Продолжите ввод" << endl;
			break;
		case 5:
			WriteInFile(array, currentSize);
			cout << "Продолжите ввод" << endl;
			break;
		case 6:
			if (out.is_open())
			{
				out << "Новый тест" << endl;
				out << string(32,'-') << endl;
			}
			for (int i = minSize; i <= maxSize; i+=step)
			{
				array = new int[i];
				if (!typeOfSorting)
					SetRandValues(array, i);
				else
					SetSortValues(array, i);
				BubbleSort(array, i);
				currentSize = i;
			}
			cout << "Продолжите ввод" << endl;
			break;
		case 7:
			if (out.is_open())
			{
				out << "Новый тест" << endl;
				out << string(32,'-') << endl;
			}
			for (int i = minSize; i <= maxSize; i += step)
			{
				array = new int[i];
				if (!typeOfSorting)
					SetRandValues(array, i);
				else
					SetSortValues(array, i);
				MixingSort(array, i);
				currentSize = i;
			}
			cout << "Продолжите ввод" << endl;
			break;
		case 8:
			if (out.is_open())
			{
				out << "Новый тест" << endl;
				out << string(32,'-') << endl;
			}
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
				MixingSort(arr2, i);
				delete[] arr1;
				delete[] arr2;
				currentSize = i;
			}
			cout << "Продолжите ввод" << endl;
			break;
		case -1:
			flag = false;
			break;
		default:
			cout << "Выберите один из преложенных вариантов или выйдите из приложения" << endl;
			break;
		}
		out.close();
	}
}


