class Solution
{
public:
  int threeSumClosest (vector<int> &nums, int target)
  {
    int min_diff {nums[0] + nums[1] + nums[2] - target};
    auto n {static_cast<int>(nums.size())};
    std::sort(nums.begin(), nums.end());
    auto prev_nums_i {nums[0] - 1};
    int i {};
    while (i != (n - 2))
    {
      while (i != (n - 2) &&  prev_nums_i == nums[i]) { ++i; }
      if (i != n - 2)
      {
        auto new_target {-nums[i] + target};
        int j {i + 1};
        int k {n - 1};
        while (j != k)
        {
          auto sum {nums[j] + nums[k]};
          auto diff {nums[i] + sum - target};
          if (std::abs(diff) < std::abs(min_diff))
          {
            min_diff = diff;
          }
          if (sum == new_target)
          {
            return target;
          }
          else if (sum < new_target)
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
    return (target + min_diff);
  }
};
