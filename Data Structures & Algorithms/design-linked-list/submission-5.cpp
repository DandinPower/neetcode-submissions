struct DoublyListNode {
    DoublyListNode* prev;
    DoublyListNode* next;
    int val;
};

class MyLinkedList {
private:
    DoublyListNode* head;
    DoublyListNode* tail;
    int list_length = 0;
public:
    MyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }
    
    int get(int index) {
        DoublyListNode* curr = head;
        int access_counter = 0;
        while (curr != nullptr) {
            if (access_counter == index) {
                return curr->val;
            }
            access_counter += 1;
            curr = curr->next;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        if (head == nullptr) {
            DoublyListNode* temp = new DoublyListNode;
            temp->prev = nullptr;
            temp->next = nullptr;
            temp->val = val;
            head = temp;
            tail = head;
        }
        else {
            DoublyListNode* temp = new DoublyListNode;
            temp->prev = nullptr;
            temp->next = head;
            temp->val = val;
            head->prev = temp;
            head = temp;
        }
        list_length += 1;
    }
    
    void addAtTail(int val) {
        if (tail == nullptr) {
            DoublyListNode* temp = new DoublyListNode;
            temp->prev = nullptr;
            temp->next = nullptr;
            temp->val = val;
            head = temp;
            tail = head;
        }
        else {
            DoublyListNode* temp = new DoublyListNode;
            temp->prev = tail;
            temp->next = nullptr;
            temp->val = val;
            tail->next = temp;
            tail = temp;
        }
        list_length += 1;
    }
    
    void addAtIndex(int index, int val) {
        if (index > list_length) {
            return;
        }
        else if (index == 0) {
            addAtHead(val);
        }
        else if (index == list_length) {
            addAtTail(val);
        }
        else {
            DoublyListNode* curr = head;
            int access_counter = 0;
            while (access_counter != index) {
                access_counter += 1;
                curr = curr->next;
            }
            DoublyListNode* temp = new DoublyListNode;
            temp->prev = curr->prev;
            temp->next = curr;
            temp->val = val;
            if (curr->prev != nullptr) {
                curr->prev->next = temp;
            }
            curr->prev = temp;
            list_length += 1;
        }       
    }
    
    void deleteAtIndex(int index) {
        if (index >= list_length) {
            return;
        }
    
        DoublyListNode* curr = head;
        int access_counter = 0;
        while (access_counter != index) {
            access_counter += 1;
            curr = curr->next;
        }
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        }
        else {
            head = curr->next;
        }

        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }
        else {
            tail = curr->prev;
        }
        list_length -= 1;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */