/*
 * date ：2023/10/31
 * title：哈希表---两数之和
 * brief：给定一个整数数组nums和一个目标值target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标
 *        假定每种输入只会对应一个答案，但是，数组中同一个元素不能使用两遍
 * example：
 *        给定 nums = [2,7,11,15], target = 9
 *        因为 nums[0] + nums[1] = 2 + 7 = 9
 *        所以返回[0,1]
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int* twoSum(int* nums, int numSize, int target, int* returnSize){

    int* result = (int*)malloc(2 * sizeof(int));

    *returnSize = 0;
    if (result == NULL){
        return NULL; /* 内存分配失败 */
    }

    int map[100000]; /* 假设数组中的数字具有最大值 */

    for(int i = 0; i < numSize; i++){
        /* 互补元素的识别 */
        /* 以主函数的例子解释
            当complement = 9 - 2 = 7
            因为不满足if条件
            所以让map[2] = 1
            当complement = 9 - 7 = 2
            发现map[2] != 0;发现互补元素，然后记录下来； 
         */
        int complement = target - nums[i];
        if(complement >= 0 && map[complement] !=0){
            result[0] = map[complement] - 1;
            result[1] = i;
            *returnSize = 2;
            break;
        }
        map[nums[i]] = i + 1;
    }
    return result;
}


int main() {
    int nums[] = {2, 7, 11, 4};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);
    
    if (returnSize == 2) {
        printf("索引: %d, %d\n", result[0], result[1]);
    } else {
        printf("未找到解。\n");
    }

    free(result); // 不要忘记在完成后释放分配的内存

    return 0;
}


