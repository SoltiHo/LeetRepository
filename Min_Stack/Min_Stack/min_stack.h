// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// 
// push(x) --Push element x onto stack.
// pop() --Removes the element on top of the stack.
// top() --Get the top element.
// getMin() --Retrieve the minimum element in the stack.
#include <stack>
#include <algorithm>
using namespace std;


class MinStack {
public:
    void push(int x) {
        this->_valueStack.push(x);
        if (this->_minStack.size() > 0){
            this->_minStack.push(min(this->_minStack.top(), x));
        }
        else{
            this->_minStack.push(x);
        }
        
    }

    void pop() {
        if (this->_valueStack.size() > 0){
            this->_valueStack.pop();
            this->_minStack.pop();
        }
    }

    int top() {
        if (this->_valueStack.size() > 0){
            return this->_valueStack.top();
        }
        else{
            return INT_MAX;
        }
    }

    int getMin() {
        if (this->_valueStack.size() > 0){
            return this->_minStack.top();
        }
        else{
            return INT_MAX;
        }
    }
private:
    stack<int> _valueStack;
    stack<int> _minStack;
};



class MinStack {
public:
    struct StackNode {
        int value;
        int minSoFar;
    };

    stack<StackNode> _internalStack;

    void push(int x) {
        if (_internalStack.size() > 0){
            _internalStack.push({ x, min(_internalStack.top().minSoFar, x) });
        }
        else{
            _internalStack.push({ x, x });
        }
        
    }

    void pop() {
        _internalStack.pop();
    }

    int top() {
        return _internalStack.top().value;
    }

    int getMin() {
        return _internalStack.top().minSoFar;
    }
};