#include <iostream>

using namespace std;

const int N = 1000010;
const int n = 10;          // ex
int q[n] {34, 12,67,0,6,34,66,77,45, 8};
int temp[N];

void merge_sort(int q[], int l, int r) {
	if (l >= r) return;
	int mid = (l + r) >> 1;

	merge_sort(q, l, mid), merge_sort(q, mid+1, r);
	int k = 0, i = l, j = mid + 1;
	while (i <= mid && j <= r) {
		if (q[i] <= q[j]) temp[k++] = q[i++];
		else temp[k++] = q[j++];
	}

	while (i <= mid) temp[k++] = q[i++];
	while (j <=r ) temp[k++] = q[j++];

	for (i = l, j = 0; i <= r; i++, j++) q[i]= temp[j];
}

int main() {
	merge_sort(q, 0, n-1);
	for (auto item : q)
		cout << item << " ";
	cout << endl;
	return 0;
}
