class Solution
{
public:
  int reverse (int x)
  {
    int reversed_x {};
    if (x == (1 << 31))
    {
      return 0;
    }
    int sign {-1 * ((x < 0) ? 1 : -1)};
    x *= sign;
    while (x > 9)
    {
      reversed_x = (reversed_x * 10) + (x % 10);
      x /= 10;
    }
    if ((reversed_x >= 0) && ((reversed_x < 214748364) || ((reversed_x <= 214748364) && (x <= 7))))
    {
      reversed_x = (reversed_x * 10) + x;
    }
    else
    {
      reversed_x = 0;
    }
    return (sign * reversed_x);
  }
};
