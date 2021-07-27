class Solution
{
public:
  int myAtoi (std::string s)
  {
    int integer {};
    auto it {s.begin()};
    for (; (it != s.end()) && (*it == ' '); ++it);
    if ((it != s.end()) && ((*it == '-') || (*it == '+') || std::isdigit(*it)))
    {
      bool sign {*it == '-'};
      if (std::isdigit(*it))
      {
        integer = (*it - '0');
      }
      for (++it; (it != s.end()) && std::isdigit(*it); ++it)
      {
        if (integer < 214748364)
        {
          integer = (integer * 10) + (*it - '0');
        }
        else if (integer == 214748364)
        {
          if (*it <= '7')
          {
            integer = (integer * 10) + (*it - '0');
          }
          else if (sign && (*it == '8'))
          {
            return std::numeric_limits<int>::min();
          }
          else
          {
            return ((sign) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max());
          }
        }
        else
        {
          return ((sign) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max());
        }
      }
      return ((sign) ? -integer : integer);
    }
    return 0;
  }
};
