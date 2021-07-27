class Solution
{
public:
  bool isPalindrome (int x)
  {
    if (x >= 0)
    {
      int temp_x {x};
      int amount_digits {};
      while (temp_x)
      {
        ++amount_digits;
        temp_x /= 10;
      }
      int reverse_x {};
      int length {amount_digits / 2};
      while (length--)
      {
        reverse_x = (reverse_x * 10) + (x % 10);
        x /= 10;
      }
      if (amount_digits & 1)
      {
        x /= 10;
      }
      return (x == reverse_x);
    }
    return false;
  }
};
