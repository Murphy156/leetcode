/*
 * date：2023/10/08
 * title：长度最小的子数组
 * brief：给定一个含有n个正整数的数组和一个正整数s，找出该数组中满足其和>=s的长度最小的连续子数组，并返回其长度。如果不存在符合条件的子数组，返回0。
 * example：
 *          输入：s = 7,nums = [2,3,1,2,4,3]
 *          输出：2
 *          解释：子数组[4,3]是该条件下的长度最小的子数组。
*/

/* 
 * 思路：滑窗效果，一次移动一位。所谓滑动窗口，就是不断的调节子序列的起始位置和终止位置，从而得出我们要想的结果。题的关键在于 窗口的起始位置如何移动
 * 
*/

#include <stdlib.h>
#include <stdio.h>

int FindMinArr(int target, int* nums,int numSize)
{
    int minLength = numSize;
    int left = 0;
    int right = 0;
    int sum = 0;
    /*
      for(;;++i):for(;;i++):
      效果一样
    */
    for(;right < numSize;++right){
        sum += nums[right];
        while (sum >= target)
        {
            int subLength = right - left + 1;
            minLength = minLength < subLength ? minLength : subLength;
            sum -= nums[left++];
        }
    }
    return minLength == numSize ? 0 : minLength;
}

int main() {
    int num[] = {2, 3, 1, 2, 4, 3};
    int ans;
    int target = 7;
    int returnSize;

    ans = FindMinArr(target, num, 6);

    printf("FindMinArr: %d",ans);
    printf("\n");

    // 释放动态分配的内存
    free(ans);

    return 0;
}
