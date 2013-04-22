/* 利用位运算的加法逆元（a^a = 0），及异或运算可交换、可结合
 * 来实现不需额外空间的值交换 */

#include <stdio.h>

#define LEN 5

void inplace_swap(int *x, int *y) {
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;
}

void reverse_array(int a[], int cnt) {
    int first, last;
    for(first=0, last=cnt-1; first < last; first++, last--)
        inplace_swap(&a[first], &a[last]);
}

void print_array(int a[], int cnt) {
    int i;
    for(i=0; i<cnt; i++) {
        printf(" %d", a[i]);
        if(i==cnt-1)printf("\n");
    }
}

int main() {
    int x = 3, y = 7;
    printf("before: %d, %d\n", x, y);
    inplace_swap(&x, &y);
    printf("after : %d, %d\n", x, y);

    int a[LEN] = {1, 2, 3, 4, 5};
    printf("before:\n");
    print_array(a, LEN);
    reverse_array(a, LEN);
    printf("after :\n");
    print_array(a, LEN);

    return 0;
}
