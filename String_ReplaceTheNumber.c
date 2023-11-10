/*
 * date ：2023/11/9
 * title：字符串 --- 替换数字
 * brief：给定一个字符串s，它包含小写字母和数字字符，请编写一个函数，将字符串中的字母字符保持不变，而将每个数字字符替换为number
 * example：
 *         INPUT : "a5b"
 *         OUTPUT:"anumberb"
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

void replaceDigitsWithNumber(char *s) {
    int count = 0;
    int sOldSize = strlen(s);

    // 统计字符串中的数字个数
    for (int i = 0; i < sOldSize; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            count++;
        }
    }

    // 调整字符串大小以容纳替换后的内容
    int sNewSize = sOldSize + count * 5;

    // 从后往前遍历字符串，进行替换操作
    for (int i = sNewSize - 1, j = sOldSize - 1; j < i; i--, j--) {
        if (s[j] > '9' || s[j] < '0') {
            s[i] = s[j];
        } else {
            s[i] = 'r';
            s[i - 1] = 'e';
            s[i - 2] = 'b';
            s[i - 3] = 'm';
            s[i - 4] = 'u';
            s[i - 5] = 'n';
            i -= 5;
        }
    }
    return 0;
}


int main() {

    char testString1[] = "abc123xyz";
    char testString2[] = "1a2b3c";
    char testString3[] = "hello123";
    
    printf("Original String 1: %s\n", testString1);
    replaceDigitsWithNumber(testString1);
    printf("Modified String 1: %s\n\n", testString1);

    printf("Original String 2: %s\n", testString2);
    replaceDigitsWithNumber(testString2);
    printf("Modified String 2: %s\n\n", testString2);

    printf("Original String 3: %s\n", testString3);
    replaceDigitsWithNumber(testString3);
    printf("Modified String 3: %s\n", testString3);

    return 0;
}

