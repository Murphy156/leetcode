/*
 * date ：2023/11/14
 * title：字符串 --- 翻转字符串中的单词
 * brief：给定一个字符串，你需要翻转字符串中每个单词的字符顺序，同时仍保留空格和单词间的分隔。
 * example：
 *         INPUT : "the sky is blue"
 *         OUTPUT: "blue is sky the"
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>


/* 翻转字符串中指定范围的字符 */
void reverse(char* s,int start, int end){
    for(int i = start, j = end; i < j; i++ , j--){
        int temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* 删除字符串两端和中间多余的空格 */
void removeExtraSpace(char* s){
    int start = 0;  /* 指向字符串开头的指针 */
    int end = strlen(s) - 1; /* 指向字符串末尾的指针 */
    while(s[start] == ' ')start++; /*移动指针start,直到找到第一个非空格字符*/
    while(s[end] == ' ')end--; /* 移动指针end，直到找到第一个非空格字符 */
    int slow = 0; /* 指向字符串的下一个写入位置的指针 */
    for (int i = start; i <= end; i++)/* 遍历整个字符串，如果当前字符是空格，并且下一个字符也是空格，则跳过 */
    {
        if (s[i] == ' '&&s[i+1] == ' ')
        {
            continue;
        }
        s[slow] = s[i]; /* 否则，将当前字符复制到新字符串的slow位置 */
        slow++;         /* 将slow指针向后移动 */
    }
    s[slow] = '\0';
}

/* 翻转字符串中的单词 */
char* reverseWord(char* s){
    removeExtraSpace(s);    /* 先删除字符串两端和中间的多余空格 */
    reverse(s,0,strlen(s)-1);   /* 翻转整个字符串 */
    int slow = 0;/* 指向每个单词的开头位置和指针 */
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == ' '||s[i] == '\0')
        {
            reverse(s,slow,i-1); /* 翻转单词 */
            slow = i + 1;        /* 将slow指针指向下一个单词的开头位置 */
        }
    }
    return s; 
}


