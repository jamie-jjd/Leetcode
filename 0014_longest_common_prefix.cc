class Solution
{
public:
  std::string longestCommonPrefix (std::vector<std::string> &strs)
  {
    if (strs.size() == 1)
    {
      return strs[0];
    }
    for (auto const &str : strs)
    {
      if (str.empty())
      {
        return "";
      }
    }
    size_t j {};
    while (j != strs[0].size())
    {
      auto c {strs[0][j]};
      for (size_t i {1}; i != strs.size(); ++i)
      {
        if (j == strs[i].size())
        {
          return strs[i];
        } else if (strs[i][j] != c)
        {
          return strs[0].substr(0, j);
        }
      }
      ++j;
    }
    return strs[0];
  }
};
