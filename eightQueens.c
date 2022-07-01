#include<stdio.h> 
#include<stdbool.h>

#define N 8
#define TRUE 0
#define FALSE 1

bool isSafe(int** p, int x, int y);
void find(int** box, int* nums, int row, int columns, int count);
void f(int** box);
void printNums(int* nums, int size);
void primaryResult(int *count, int* nums);

void main() {
    int box[8][8] = {0};
    int* p[8];
    for (int i = 0; i < 8; i++) {
        p[i] = box[i];
    }
    f(p);        
}

void f(int** box) {
    int nums[N] = {0};
    int row = 0, columns = 0, count = 0;         
    find(box, nums, row, columns, count);
}

void find(int** box, int* nums, int row, int columns, int count) {
    while (row >= 0 && row < N && columns < N && columns >= 0) {
        if (isSafe(box, row, columns)) {          // 是否可以放置皇后
            box[row][columns] = FALSE;
            nums[row] = columns;
            columns = 0;
            if (row++ == N-1) {               
                primaryResult(&count, nums);   // print 
                columns = nums[--row];   // back
                return find(box, nums, row, columns, count);
            }
        }
        else if (columns == N-1) {     // 所在行没有放置皇后的位置
            box[row][columns] = 0;
            columns = nums[--row];   // back
            return find(box, nums, row, columns, count);
        }
        else {
            box[row][columns++] = TRUE;     // renew
        }
    }
}

bool isSafe(int** p, int x, int y) {
    for (int i = 0; i < x; i++) {       // vertical inspection
        if (p[i][y] == FALSE) return false;
    }
    int n = 0;
    while (x - n >= 0 && y - n >= 0) {        // top left inspection
        if (p[x - n][y - n] == FALSE) return false;
        n++;
    }
    n = 0;       // renew
    while (y + n <= 7 && x - n >= 0) {        // top right inspcetion
        if (p[x - n][y + n] == FALSE) return false;
        n++;
    }
    return true;
}

void printNums(int* nums, int size) {
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", i, nums[i]);
    }
    printf("\n");
}

void primaryResult(int *count, int* nums) {
    (* count)++;
    printf("第%d种: ", *count);
    printNums(nums, N);
    printf("-----------------------------------------------------------------\n");
}
