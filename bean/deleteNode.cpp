#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode *deleteNode(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    ListNode *pNext = head;
    ListNode *pCur = head;
    while (pNext != nullptr)
    {
        pNext = pCur->next;
        while (pNext != nullptr && pNext->val == pCur->val)
        {
            pNext = pNext->next;
        }
        if (pNext == nullptr)
        {
            return head;
        }
        pCur->next = pNext;
        pCur=pCur->next;
    }

    return head;
}

int main()
{
    ListNode node1(1), node2(1), node3(2), node4(3);
    ListNode *head;
    head = &node1;
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    //while (head != nullptr)
    //{
    // cout << head->val << " ";
    // head = head->next;
    //}
    head = deleteNode(head);
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}