class Solution
{
public:
  std::vector<std::vector<int>> threeSum (std::vector<int> &nums)
  {
    std::vector<std::vector<int>> three_sums;
    auto n {static_cast<int>(nums.size())};
    if (n > 2)
    {
      std::sort(nums.begin(), nums.end());
      auto prev_nums_i {nums[0] - 1};
      int i {};
      while (i != (n - 2))
      {
        while (i != (n - 2) &&  prev_nums_i == nums[i]) { ++i; }
        if (i != n - 2)
        {
          auto target {-nums[i]};
          int j {i + 1};
          int k {n - 1};
          while (j != k)
          {
            auto sum {nums[j] + nums[k]};
            if (sum == target)
            {
              three_sums.push_back({nums[i], nums[j], nums[k]});
              auto prev_nums_j {nums[j]};
              while (j != k && prev_nums_j == nums[j]) { ++j; }
            }
            else if (sum < target)
            {
              ++j;
            }
            else
            {
              --k;
            }
          }
          prev_nums_i = nums[i];
        }
      }
    }
    return three_sums;
  }
};
