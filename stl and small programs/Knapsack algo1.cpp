// Knapsack algorithm

#include <bits/stdc++.h>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int main()
{
	int n = 4, weight = 5, w, i;

	int val[5] = {0, 100, 20, 60, 40};
	// value's size will be 1 element grater than the total 'number of items'
	// val[n + 1]
	// the first of which will be '0' to avoid complexity
	int wt[5] = {0, 3, 2, 4, 1};
	// the same way, weights' array size will be greater than 'n' by 1
	// wt[n+1]

	int v[5][6];
	// v[n+1][max_weight+1];
	// 0th rows and 0th columns are all '0'

	for(i = 0; i <= n; i++) v[i][0] = 0;
	for(i = 0; i <= weight; i++) v[0][i] = 0;
	// 0th rows and 0th columns are all '0'

	for(i = 1; i <= n; i++) {
		for(w = 1; w <= weight; w++) {
			if (wt[i] > w) {
				v[i][w] = v[i-1][w];
			}
			else if (wt[i] <= w) {
				v[i][w] = max (v[i-1][w], val[i] + v[i-1][w - wt[i]]);
			}
		}
	}

	for(i = 0; i <= n; i++) {
		for(w = 0; w <= weight; w++) {
			cout << v[i][w] << "\t";
		}
		cout << "\n";
	}

	int max = v[n][weight];
	cout << "MAX the theif can get:\t" << max << endl;

// time to find the values/objects choosen;
	int choosen[5];
	memset(choosen, -1, sizeof(choosen));

	i = n; w = weight;
	int choice = 0;

	while (i > 0 && w > 0) {
		if (v[i][w] != v[i-1][w]) {
			choosen[choice++] = i;
			w = w - wt[i];
			i--;
		}
		else if (v[i][w] == v[i-1][w]) i--;
	}

	cout << "Choosen items indices are:\t";
	for(i = 0; i <= n; i++) {
		if (choosen[i] == -1) break;
		cout << choosen[i] << "\t";
	}
	puts("");

//	choosen[5] = {4, 1, -1, -1, -1};
	sort(choosen, choosen + choice);
//	choosen[5] = {1, 4, -1, -1, -1};



	cout << "Choosen items' values are:\t";
	i = 0;
	while(choosen[i] != -1) {
		cout << val[choosen[i]] << "\t";
		i++;
	}
	puts("");


	cout << "Choosen items' weights are:\t";
	i = 0;
	while (choosen[i] != -1) {
		cout << wt[choosen[i]] << "\t";
		i++;
	}
	puts("");





	return 0;
}
