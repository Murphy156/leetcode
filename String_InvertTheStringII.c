/*
 * date ：2023/11/9
 * title：字符串 --- 反转字符串
 * brief：给定一个字符串s和一个整数k，从字符串开头算起，每计数至2k个字符，就反转这2k个字符中的前k个字符
 *        如果剩余字符少于k个，则将剩余字符全部反转，如果剩余字符小于2k但大于或等于k个，则反转前k个字符
 *        其余字符保持原样。
 * example：
 *         INPUT:s = "abcdefg" , k = 2
 *         OUTPUT:"bacdfeg"
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

char * reverseStr(char* s,int k){
    int len = strlen(s);
    for (int i = 0; i < len; i += (2 * k))
    {
        k = i + k > len ? len - i : k;

        int left = i;
        int right = i + k - 1;
        while (left < right)  
        {
            char temp = s[left];
            s[left++] = s[right];
            s[right--] = temp;
        }
    }
    return s;
}


