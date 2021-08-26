class Solution
{
public:
  double findMedianSortedArrays (std::vector<int> &nums1, std::vector<int> &nums2)
  {
    if (nums1.empty() || nums2.empty())
    {
      auto &nums_nonempty {(nums2.empty()) ? nums1 : nums2};
      if (nums_nonempty.size() & 1)
      {
        return nums_nonempty[nums_nonempty.size() / 2];
      }
      else
      {
        auto offset {(nums_nonempty.size() / 2) - 1};
        return (nums_nonempty[offset] + nums_nonempty[offset + 1]) / 2.0;
      }
    }
    auto size_12 {nums1.size() + nums2.size()};
    auto middle_offset_12 {(size_12 - 1) / 2};
    auto &nums_shorter {(nums1.size() <= nums2.size()) ? nums1 : nums2};
    auto &nums_longer {(nums1.size() <= nums2.size()) ? nums2 : nums1};
    auto lower_offset_12
    {
      nums_shorter.size() +
      std::distance
      (
        nums_longer.begin(),
        std::lower_bound
        (
          nums_longer.begin(),
          nums_longer.end(),
          *nums_shorter.rbegin()
        )
      ) - 1
    };
    auto offset_longer {middle_offset_12 - nums_shorter.size()};
    if (lower_offset_12 < middle_offset_12)
    {
      if (size_12 & 1)
      {
        return nums_longer[offset_longer];
      }
      else
      {
        return (nums_longer[offset_longer] + nums_longer[offset_longer + 1]) / 2.0;
      }
    }
    else if (lower_offset_12 == middle_offset_12)
    {
      if (size_12 & 1)
      {
        return *nums_shorter.rbegin();
      }
      else
      {
        return (*nums_shorter.rbegin() + nums_longer[offset_longer + 1]) / 2.0;
      }
    }
    auto upper_offset_12
    {
      std::distance
      (
        nums_longer.begin(),
        std::upper_bound
        (
          nums_longer.begin(),
          nums_longer.end(),
          *nums_shorter.begin()
        )
      )
    };
    if (size_12 & 1)
    {
      if (middle_offset_12 < upper_offset_12)
      {
        return nums_longer[middle_offset_12];
      }
      else if (middle_offset_12 == upper_offset_12)
      {
        return *nums_shorter.begin();
      }
    }
    else
    {
      if (middle_offset_12 + 1 < upper_offset_12)
      {
        return (nums_longer[middle_offset_12] + nums_longer[middle_offset_12 + 1]) / 2.0;
      }
      else if (middle_offset_12 + 1 == upper_offset_12)
      {
        return (*nums_shorter.begin() + nums_longer[middle_offset_12]) / 2.0;
      }
    }
    int left {};
    auto right {nums_shorter.size() - 1};
    auto offset_shorter {(nums_shorter.size() - 1) / 2};
    offset_longer = (nums_longer.size() - 1) / 2;
    while (true)
    {
      if (nums_shorter[offset_shorter] <= nums_longer[offset_longer])
      {
        if ((offset_shorter + 1) == nums_shorter.size() || nums_longer[offset_longer] <= nums_shorter[offset_shorter + 1])
        {
          if (nums_shorter.size() & 1 && nums_longer.size() & 1)
          {
            if (offset_longer == 0 || nums_longer[offset_longer - 1] < nums_shorter[offset_shorter])
            {
              return (nums_shorter[offset_shorter] + nums_longer[offset_longer]) / 2.0;
            }
            else
            {
              return (nums_longer[offset_longer - 1] + nums_longer[offset_longer]) / 2.0;
            }
          }
          else if ((nums_shorter.size() & 1) ^ (nums_longer.size() & 1))
          {
            return nums_longer[offset_longer];
          }
          else
          {
            if ((offset_shorter + 1) == nums_shorter.size() || nums_longer[offset_longer + 1] <= nums_shorter[offset_shorter + 1])
            {
              return (nums_longer[offset_longer] + nums_longer[offset_longer + 1]) / 2.0;
            }
            else
            {
              return (nums_longer[offset_longer] + nums_shorter[offset_shorter + 1]) / 2.0;
            }
          }
        }
        else
        {
          left = offset_shorter + 1;
          offset_shorter = (left + right) / 2;
          offset_longer -= (offset_shorter - left + 1);
        }
      }
      else
      {
        if (nums_shorter[offset_shorter] <= nums_longer[offset_longer + 1])
        {
          if (nums_shorter.size() & 1 && nums_longer.size() & 1)
          {
            if (offset_shorter == 0 || nums_shorter[offset_shorter - 1] < nums_longer[offset_longer])
            {
              return (nums_shorter[offset_shorter] + nums_longer[offset_longer]) / 2.0;
            }
            else
            {
              return (nums_shorter[offset_shorter - 1] + nums_shorter[offset_shorter]) / 2.0;
            }
          }
          else if ((nums_shorter.size() & 1) ^ (nums_longer.size() & 1))
          {
            return nums_shorter[offset_shorter];
          }
          else
          {
            if ((offset_shorter + 1) == nums_shorter.size() || nums_longer[offset_longer + 1] <= nums_shorter[offset_shorter + 1])
            {
              return (nums_shorter[offset_shorter] + nums_longer[offset_longer + 1]) / 2.0;
            }
            else
            {
              return (nums_shorter[offset_shorter] + nums_shorter[offset_shorter + 1]) / 2.0;
            }
          }
        }
        else
        {
          right = offset_shorter - 1;
          offset_shorter = (left + right) / 2;
          offset_longer += (right - offset_shorter + 1);
        }
      }
    }
    return 0;
  }
};
