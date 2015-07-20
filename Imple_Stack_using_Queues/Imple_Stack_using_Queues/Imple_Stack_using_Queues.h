// Implement the following operations of a stack using queues.
// 
// push(x) --Push element x onto stack.
// pop() --Removes the element on top of the stack.
// top() --Get the top element.
// empty() --Return whether the stack is empty.
// Notes:
// You must use only standard operations of a queue -- which means only push to back, peek / pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque(double - ended queue), 
// as long as you use only standard operations of a queue.
// You may assume that all operations are valid(for example, no pop or top operations will be called on an empty stack).

#include <queue>

using namespace std;


class Stack {
public:
    Stack() : lastPushed(-1){}


    // Push element x onto stack.
    void push(int x) {
        this->internalQueue.push(x);
        this->lastPushed = x;
    }

    // Removes the element on top of the stack.
    void pop() {
        const int qSize = this->internalQueue.size();
        int output = 0;
        for (int i = 0; i < qSize - 1; ++i){
            output = this->internalQueue.front();
            this->internalQueue.pop();
            this->internalQueue.push(output);
            this->lastPushed = output;
        }
        this->internalQueue.pop();
    }

    // Get the top element.
    int top() {
        return this->lastPushed;
    }

    // Return whether the stack is empty.
    bool empty() {
        return this->internalQueue.empty();
    }

    queue<int> internalQueue;
    int lastPushed;
};