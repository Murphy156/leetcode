/*
 * date ：2023/11/3
 * title：哈希表---赎金信
 * brief：给定一个赎金信（ransom）字符串和一个杂志（magazine）字符串，判断第一个字符串ransom能不能由第二个字符串magazine里面的字符构成，如果可以构成，返回true；否则返回false
 *        你可以假设两个字符串均只含有小写字母。
 * example：
 *         canConstruct("a", "b") -> false 
 *         canConstruct("aa", "ab") -> false
 *         canConstruct("aa", "aab") -> true  
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>


bool canConstruct(char* ransomNote, char* magazine)
{
    int record[26] = {0};

    if (strlen(ransomNote) > strlen(magazine))
    {
        return false;
    }
    
    /* 遍历杂志，记录每一个字母出现的次数 */
    for (int i = 0; i < strlen(magazine); i++)
    {
        /* 存储的是字符，所以要做处理 */
        record[magazine[i] - 'a']++;
    }

    /* 遍历赎金信，从record数组中对应的字符次数减一 */
    for (int i = 0; i < strlen(ransomNote); i++)
    {
        record[ransomNote[i] - 'a']--;

        if (record[ransomNote[i] - 'a'] < 0) {
            return false;
        }
    }
    return true;
}


int main() {
    char ransomNote[] = "a";
    char magazine[] = "b";

    if (canConstruct(ransomNote, magazine)) {
        printf("可以构建赎金信。\n");
    } else {
        printf("无法构建赎金信。\n");
    }
    return 0;
}