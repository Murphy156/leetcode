/*
 * date ：2023/11/2
 * title：哈希表---四数相加II
 * brief：给定四个包含整数的数组列表A,B,C,D，计算有多少个元组（i，j，k，l），使得A[i] + B[j] + C[k] + D[l] = 0
 *        为了简化问题，所有的A,B,C,D具有相同的长度N，且0 <= N <= 500。所有整数的范围在-2^28到2^28 - 1，最终结果不会超过2^23 - 1。
 * example：
 *        input：A = [1,2]、B = [-2,-1]、C = [-1,2]、D = [0,2]
 *        output：2
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int fourSumCount(int* A,int ASize, int* B, int BSize, int* C,int CSize, int* D, int DSize){

    int* umap = (int*)malloc(2 * ASize * BSize * sizeof(int)); /* 一个数组用来存储a + b的数量 */

    /* 初始化umap数组的值 */
    for(int i = 0; i < 2 * ASize * BSize; i++){
        umap[i] = 0;
    }

    for (int i = 0; i < ASize; i++)
    {
        for (int j = 0; j < BSize; j++)
        {
            /* 这里是为了确保足够大以容纳可能的‘a + b’值的范围 */
            umap[A[i] + B[j]]++;
        }
    }

    int count = 0; /* 统计a + b + c + d = 0的次数*/
    
    /* 检查0 - (c + d)是否存在于umap数组中，如果存在，则将其数量添加到总计数中 */
    for (int i = 0; i < CSize; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (0 - (C[i] + D[j]) >= 0 && 0 - (C[i] + D[j]) < 2 * ASize * BSize)
            {
                /* 
                    a + b = -(c + d)
                    所以他们在位置上匹配时，即可加入count
                 */
                count += umap[0 - (C[i] + D[j])];          
            }
        }
    }

    free(umap);

    return count;
}


int fourSumCount2(int* A, int ASize, int* B, int BSize, int* C, int CSize, int* D, int DSize) {
    int count = 0;
    int* ABsums = (int*)malloc(ASize * BSize * sizeof(int));

    // 计算A和B的所有可能和的组合，并存储在ABsums数组中
    int index = 0;
    for (int i = 0; i < ASize; i++) {
        for (int j = 0; j < BSize; j++) {
            ABsums[index++] = A[i] + B[j];
        }
    }

    // 使用哈希表来记录ABsums数组中各元素出现的次数
    int* hash = (int*)calloc(2001, sizeof(int));
    for (int i = 0; i < ASize * BSize; i++) {
        hash[ABsums[i] + 1000]++;
    }

    // 遍历C和D的所有可能和，查看其相反数在ABsums数组中出现的次数
    for (int i = 0; i < CSize; i++) {
        for (int j = 0; j < DSize; j++) {
            int target = 0 - (C[i] + D[j]);
            count += hash[target + 1000];
        }
    }

    free(ABsums);
    free(hash);

    return count;
}

int main() {
    int A[] = {0};
    int B[] = {0};
    int C[] = {0};
    int D[] = {0};
    int result = fourSumCount2(A, 2, B, 2, C, 2, D, 2);
    printf("a+b+c+d=0的次数:%d\n", result);
    return 0;
}


