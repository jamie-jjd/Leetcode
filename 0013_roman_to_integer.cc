class Solution
{
public:
  int romanToInt (std::string s)
  {
    int integer {};
    auto it {s.begin()};
    while (it != s.end() && *it == 'M')
    {
      integer += 1'000;
      ++it;
    }
    if (it != s.end() && *it == 'C' && std::next(it) != s.end() && *std::next(it) == 'M')
    {
      integer += 900;
      std::advance(it, 2);
    }
    if (it != s.end() && *it == 'D')
    {
      integer += 500;
      ++it;
    }
    if (it != s.end() && *it == 'C' && std::next(it) != s.end() && *std::next(it) == 'D')
    {
      integer += 400;
      std::advance(it, 2);
    }
    while (it != s.end() && *it == 'C')
    {
      integer += 100;
      ++it;
    }
    if (it != s.end() && *it == 'X' && std::next(it) != s.end() && *std::next(it) == 'C')
    {
      integer += 90;
      std::advance(it, 2);
    }
    if (it != s.end() && *it == 'L')
    {
      integer += 50;
      ++it;
    }
    if (it != s.end() && *it == 'X' && std::next(it) != s.end() && *std::next(it) == 'L')
    {
      integer += 40;
      std::advance(it, 2);
    }
    while (it != s.end() && *it == 'X')
    {
      integer += 10;
      ++it;
    }
    if (it != s.end() && *it == 'I' && std::next(it) != s.end() && *std::next(it) == 'X')
    {
      integer += 9;
      std::advance(it, 2);
    }
    if (it != s.end() && *it == 'V')
    {
      integer += 5;
      ++it;
    }
    if (it != s.end() && *it == 'I' && std::next(it) != s.end() && *std::next(it) == 'V')
    {
      integer += 4;
      std::advance(it, 2);
    }
    while (it != s.end() && *it == 'I')
    {
      ++integer;
      ++it;
    }
    return integer;
  }
};
