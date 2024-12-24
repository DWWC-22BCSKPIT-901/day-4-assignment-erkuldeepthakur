#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    
    MinStack() {}

   
    void push(int val) {
        mainStack.push(val);
        
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        } else {
            minStack.push(minStack.top());
        }
    }

    
    void pop() {
        mainStack.pop();
        minStack.pop();
    }

    
    int top() {
        return mainStack.top();
    }

    
    int getMin() {
        return minStack.top();
    }
};

int main() {
    
    MinStack minStack;
    
   
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);

    
    cout << minStack.getMin() << endl; 

   
    minStack.pop();

    
    cout << minStack.top() << endl; 

    
    cout << minStack.getMin() << endl; 

    return 0;
}
