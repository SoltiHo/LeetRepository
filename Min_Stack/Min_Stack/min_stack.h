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