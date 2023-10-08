/*
 * date：2023/10/07
 * title：有序数组的平方
 * brief：给你一个按非递减顺序排序的整数数组nums，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。
 * example：
 *          输入：nums = [-4,-1,0,3,10]
 *          输出：[0,1,9,16,100]
 *          解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]
*/



#include <stdlib.h>
#include <stdio.h>

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int left = 0;
    int right = numsSize - 1;

/*
    malloc 函数：
    malloc 是C语言中的一个函数，用于动态分配内存。它接受一个参数，即要分配的内存空间的字节数，然后返回一个指向分配内存的指针。
    如果分配成功，返回的指针指向一段未初始化的内存区域，大小为参数指定的字节数。

    sizeof(int) * numsSize：
    sizeof(int) 返回一个整数的字节数。因此，sizeof(int) * numsSize 计算出了需要分配的内存空间大小。在这里，我们希望分配能够存储 numsSize 个整数的空间

    类型转换 ((int*)malloc(...)):
    返回的指针是 void* 类型，但是我们想要将其转换为指向整数 (int*) 的指针类型。这样做是为了方便后续对这段内存进行整数类型的操作，因为 malloc 返回的指针是通用指针类型 (void*)。

    这行代码分配了足够的内存空间，以容纳 numsSize 个整数，然后将返回的指针转换为 int* 类型并赋给变量 ans。这样，
    ans 就指向了一段可以存储 numsSize 个整数的内存空间，可以在该内存空间中存储排序后的平方值数组。
*/
    int* ans = (int*)malloc(sizeof(int) * numsSize);

    if (ans == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    int index;

    for (index = numsSize - 1; index >= 0; index--) {
        int lSquare = nums[left] * nums[left];
        int rSquare = nums[right] * nums[right];

        if (lSquare > rSquare) {
            ans[index] = lSquare;
            left++;
        } else {
            ans[index] = rSquare;
            right--;
        }
    }

    return ans;
}

int main() {
    int num[] = {-4, -1, 0, 3, 10};
    int* ans;
    int returnSize;

    ans = sortedSquares(num, 5, &returnSize);

    printf("Sorted squares: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    // 释放动态分配的内存
    free(ans);

    return 0;
}
