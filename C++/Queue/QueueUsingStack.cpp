class MyQueue {
    stack<int> stk1;
    stack<int> stk2;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        
        return peek(true);
    }

    /** Get the front element. */
    int peek(bool pop = false) {
        while (stk1.size() > 0)
        {
            int val = stk1.top();
            stk2.push(val);
            stk1.pop();
        }
        int res = stk2.top();
        if(pop)
            stk2.pop();
        while (stk2.size() > 0)
        {
            int val = stk2.top();
            stk1.push(val);
            stk2.pop();
        }
        return res;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
    }
};
