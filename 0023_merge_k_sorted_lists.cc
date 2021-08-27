/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode* mergeKLists (std::vector<ListNode*> &lists)
  {
    auto it {lists.begin()};
    while (it != lists.end() && !(*it))
    {
      ++it;
    }
    ListNode *list {};
    ListNode *last {};
    std::vector<int> vector;
    if (it != lists.end())
    {
      last = list = *it++;
      vector.push_back(last->val);
      while (last->next)
      {
        last = last->next;
        vector.push_back(last->val);
      }
    }
    while (it != lists.end())
    {
      if (*it)
      {
        last = last->next = *it;
        vector.push_back(last->val);
        while (last->next)
        {
          last = last->next;
          vector.push_back(last->val);
        }
      }
      ++it;
    }
    if (list)
    {
      std::sort(vector.begin(), vector.end());
      auto it {vector.begin()};
      last = list;
      while (last)
      {
        last->val = *it++;
        last = last->next;
      }
    }
    return list;
  }
};
