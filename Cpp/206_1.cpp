#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode* reverse(ListNode* ptr, ListNode* ptrLast){
    if(ptr->next==nullptr){
        ptr->next = ptrLast;
        return ptr;
    }
    ListNode* ptrNext = ptr->next;
    ptr->next = ptrLast;
    return reverse(ptrNext, ptr);
}

ListNode* reverseList(ListNode* head) {
    if(head==nullptr){
        return nullptr;
    }
    else{
        return reverse(head, nullptr);        
    }
}

/* 这种方法不需要处理head=nullptr的情况
ListNode* reverse(ListNode* ptr, ListNode* ptrLast){
    if(ptr==nullptr){
        return ptrLast;
    }
    ListNode* ptrNext = ptr->next;
    ptr->next = ptrLast;
    return reverse(ptrNext, ptr);
}

ListNode* reverseList(ListNode* head) {
    return reverse(head, nullptr);        
}
*/
int main(){
    int nums[]={1, 2, 3, 4, 5};
    int len = sizeof(nums)/sizeof(nums[0]);
    ListNode* dummyhead = new ListNode();
    ListNode* ptr = dummyhead;
    for(int i=0;i<len;i++){
        ptr->next = new ListNode(nums[i]);
        ptr = ptr->next;
    }

    ptr = reverseList(dummyhead->next);
    while(ptr!=nullptr){
        cout << ptr->val << endl;
        ptr = ptr->next;
    }
}