/*
 * date ：2023/10/30
 * title：哈希表---快乐数
 * brief：编写一个算法来判断一个数n是不是快乐数。快乐数：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为1
 *        也可能是无限循环但始终变不到1.如果可以变为1，那么这个数就是快乐数。
 *        如果n是快乐数就返回True；不是，则返回False
 * example：
 *          input  : 19
 *          output : true
 *          1^2 + 9^1 = 82
 *          8^2 + 2^2 = 68
 *          6^2 + 8^2 = 100
 *          1^2 + 0^2 + 0^2 = 1
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/**
 *  这段代码有效地将一个整数 n 拆分为各位数字，计算它们的平方和，然后返回这个和。
*/
int get_sum(int n){
    int sum = 0;
    /* div_t 是一个结构类型，用于存储整数除法的结果（商和余数）。.quot是div_t结构体中的一个成员，用于存储整数除法的商 */
    /* 
    typedef struct {
        int quot; // 商
        int rem;  // 余数
    } div_t;
    .quot 是结构体成员（structure member）的引用方式，用于访问结构体内部的成员变量。在C语言中，要访问结构体的成员，你需要使用成员访问运算符 .（点号）。
    */
    div_t n_div = { .quot = n };

    while (n_div.quot != 0)
    {
        /* 从低位开始算 */
        n_div = div(n_div.quot, 10);
        sum += n_div.rem * n_div.rem;
    }
    return sum;
}


/* 用于检查数组中的那个位置是否已经检查过 */
bool isHappy1(int n){
    uint8_t visited[163] = {0};
    int sum = get_sum(get_sum(n));
    int next_n = sum;

    while (next_n != 1)
    {
        sum = get_sum(next_n);
        if(visited[sum]) return false;
        visited[sum] = 1;
        next_n = sum;
    };
    return true;
}

bool isHappy2(int n){
    int slow = n;
    int fast = n;
    do
    {
        slow = get_sum(slow);
        fast = get_sum(get_sum(fast));
    } while (slow != fast);
    /* 也是一个判断数 */
    return (fast == 1);
}

int main() {
    int a = 19;
    int result = isHappy1(a);
    printf("result: %d\n", result); 
    return 0;
}



