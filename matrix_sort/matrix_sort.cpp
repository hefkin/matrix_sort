#include <iostream>
#include <ctime>
#include <clocale>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;

	cout << "Введите размерность массива: ";

	while (!(cin >> n) || (cin.peek() != '\n'))
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Некорректные данные, попробуйте снова" << endl;
	}

	while (n > 10)
	{
		cout << "Некорректные данные, попробуйте снова" << endl;
		while (!(cin >> n) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некорректные данные, попробуйте снова" << endl;
		}
	}

	system("cls");

	int** a;
	a = new int* [n];
	for (int i = 0; i < n; i++)
	{

		a[i] = new  int[n];

	}

	cout << "___________________________________________________________________________" << endl << endl;
	cout << "Массив:" << endl;
	cout << "___________________________________________________________________________" << endl << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{

			a[i][j] = rand() % 10;
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int q = 0; q < n - 1; q++)      //q -  строка
			{
				for (int w = q + 1; w < n; w++)
				{
					if (a[i][j] < a[q][w])
					{
						swap(a[i][j], a[q][w]);
					}
				}
			}
		}
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			for (int q = 1; q < n; q++)
			{
				for (int w = 0; w < q; w++)
				{
					if (a[i][j] > a[q][w])
					{
						swap(a[i][j], a[q][w]);
					}
				}
			}
		}
	}

	cout << "___________________________________________________________________________" << endl << endl;
	cout << "Отсортированный массив:" << endl;
	cout << "___________________________________________________________________________" << endl << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << "\t";
		}
		cout << endl;
	}

}