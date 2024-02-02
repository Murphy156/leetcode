/*
 * date ：2023/11/20
 * title：字符串 --- 重复的子字符串
 * brief：给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。
 * example：
 *         INPUT : "abab"
 *         OUTPUT: True
 *         INPUT : "aba"
 *         OUTPUT: False
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>


void getNext(int* next, const char* s){
    int len = strlen(s);
    next[0] = -1;
    int j = -1;
    for (int i = 1; i < len; i++)
    {
        while(j >= 0 && s[i] != s[j + 1])
        {
            j = next[j];
        }
        if (s[i] == s[j + 1])
        {
            j++;
        }
        next[i] = j;
    }
}