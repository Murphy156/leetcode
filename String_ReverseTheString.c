/*
 * date ：2023/11/7
 * title：字符串 --- 反转字符串
 * brief：编写一个函数，其作用是将输入的字符串反转过来。输入的字符串以字符数组char[]的形式给出。不要给另外的数组分配额外的空间，必须原地修改输入数组
 *        使用o（1）的额外空间解决这一问题。
 * example：
 *         INPUT:["H","E","L","L","O"]
 *         OUTPUT:["O","L","L","E","H"]
 *         INPUT:["H","A","N","N","A","H"]
 *         OUTPUT:["H","A","N","N","A","H"]
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void reverseString(char* s, int sSize){
    int left = 0;
    int right = sSize - 1;

    while (left < right)
    {
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}

void printArray(char* s, int sSize) {
    for (int i = 0; i < sSize; i++) {
        printf("\"%c\"", s[i]);
        if (i < sSize - 1) {
            printf(",");
        }
    }
    printf("\n");
}

int main() {
    char str1[] = {'H', 'E', 'L', 'L', 'O'};
    int size1 = 5;

    char str2[] = {'H', 'A', 'N', 'N', 'A', 'H'};
    int size2 = 6;

    printf("Input 1: ");
    printArray(str1, size1);

    reverseString(str1, size1);

    printf("Output 1: ");
    printArray(str1, size1);

    printf("Input 2: ");
    printArray(str2, size2);

    reverseString(str2, size2);

    printf("Output 2: ");
    printArray(str2, size2);

    return 0;
}
