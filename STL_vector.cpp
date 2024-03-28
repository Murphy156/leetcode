#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec; // 声明一个int类型的vector

    // 添加元素
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    // 遍历vector的几种方式

    // 使用下标
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << "Element at index " << i << ": " << vec[i] << std::endl;
    }

    // 使用迭代器
    std::cout << "Using iterators:" << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }

    // 使用范围for循环（C++11及以上）
    std::cout << "Using range-based for loop:" << std::endl;
    for (int elem : vec) {
        std::cout << elem << std::endl;
    }

    // 访问元素
    std::cout << "First element: " << vec[0] << std::endl; // 使用下标
    std::cout << "Second element: " << vec.at(1) << std::endl; // 使用at()

    // 容量相关操作
    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Is empty?: " << vec.empty() << std::endl;

    // 移除元素
    vec.pop_back(); // 移除最后一个元素

    // 清空vector
    vec.clear();
    std::cout << "Size after clear: " << vec.size() << std::endl;

    return 0;
}
