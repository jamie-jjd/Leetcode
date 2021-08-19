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
  ListNode* removeNthFromEnd (ListNode *begin, int n)
  {
    ListNode *prev {};
    ListNode *next {};
    ListNode *node {begin};
    while (node)
    {
      next = node->next;
      node->next = prev;
      prev = node;
      node = next;
    }
    {
      node = prev;
      while (node)
      {
        prev = node->next;
        node->next = next;
        next = node;
        node = prev;
        if (n-- == 1)
        {
          auto temp {next};
          next = next->next;
          delete temp;
        }
      }
    }
    return next;
  }
};
