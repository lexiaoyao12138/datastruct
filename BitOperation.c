#include <stdio.h>
#include <stdbool.h>

// 判断是否为奇数
// 通过判断二进制下最后一位 1/0
bool isOdd(int n) {
	return n & 0x1;
}

// 判断一个整数是否为2的次幂
// 通过
bool isPower_2(int n) {
	return (n & n - 1) == 0;
}

// last signle
int lastSignle(int n) {
	return n & (-n);
}

// 成对数字的数组，找出单独出现的数字
int findOnly(int a[], int len)  {
	int sign = 0;
	for (int i = 0; i < len; i ++ ) {
		sign ^= a[i];
	}
	return sign;
}

// 成对出现的数组，找出单独出现的两个数字
int a = 0, b = 0;
void findOnly_2(int arr[], int len) {
	int xor = 0;
	for (int i = 0; i < len; i++) {
		xor ^= arr[i];
	}
	int lastSetBit = xor & (-xor);
	for (int i = 0; i < len; i ++ ) {
		if (arr[i] & lastSetBit)	a ^= arr[i];
		else 	b ^= arr[i];
	}
}
