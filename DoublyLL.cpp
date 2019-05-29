#include <iostream>

class MyLinkedList {
    
private:
    struct ListNode{
        int val;
        ListNode *next;
        ListNode *prev;
    };    
    
    int size;
    ListNode *head;
    ListNode *tail;
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->size = 0;
        head = NULL;
        tail = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if(index < 0 || index >= size)return -1;
        
        ListNode *curr = head;
        for(int i = 0; i < index; ++i)
        {
            curr = curr->next;
        }
        
        return curr->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        ListNode *newNode = new ListNode();
        newNode->val = val;
        newNode->next = head;
        newNode->prev = NULL;
        
        // ListNode* curr = head;
        if(head)
            head->prev = newNode;
        
        head = newNode;
        size++;
        
        if(size == 1)tail = head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        ListNode *newNode = new ListNode();
        newNode->val = val;
        newNode->next = NULL;
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        if(index < 0 || index > size)return;
        
        if(index == 0)
        {
            addAtHead(val);
        }
        
        else if(index == size)
        {
            addAtTail(val);
        }
        
        else
        {
            ListNode *newNode = new ListNode();
            newNode->val = val;
            newNode->prev = NULL;
            newNode->next = NULL;
            
            ListNode* curr = head;
            ListNode* pre = NULL;
            for(int i = 0; i < index; ++i)
            {
                pre = curr;
                curr = curr->next;
            }
            
            newNode->next = curr;
            pre->next = newNode;
            newNode->prev = pre;
            curr->prev = newNode;
            
            size++;
        }
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if(index < 0 || index >= size)return;
        if(index == 0)
        {
            head = head->next;
            head->prev = NULL;
            size--;
        }
        
        else if(index == size-1)
        {
            tail = tail->prev;
            tail->next = NULL;
            size--;
        }
        else
        {
            ListNode* curr = head;
            ListNode* pre = NULL;
            
            for(int i = 0; i < index; ++i)
            {
                pre = curr;
                curr = curr->next;
            }
            
            curr = curr->next;
            pre->next = curr;
            
            curr->prev = pre;
            size--;
        }
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */