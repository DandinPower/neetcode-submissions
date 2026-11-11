struct DoublyListNode {
    DoublyListNode* prev;
    DoublyListNode* next;
    string url;

    DoublyListNode(DoublyListNode* prev_ptr, DoublyListNode* next_ptr, string url_str) 
        : prev(prev_ptr), next(next_ptr), url(url_str) {} 
};


class BrowserHistory {
private:
    DoublyListNode* curr;
public:
    BrowserHistory(string homepage) {
        curr = new DoublyListNode(nullptr, nullptr, homepage);
    }
    
    void visit(string url) {
        DoublyListNode* temp = new DoublyListNode(curr, nullptr, url);
        
        DoublyListNode* ptr_for_deletion = curr->next;
        while (ptr_for_deletion != nullptr) {
            DoublyListNode* delete_ptr = ptr_for_deletion;
            ptr_for_deletion = ptr_for_deletion->next;
            delete delete_ptr;
        }

        curr->next = temp;
        curr = curr->next;
    }
    
    string back(int steps) {
        while (steps > 0 && curr->prev != nullptr) {
            steps -= 1;
            curr = curr->prev;
        }
        return curr->url;
    }
    
    string forward(int steps) {
        while (steps > 0 && curr->next != nullptr) {
            steps -= 1;
            curr = curr->next;
        }
        return curr->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */