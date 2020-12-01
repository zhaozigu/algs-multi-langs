#pragma once
#include <memory>
#include <vector>
/// Leetcode 单链表结构
struct ListNode
{
  int val;
  std::shared_ptr<ListNode> next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void InsertNextElem(ListNode *cur, int arg)
{
  cur->next = make_shared<ListNode>(arg);
}

ListNode *PushBackList(ListNode *tail, const vector<int> &ins)
{
  ListNode *cur = tail;
  for (auto i : ins)
  {
    InsertNextElem(cur, i);
    cur = &*cur->next;
  }
  return tail;
}

vector<int> LinkToArray(ListNode *head)
{
  std::vector<int> res = {};
  for (auto cur = head; cur != nullptr; cur = &*cur->next)
  {
    res.emplace_back(cur->val);
  }

  return res;
}
