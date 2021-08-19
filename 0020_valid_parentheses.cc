class Solution
{
public:
  bool isValid (std::string s)
  {
    std::deque<char> stack;
    for (auto const c : s)
    {
      if (c == '(' || c == '{' || c == '[')
      {
        stack.push_back(c);
      }
      else if (c == ')')
      {
        if (stack.empty() || stack.back() != '(')
        {
          return false;
        }
        stack.pop_back();
      }
      else if (c == '}')
      {
        if (stack.empty() || stack.back() != '{')
        {
          return false;
        }
        stack.pop_back();
      }
      else
      {
        if (stack.empty() || stack.back() != '[')
        {
          return false;
        }
        stack.pop_back();
      }
    }
    return stack.empty();
  }
};
