#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {} 
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode *ptr = head;
    if(head->val == val){
        head = head->next;
    }
    while(ptr!=nullptr){
        if(ptr->next!=nullptr){
            if(ptr->next->val == val){
                ptr->next = ptr->next->next;
            }
        }
        ptr = ptr->next; 
    }
    return head;
}

int main(){
    int nums[] = {1, 3, 5, 7};
    int len = sizeof(nums)/sizeof(nums[0]);
    int val = 1;
    ListNode *head = nullptr;
    for(int i=len-1;i>=0;i--){
        head = new ListNode(nums[i], head);
    }
    ListNode *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->val << endl; //处理结点（显示结点内容）
        ptr = ptr->next; //移动到下一个结点
    }

    ptr = removeElements(head, val);
    while (ptr != nullptr)
    {
        cout << ptr->val << endl; //处理结点（显示结点内容）
        ptr = ptr->next; //移动到下一个结点
    }
}