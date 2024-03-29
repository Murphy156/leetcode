#include <stdio.h>
#include <string.h>

#define CHAR_RANGE 256 // 假设字符串范围是ASCII

int lengthOfLongestSubstring(char *s)
{
    int n = strlen(s);
    int maxLength = 0;              // 用于存储最长子串的长度
    int start = 0;                  // 滑动窗口的起始位置
    int lastIndices[CHAR_RANGE];    // 存储字符最后一次出现的索引
    // 初始化索引为-1，表示未出现
    for(int i = 0; i < CHAR_RANGE; i++)
    {
        lastIndices[i] = -1;
    }

    for(int i = 0; i < n; i++)
    {
        start = (lastIndices[s[i]] + 1 > start) ? lastIndices[s[i]] + 1 : start; // 更新起始位置
        maxLength = (i - start + 1 > maxLength) ? i - start + 1 : maxLength;     // 更新最长子串长度
        lastIndices[s[i]] = i;                                                   // 更新当前字符的最后出现位置
    }
    return maxLength;
}

int main() {
    char str[] = "abcabcbb";
    printf("The length of the longest substring without repeating characters is: %d\n", lengthOfLongestSubstring(str));
    printf("Hello World");
    
    return 0;
}