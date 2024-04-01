/*
 * date ：2024/03/29
 * title：数组中的第K个最大元素
 * brief：给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 *        请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * example：
 *          input  ： [3,2,1,5,6,4], k = 2
 *          output ： 5
 *          input  :  [3,2,3,1,2,4,5,5,6], k = 4
 *          output :  4
*/

/*
 * 思路：冒泡排大，然后就行了
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

// int QuickSort(int a[], int l, int r, int k)
// {
//     if(l >= r) return a[l];

//     int i = l - 1, j = r + 1, x = a[l + r >> 1];
//     while(i < j)
//     {
//         do i ++; while(a[i] < x);
//         do j --; while(a[j] > x);
//         if(i < j)
//         {
//             int con = a[i];
//             a[i] = a[j];
//             a[j] = con;
//         }
//     }
//     int SL = j - l + 1;
//     if(SL >= k) return QuickSort(a, l, j, k);
//     else return QuickSort(a, j + 1, r, k - SL);
// }

// int findKthLargest(int* nums, int numsSize, int k){
//     return QuickSort(nums, 0, numsSize - 1, numsSize - k + 1);
// }

// 冒泡排序函数，按从大到小排序
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) { // 比较并交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// 寻找第k个最大元素
int findKthLargest(int* nums, int numsSize, int k) {
    // 先使用冒泡排序按从大到小排序
    bubbleSort(nums, numsSize);

    // 输出排序后的数组
    printf("排序后的数组: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    // 返回第k个最大元素
    return nums[k - 1]; // 数组索引从0开始，因此是k-1
}

// 测试用例
int main() {
    int arr[] = {3, 2, 3, 1, 5, 6, 4, 6};
    int numsSize = sizeof(arr) / sizeof(arr[0]);
    int k = 2; // 查找第2大的元素
    int result = findKthLargest(arr, numsSize, k);
    printf("第 %d 大的元素是 %d\n", k, result);
    return 0;
}




