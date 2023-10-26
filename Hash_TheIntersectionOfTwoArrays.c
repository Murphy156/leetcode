/*
 * date ：2023/10/26
 * title：哈希表---两个数组的交集
 * brief：给定两个数组，编写一个函数来计算它们的交集
 * example：
 *          input  : num1 = [1,2,2,1], num2 = [2,2]
 *          output : [2]
 *          input  : num1 = [4,9,5], num2 = [9,4,9,8,4]
 *          output : [9,4]
 * 说明：输出结果中的每个元素一定是唯一的，我们可以不考虑输出结果的顺序。
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int numsCnt[1000] = {0};
    /*  
        int nums1Size = sizeof(nums1) / sizeof(int);
        int nums2Size = sizeof(nums2) / sizeof(int);
        sizeof(nums1) 和 sizeof(nums2) 在函数参数中不会给出数组的正确大小，因为在函数中数组变成了指针，sizeof 操作符返回的是指针的大小。
        要获取正确的数组大小，你应该在调用函数时将数组的大小作为参数传递，就像你之前所做的一样：
        int nums1Size = 3;  // 传递正确的数组大小
        int nums2Size = 5;  // 传递正确的数组大小
        int *result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);
    */
    int lessSize = nums1Size < nums2Size ? nums1Size : nums2Size;
    /* 
        void *calloc(size_t num_elements, size_t element_size);
        这个函数接受两个参数
        'num_elements' : 要分配内存块的元素数量
        'element_size' : 每个元素的大小（以字节为单位）
        calloc函数将为num_elements * element_size字节的内存分配空间，并将该内存初始化为零。
        这是与malloc函数的一个重要区别，因为malloc函数分配的内存不会自动初始化，它包含了之前分配给其他程序的数据，这可能导致安全性和稳定性问题。
     */
    int* result = (int *)calloc(lessSize, sizeof(int));
    int resultIndex = 0;
    int* tempNums;
    int i;
    /* 统计num1中每个元素出现的重复次数 */
    for(i = 0; i < nums1Size; i++)
    {
        printf("the current nums1: %d \n", nums1[i]);
        numsCnt[nums1[i]]++;
    }

    for(i = 0; i < nums2Size; i++)
    {
        if(numsCnt[nums2[i]] > 0)
        {
            result[resultIndex] = nums2[i];
            resultIndex ++;
            numsCnt[nums2[i]] = 0;
        }
    }
    *returnSize = resultIndex;
    return result;
}

int main() {
    int nums1[] = {4, 9, 5};
    int nums2[] = {9, 4, 9, 8, 4};
    int nums1Size = sizeof(nums1) / sizeof(int);
    int nums2Size = sizeof(nums2) / sizeof(int);
    int returnSize;
    int *result = intersection(nums1, nums1Size, nums2, nums2Size, &returnSize);
    fflush(stdout);     // 强制刷新缓冲区
    printf("intersection: \n");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    return 0;
}
