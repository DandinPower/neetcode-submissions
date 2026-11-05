class MinStack {

private:
    vector<int> data_buffer;
    vector<int> min_data_buffer;
public:
    MinStack() {
    }
    
    void push(int val) {
        if (min_data_buffer.empty()) {
            min_data_buffer.push_back(val);
        }
        else {
            if (val <= min_data_buffer.back()) {
                min_data_buffer.push_back(val);
            }   
        }  
        data_buffer.push_back(val);   
    }
    
    void pop() {
        if (data_buffer.back() == min_data_buffer.back()) {
            min_data_buffer.pop_back();
        }
        data_buffer.pop_back();
    }
    
    int top() {
        return data_buffer.back();
    }
    
    int getMin() {
        return min_data_buffer.back();
    }
};
