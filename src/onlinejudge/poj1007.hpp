#pragma once
#include <string>
#include <algorithm>

class Solve
{
public:
  // 返回逆序数
  int Stat(std::string s)
  {
    int count = 0;
    int len = s.length();
    // 冒泡排序
    for (int i = 0; i < len - 1; i++)
    {
      for (int j = 0; j < len - 1 - i; j++)
      {
        if (s[j] > s[j + 1])
        {
          std::swap(s[j], s[j + 1]);
          ++count;
        }
      }
    }
    return count;
  }
};
