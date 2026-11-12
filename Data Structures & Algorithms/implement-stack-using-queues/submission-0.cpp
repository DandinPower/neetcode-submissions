class MyStack {
private: 
    queue<int> data;
public:
    MyStack() {}
    
    void push(int x) {
        int original_size = data.size();
        data.push(x);
        for (int i=0; i<original_size; i++) {
            int temp = data.front();
            data.pop();
            data.push(temp);
        }
    }
    
    int pop() {
        int temp = top();
        data.pop();
        return temp;
    }
    
    int top() {
        return data.front();
    }
    
    bool empty() {
        return data.empty();
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