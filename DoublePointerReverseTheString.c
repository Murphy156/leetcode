/*
 * date ：2024/02/02
 * title：双指针法 --- 反转字符串
 * brief：编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
 * example：
 *         INPUT : ["h","e","l","l","o"]
 *         OUTPUT: ["o","l","l","e","h"]
 *         INPUT : ["H","a","n","n","a","h"]
 *         OUTPUT: ["h","a","n","n","a","H"]
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/**
 * @brief 反转字符串
 *
 * 将给定的字符串进行反转。
 *
 * @param s 字符串指针
 * @param sSize 字符串长度
 */
void reverseString(char* s, int sSize) {
    // 定义左指针
    int left = 0;
    // 定义右指针
    int right = sSize - 1;
    // 交换字符串
    while (left < right) {
        char temp = s[left];
        s[left++] = s[right];
        s[right--] = temp;
    }
}


int main() {
    char str[] = "hello";  // 示例字符串
    int strSize = sizeof(str) - 1;  // 计算字符串长度，减去末尾的 '\0'
    
    printf("Original string: %s\n", str);  // 打印原始字符串
    
    reverseString(str, strSize);  // 调用 reverseString 函数
    
    printf("Reversed string: %s\n", str);  // 打印反转后的字符串
    
    return 0;
}

