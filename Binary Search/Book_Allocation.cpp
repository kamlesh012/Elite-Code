//Binary Search on Answer.
//Book Allocation
//Similar Problem-Split Array Largest Sum (LeetCode)


//The Idea is to find a minimum possible maximum book size that can be allocated to m students.

//If a suitable book size is found try to minimize it.
//Else increase the book size.

#include <iostream>
#include <algorithm>//*max_element()
#include <numeric>//accumulate

using namespace std;

bool isValid(int a[], int n, int m, int mid) {

	int student = 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
		if (sum > mid) {
			// cout << "Before :" << sum << " ";
			sum = a[i];
			// cout << "After :" << sum << " " << endl;
			student++;
		}
		if (student > m)return false;
	}
	return true;
}

int allocate(int a[], int n, int m) {

	if (n < m)return -1;

	int high = accumulate(a, a + n, 0);
	int low = 0;//can be *max_element(a,a+n) also Doesn't matter though.
	int ans = -1;

	while (low <= high) {

		int mid = low + ((high - low) / 2);

		if (isValid(a, n, m, mid)) {
			ans = mid;
			high = mid - 1;
		}
		else low = mid + 1;
	}
	return ans;
}

int main() {
	int t; cin >> t;
  
	while (t--) {
    
		int n; cin >> n;
    
		int a[n];
		for (int i = 0; i < n; i++)cin >> a[i];
		int m; cin >> m;
    
		cout << allocate(a, n, m) << endl;
    
	}
}
//14-May-2022
