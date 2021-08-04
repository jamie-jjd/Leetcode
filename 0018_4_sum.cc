class Solution
{
public:
  std::vector<std::vector<int>> fourSum (vector<int> &nums, int target)
  {
    std::vector<std::vector<int>> four_sums;
    auto n {static_cast<int>(nums.size())};
    if (n > 3)
    {
      std::sort(nums.begin(), nums.end());
      int a {};
      auto prev_nums_a {nums[a] - 1};
      while (a != (n - 3))
      {
        while (a != (n - 3) && prev_nums_a == nums[a]) { ++a; }
        if (a != (n - 3))
        {
          prev_nums_a = nums[a];
          int b {a + 1};
          auto prev_nums_b {nums[b] - 1};
          while (b != (n - 2))
          {
            while (b != (n - 2) && prev_nums_b == nums[b]) { ++b; }
            if (b != (n - 2))
            {
              prev_nums_b = nums[b];
              auto new_target {target - nums[a] - nums[b]};
              int c {b + 1};
              int d {n - 1};
              while (c != d)
              {
                auto sum {nums[c] + nums[d]};
                if (sum == new_target)
                {
                  four_sums.push_back({nums[a], nums[b], nums[c], nums[d]});
                }
                if (sum <= new_target)
                {
                  auto prev_nums_c {nums[c]};
                  while (c != d && prev_nums_c == nums[c]) { ++c; }
                }
                else
                {
                  --d;
                }
              }
            }
          }
        }
      }
    }
    return four_sums;
  }
};
