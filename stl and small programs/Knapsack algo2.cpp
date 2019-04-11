// Knapsack algorithm

#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef unsigned long long llu;

int table[100][200];
int val[100];
int wt[100];

int main()
{
	int n, max_weight;

	string value = "yes";

	while (value != "no") {

		cout << "Enter the number of elemnts: ";
		cin >> n;	

		cout << "Enter the max weigt: ";
		cin >> max_weight;

		memset(val, 0, sizeof(val));
		memset(wt, 0, sizeof(wt));

		for(int i = 0; i <= n; i++) table[i][0] = 0;
		for(int i = 0; i <= max_weight; i++) table[0][i] = 0;

		cout << "Now enter the elements:\n";
		for(int i = 1; i <= n; i++) {
			cin >> val[i];
		}

		cout << "Now enter their weights: \n";
		for(int i = 1; i <= n; i++) {
			cin >> wt[i];
		}

		for(int i = 1; i <= n; i++) {
			for(int w = 1; w <= max_weight; w++) {
				if (wt[i] > w) {
					table[i][w] = table[i-1][w];
				}
				else if (wt[i] <= w) {
					table[i][w] = max(table[i-1][w], val[i] + table[i-1][w-wt[i]]);
				}
			}	
		}

		cout << "Your table is:\n";
		for(int i = 0; i <= n; i++) {
			for(int j = 0; j <= max_weight; j++) {
				cout << table[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "\nDo you want to continue? (yes/no): ";
		cin >> value;

	}


	return 0;
}