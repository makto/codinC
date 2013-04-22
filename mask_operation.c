/* 1 运用位级运算来实现掩码运算
 * 2 实现CSAPP 35页练习题 */

#include <stdio.h>

// 位设置指令
int bis(int x, int m) {
    return x | m;
}

// 位清除指令
int bic(int x, int m) {
    return x & ~m;
}

// 利用bis和bic实现布尔或
int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}

// 利用bis和bic实现布尔异或
int bool_xor(int x, int y) {
    /* 下面这种写法比较复杂
     * 是通过研究y对x的改动而得到的
     * 即首先将所有y为1的位置为1，然后从中去掉x也为1的部分
     * int result = bic(bis(x, y) ,bic(x, bic(x, y)));
     * 其中bic(x, bic(x, y))得到的是x为1且y为1的位 */
    /* 更简洁的方式是
     * int result = bis(bic(x, y), bic(y, x));
     * 是通过研究何时结果中有1而得到的
     * 即，x中为1而y为0，或者y中为1而x中为0
     * 这也是异或最自然的表述 */
    int result = bis(bic(x, y), bic(y, x));
    return result;
}

int main() {
    int mask = 0xFF;
    int x = 0x87654321;

    printf("%.8x\n", x&mask);  //除最低位外，其余置为0
    printf("%.8x\n", x^~mask); //除最低位外，其余取补
    printf("%.8x\n", x|mask);  //最低位设全置为0

    // 分别验证bool_or和bool_xor的实现
    printf("%.8x\n", bool_xor(x, ~mask));
    printf("%.8x\n", bool_or(x, mask));

    return 0;
}
