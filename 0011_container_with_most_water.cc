class Solution
{
public:
  int maxArea (std::vector<int> &height)
  {
    int max_area {};
    int area {};
    auto length {height.size() - 1};
    auto it {height.begin()};
    auto rit {std::prev(height.end())};
    while (it != rit)
    {
      if (*it < *rit)
      {
        area = *it++ * length;
      }
      else
      {
        area = *rit-- * length;
      }
      if (max_area < area)
      {
        max_area = area;
      }
      --length;
    }
    return max_area;
  }
};
