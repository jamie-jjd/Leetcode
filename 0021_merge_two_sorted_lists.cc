/*
* Definition for singly-linked list.
* struct ListNode
* {
*   int val;
*   ListNode *next;
*   ListNode() : val(0), next(nullptr) {}
*   ListNode(int x) : val(x), next(nullptr) {}
*   ListNode(int x, ListNode *next) : val(x), next(next) {}
* };
*/
class Solution
{
public:
  ListNode* mergeTwoLists (ListNode *l1, ListNode *l2)
  {
    if (l1 == nullptr)
    {
      return l2;
    }
    if (l2 == nullptr)
    {
      return l1;
    }
    ListNode node;
    ListNode *l {&node};
    while (l1 && l2)
    {
      if (l1->val < l2->val)
      {
        l = l->next = l1;
        l1 = l1->next;
      }
      else
      {
        l = l->next = l2;
        l2 = l2->next;
      }
    }
    while (l1)
    {
      l = l->next = l1;
      l1 = l1->next;
    }
    while (l2)
    {
      l = l->next = l2;
      l2 = l2->next;
    }
    return node.next;
  }
};
