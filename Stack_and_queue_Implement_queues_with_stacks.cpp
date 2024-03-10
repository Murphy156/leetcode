/*
 * date ：2024/02/20
 * title：栈和队列 --- 用栈实现队列
 * brief：使用栈实现队列的下列操作：
 * example：
 *         push(x) -- 将一个元素放入队列的尾部。
 *         pop() -- 从队列首部移除元素。
 *         peek() -- 返回队列首部的元素。
 *         empty() -- 返回队列是否为空。 
*/

#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    /** Push element x to the back of queue. */
    void push(int x) {
        stIn.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        // 只有当stOut为空的时候，再从stIn里导入数据（导入stIn全部数据）
        if (stOut.empty()) {
            // 从stIn导入数据直到stIn为空
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int result = stOut.top();
        stOut.pop();
        return result;
    }

    /** Get the front element. */
    int peek() {
        int res = this->pop(); // 直接使用已有的pop函数
        stOut.push(res); // 因为pop函数弹出了元素res，所以再添加回去
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

int main() {
    MyQueue q;

    // 测试push函数
    q.push(1);
    q.push(2);
    q.push(3);

    // 测试pop函数
    cout << "Pop: " << q.pop() << endl;

    // 测试peek函数
    cout << "Peek: " << q.peek() << endl;

    // 测试empty函数
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}



