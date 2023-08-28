#include<queue>

using std::queue;

class MyStack {
public:
queue<int> q1;
    MyStack() {
        
    }
    
    void push(int x) {
        
        q1.push(x);

        int a = q1.size() -1;
        int i = 0;

        while(i < a) {
            q1.push(q1.front());
            i++;
            q1.pop();
        }

    }
    
    int pop() {

        int b = q1.front();
        q1.pop();
        return b;

    }
    
    int top() {

        return q1.front();

    }
    
    bool empty() {
        
        return q1.size() == 0;

    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */