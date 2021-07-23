class Solution {
public:
  std::vector<int> twoSum (std::vector<int> &nums, int target)
  {
    std::vector<int> index_pair(2);
    std::vector<std::pair<int, int>> value_to_index;
    for (size_t i {}; i != nums.size(); ++i)
    {
      value_to_index.push_back({nums[i], i});
    }
    std::sort
    (
      value_to_index.begin(),
      value_to_index.end(),
      [&] (auto const &left, auto const &right)
      {
        return (std::get<0>(left) < std::get<0>(right));
      }
    );
    size_t i {};
    size_t j {value_to_index.size() - 1};
    while (i != j)
    {
      auto sum {std::get<0>(value_to_index[i]) + std::get<0>(value_to_index[j])};
      if (sum == target)
      {
        index_pair[0] = std::get<1>(value_to_index[i]);
        index_pair[1] = std::get<1>(value_to_index[j]);
        break;
      }
      else if (sum < target)
      {
        ++i;
      }
      else
      {
        --j;
      }
    }
    return index_pair;
  }
};
