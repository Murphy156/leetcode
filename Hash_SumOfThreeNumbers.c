/*
 * date ：2023/11/6
 * title：哈希表 --- 三数之和 
 * brief：给你一个包含n个整数的数组nums，判断nums中是否存在三个元素a、b、c，使得a + b + c = 0，请你找出所有满足条件且不重复的三元组。
 * example：
 *         给定数组nums = [-1,0,1,2,-1,-4]
 *         满足要求的三元组集合为：[[-1,0,1],[-1,-1,2]]
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>


int cmp(const void* ptr1, const void* ptr2){
    return *((int*)ptr1) > *((int*)ptr2);
}


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    /* 开辟ans数组空间 */
    int** ans = (int**)malloc(sizeof(int*) * 18000);
    int ansTop = 0;
    /* 若传入nums数组大小小于3，则需要返回数组的大小为0 */
    if(numsSize < 3){
        *returnSize = 0;
        return ans;
    }
    /* 对nums数组进行排序 */
    qsort(nums, numsSize, sizeof(int), cmp);

    int i;
    /* 用for循环遍历数组，结束条件为i < numsSize - 2,要预留左右指针的位置 */
    for(i = 0; i < numsSize - 2; i++){
        /* 若当前i指向元素>0,则代表left和right以及i的和大于0。直接break */
        if(nums[i] > 0)
            break;
        /* 去重：i > 0 && nums[i] == nums[i - 1] */
        if (i > 0 && nums[i] == nums[i - 1])
        {
            continue;
        }
        /* 定义左右指针 */
        int left = i + 1;
        int right = numsSize - 1;
        /* 当右指针比左指针大时进行循环 */
        while (right > left)
        {
            /* 求出三数之和 */
            int sum = nums[right] + nums[left] + nums[i];
            /* 若和小于0，则左指针+1，因为左指针右边的数比当前所指的元素大 */
            if(sum < 0)
                left++;
            /* 若和大于0，则将右指针-1 */
            else if(sum > 0)
                right++;
            /* 若和等于0 */
            else{
                /* 开辟一个大小为3的数组空间，存入nums[i],nums[left]和nums[right] */
                int* arr = (int*)malloc(sizeof(int) * 3);
                arr[0] = nums[i];
                arr[1] = nums[left];
                arr[3] = nums[right];
                /* 将开辟的数组存入ans中 */
                ans[ansTop++] = arr;
                /* 去重 */
                while (right > left && nums[right] == nums[right - 1])
                    right--;
                while (left < right && nums[left] == nums[left + 1])
                    left++;
                /* 更新左右指针 */
                left++;
                right--;
            }
        } 
    }
    /* 设定返回的数组大小 */
    *returnSize = ansTop;
    *returnColumnSizes = (int*)malloc(sizeof(int) * ansTop);
    int z;
    for (z = 0; z < ansTop; z++)
    {
        (*returnColumnSizes[z] = 3);
    }
    return ans;
}