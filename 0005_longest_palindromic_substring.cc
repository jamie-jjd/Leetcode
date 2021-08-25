class Solution
{
public:
  std::string longestPalindrome (std::string s)
  {
    int n {static_cast<int>(s.size())};
    int i {};
    int j {};
    int k {};
    int longest_j {};
    int longest_k {};
    while (i != n)
    {
      j = i;
      k = i + 1;
      while (j != -1 && k != n && s[j] == s[k])
      {
        --j;
        ++k;
      }
      ++j;
      --k;
      if ((longest_k - longest_j) < (k - j))
      {
        longest_j = j;
        longest_k = k;
      }
      j = i - 1;
      k = i + 1;
      while (j != -1 && k != n && s[j] == s[k])
      {
        --j;
        ++k;
      }
      ++j;
      --k;
      if ((longest_k - longest_j) < (k - j))
      {
        longest_j = j;
        longest_k = k;
      }
      ++i;
    }
    return s.substr(longest_j, longest_k - longest_j + 1);
  }
};
