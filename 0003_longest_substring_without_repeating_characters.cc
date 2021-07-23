class Solution
{
public:
  int lengthOfLongestSubstring (std::string s)
  {
    size_t max_length {};
    size_t length {};
    auto last_offsets {std::vector<size_t>(256, s.size())};
    size_t first_offset {};
    size_t offset {};
    while (offset != s.size())
    {
      auto &last_offset {last_offsets[s[offset]]};
      if (last_offset != s.size())
      {
        for (size_t i {first_offset}; i != last_offset; ++i)
        {
          last_offsets[s[i]] = s.size();
        }
        if (max_length < length)
        {
          max_length = length;
        }
        length -= (last_offset - first_offset);
        first_offset = last_offset + 1;
      }
      else
      {
        ++length;
      }
      last_offset = offset++;
    }
    if (max_length < length)
    {
      max_length = length;
    }
    return max_length;
  }
};
