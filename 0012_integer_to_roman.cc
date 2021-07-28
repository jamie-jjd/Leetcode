class Solution
{
public:
  std::string intToRoman (int num)
  {
    std::string roman {};
    while (num >= 1'000)
    {
      roman.push_back('M');
      num -= 1'000;
    }
    if (num >= 900)
    {
      roman.push_back('C');
      roman.push_back('M');
      num -= 900;
    }
    if (num >= 500)
    {
      roman.push_back('D');
      num -= 500;
    }
    if (num >= 400)
    {
      roman.push_back('C');
      roman.push_back('D');
      num -= 400;
    }
    while (num >= 100)
    {
      roman.push_back('C');
      num -= 100;
    }
    if (num >= 90)
    {
      roman.push_back('X');
      roman.push_back('C');
      num -= 90;
    }
    if (num >= 50)
    {
      roman.push_back('L');
      num -= 50;
    }
    if (num >= 40)
    {
      roman.push_back('X');
      roman.push_back('L');
      num -= 40;
    }
    while (num >= 10)
    {
      roman.push_back('X');
      num -= 10;
    }
    if (num >= 9)
    {
      roman.push_back('I');
      roman.push_back('X');
      num -= 9;
    }
    if (num >= 5)
    {
      roman.push_back('V');
      num -= 5;
    }
    if (num >= 4)
    {
      roman.push_back('I');
      roman.push_back('V');
      num -= 4;
    }
    while (num)
    {
      roman.push_back('I');
      --num;
    }
    return roman;
  }
};
