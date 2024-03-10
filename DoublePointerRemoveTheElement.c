/*
 * date ：2024/02/02
 * title：双指针法 --- 移除元素
 * brief：给你一个数组nums和一个值val, 你需要原地移除所有数值等于val的元素，并返回移除后数组的新长度。
 * example：
 *         INPUT : nums = [0,1,2,2,3,0,4,2], val = 2
 *         OUTPUT: 5
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

/**
 * @brief 从数组中移除指定元素并返回新数组长度
 *
 * 通过双指针法，将数组中不等于给定值的元素移到数组前面，并返回新数组的长度。
 *
 * @param nums 数组指针
 * @param numsSize 数组长度
 * @param val 要移除的元素值
 *
 * @return 新数组的长度
 */
int doublePointerRemoveElement(int* nums, int numsSize, int val) {
    int slow = 0;
    for(int fast = 0; fast < numsSize; fast++)
    {
        if(nums[fast] != val){
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}

int main() {
    int nums[] = {0,1,2,2,3,0,4,2}; 
    int val = 2; 
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int newNumsSize = doublePointerRemoveElement(nums, numsSize, val);

    printf("New array size: %d\n", newNumsSize);
    printf("Modified array: ");
    for (int i = 0; i < newNumsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

