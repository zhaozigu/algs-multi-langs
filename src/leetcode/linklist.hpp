#pragma once
#include <vector>
/// Leetcode 单链表结构
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void InsertNextElem(ListNode *cur, int arg)
{
  if (cur == nullptr)
  {
    return;
  }

  ListNode *new_element = new ListNode(arg);

  if (cur->next == nullptr)
  {
    cur->next = new_element;
  }
  else
  {
    new_element->next = cur->next;
    cur->next = new_element;
  }
}

ListNode *PushBackList(ListNode *tail, const std::vector<int> &ins)
{
  ListNode *cur = tail;
  for (auto i : ins)
  {
    InsertNextElem(cur, i);
    cur = cur->next;
  }
  return tail;
}

std::vector<int> LinkToArray(ListNode *head)
{
  std::vector<int> res = {};
  for (auto cur = head; cur != nullptr; cur = cur->next)
  {
    res.emplace_back(cur->val);
  }

  return res;
}

void DestroyLinkList(ListNode *head)
{
  while (head->next != nullptr)
  {
    ListNode *next_elment = head->next;
    head->next = next_elment->next;

    delete next_elment;
  }
}
