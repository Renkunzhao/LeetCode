#include<iostream>
using namespace std;

class MyLinkedList {
public:

    struct ListNode{
        int val;
        ListNode *next;
        ListNode(): val(0), next(nullptr) {}
        ListNode(int x): val(x), next(nullptr) {}
        ListNode(int x, ListNode* next): val(x), next(next) {}
    };

    MyLinkedList() {
        dummyHead_ = new ListNode();
        size_ = 0;        
    }
    
    int get(int index) {
        if(index>=0&&index<size_){
            ListNode *ptr = dummyHead_;
            for(int i=0;i<index+1;i++){
                ptr = ptr->next;
            }
            return ptr->val;
        }
        else{
            return -1;
        }
    }
    
    void addAtHead(int val) {
        dummyHead_->next = new ListNode(val, dummyHead_->next);
        size_++;
    }
    
    void addAtTail(int val) {
        ListNode *ptr = dummyHead_;
        for(int i=0;i<size_;i++){
            ptr = ptr->next;
        }
        ptr->next = new ListNode(val);
        size_++;
    }
    
    void addAtIndex(int index, int val) {
        if(index>=0&&index<size_){
            ListNode *ptr = dummyHead_;
            for(int i=0;i<index;i++){
                ptr = ptr->next;
            }
            ptr->next = new ListNode(val, ptr->next);
            size_++;
        }
        else if(index<0){
            addAtHead(val);
        }
        else if(index==size_){
            addAtTail(val);
        }
    }
    
    void deleteAtIndex(int index) {
        if(index>=0&&index<size_){
            ListNode *ptr = dummyHead_;
            for(int i=0;i<index;i++){
                ptr = ptr->next;
            }
            ptr->next = ptr->next->next;
            size_--;
        }
    }

private:
    ListNode *dummyHead_;
    int size_;
};

int main(){
    MyLinkedList* obj = new MyLinkedList();
    obj->addAtHead(1);
    obj->addAtTail(3);
    obj->addAtIndex(1,2);
    cout << obj->get(1) << endl;
    obj->deleteAtIndex(1);
    cout << obj->get(1) << endl;
}