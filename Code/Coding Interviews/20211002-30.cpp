class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> x_stack;
    stack<int> min_stack;
    MinStack()
    {
        min_stack.push(INT_MAX);
    }

    void push(int x)
    {
        x_stack.push(x);
        min_stack.push(std::min(min_stack.top(), x));
    }

    void pop()
    {
        if (!x_stack.empty())
        {
            x_stack.pop();
            min_stack.pop();
        }
    }

    int top()
    {
        if (!x_stack.empty())
            return x_stack.top();
        else
            return -1;
    }

    int min()
    {
        if (!min_stack.empty())
            return min_stack.top();
        else
            return -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */