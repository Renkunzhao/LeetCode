#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};


/*
    遍历链表的时候需要注意：
    1）删除元素不能通过修改ptr，而要修改ptr->next，所以要检查的是ptr->next->val，因为如果ptr->val是满足条件的值，已经无法被删掉了
    2）总结：被ptr指到的元素无法删除
*/
ListNode* removeElements(ListNode* head, int val) {
    ListNode *dummyhead = new ListNode(0, head);
    ListNode *ptr = dummyhead;
    while (ptr->next!=nullptr)
    {
        if (ptr->next->val == val)
        {
            ListNode *tmp = ptr->next;
            ptr->next = ptr->next->next;
            delete tmp;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    return dummyhead->next;
}

int main(){
    int nums[] = {7, 7, 7, 7};
    int len = sizeof(nums)/sizeof(nums[0]);
    int val = 7;
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