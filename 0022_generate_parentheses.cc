class Solution
{
public:
  std::vector<std::string> generateParenthesis (int n)
  {
    std::vector<std::vector<std::string>> parentheses(n + 1);
    parentheses[0].push_back("");
    parentheses[1].push_back("()");
    GenerateParentheses(parentheses, n);
    return parentheses[n];
  }
private:
  void GenerateParentheses(std::vector<std::vector<std::string>> &parentheses, int n)
  {
    if (n > 1)
    {
      GenerateParentheses(parentheses, n - 1);
      for (int i {}; i < n; ++i)
      {
        for (auto const &left_parentheses : parentheses[i])
        {
          for (auto const &right_parentheses : parentheses[n - 1 - i])
          {
            parentheses[n].push_back(left_parentheses + "(" + right_parentheses + ")");
          }
        }
      }
    }
    return;
  }
};
