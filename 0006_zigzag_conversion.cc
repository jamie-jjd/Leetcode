class Solution
{
public:
  std::string convert (std::string s, int numRows)
  {
    if (numRows == 1)
    {
      return s;
    }
    auto n {static_cast<int>(s.size())};
    std::string zigzag_s {};
    auto step {(numRows - 1) * 2};
    for (int i {}; i < n; i += step)
    {
      zigzag_s.push_back(s[i]);
    }
    int other_step {};
    for (int i {1}; i < (numRows - 1); ++i)
    {
      step -= 2;
      other_step += 2;
      int bit {1};
      for (int j {i}; j < n; j += ((bit) ? step : other_step), bit ^= 1)
      {
        zigzag_s.push_back(s[j]);
      }
    }
    step = {(numRows - 1) * 2};
    for (int i {numRows - 1}; i < n; i += step)
    {
      zigzag_s.push_back(s[i]);
    }
    return zigzag_s;
  }
};
