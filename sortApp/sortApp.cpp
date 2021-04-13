#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <windows.h>

using namespace std;

clock_t start, stop;
double czas;

void bubblesort(vector<int>& tab, int n)
{
	for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= 1; j--)
		{
			if (tab[j] < tab[j - 1])
			{
				int temp;
				temp = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = temp;

			}
		}
	}
}

void quicksort(vector<int>& tab, int left, int right)
{
	int v = tab[(left + right) / 2];
	int i, j, x;
	i = left;
	j = right;
	do {
		while (tab[i] < v) i++;
		while (tab[j] > v) j--;
		if (i <= j) {
			x = tab[i];
			tab[i] = tab[j];
			tab[j] = x;
			i++; j--;
		}
	} while (i <= j);

	if (j > left) quicksort(tab, left, j);
	if (i < right) quicksort(tab, i, right);


}

int main()
{
	srand(time(NULL));

	int N = rand() % 100 + 20;
	vector<int> vector;

	for (int i = 0; i < N; i++)
	{
		vector.push_back(rand() % 100000 + 1);
	}

	//bubblesort(vector, N);
	quicksort(vector, 0, vector.size() - 1);

	for (int i = 0; i < vector.size(); i++)
	{
		std::cout << vector[i] << endl;
	}

}