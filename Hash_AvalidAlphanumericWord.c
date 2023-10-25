/*
 * date ：2023/10/25
 * title：哈希表---有效的字母异位词
 * brief：给定两个字符串s和t，编写一个函数来判断t是否是s的字母异位次
 * example：
 *          input  : s = "anagram" , t = "nagaram"
 *          output : true
 *          input  : s = "rat" , t = "car"
 *          output : false
*/


#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isAnagram(char *s, char *t)
{
    int record[26] = {0};
    for(int i = 0; i < strlen(s); i++)
    {
        /* 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了 */
        record[s[i] - 'a']++;        
    }
    for(int i = 0; i < strlen(t); i++)
    {
        record[t[i] - 'a']--;
    }
    for(int i = 0; i<26; i++)
    {
        if(record[i] != 0)
        {
            return false;
        }
    }
    return true;
}       


int main() {

    char s[] = "rat";
    char t[] = "car";
    
    if (isAnagram(s, t)) {
        printf("'%s' and '%s' are anagrams.\n", s, t);
    } else {
        printf("'%s' and '%s' are not anagrams.\n", s, t);
    }
    
    return 0;
}


