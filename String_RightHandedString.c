/*
 * date ：2023/11/17
 * title：字符串 --- 右旋字符串
 * brief：字符串的右旋转操作是把字符串尾部的若干个字符转移到字符串的前面。给定一个非空字符串和一个整数，请将给定的字符串进行右旋转。
 * example：
 *         INPUT : 2， "anumber"
 *         OUTPUT:"eranumb"
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void reverseString(char* str, int start, int end) {
    while (start < end)
    {
        char temp = str[start];
        str[start] = str[end];;
        str[end] = temp;
        start++;
        end--;
    }
}

int main(){
    // Test case 1
    char test1[] = "abcdefg";
    int n1 = 3;

    printf("Original string: %s\n", test1);
    reverseString(test1, 0, n1 - 1);
    reverseString(test1, n1, strlen(test1) - 1);
    reverseString(test1, 0, strlen(test1) - 1);
    printf("Reversed string: %s\n", test1);

    // Test case 2
    char test2[] = "hello";
    int n2 = 2;

    printf("Original string: %s\n", test2);
    reverseString(test2, 0, n2 - 1);
    reverseString(test2, n2, strlen(test2) - 1);
    reverseString(test2, 0, strlen(test2) - 1);
    printf("Reversed string: %s\n", test2);

    return 0;
}
