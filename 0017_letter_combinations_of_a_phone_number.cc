class Solution
{
public:

  std::vector<std::string> letterCombinations (std::string digits)
  {
    std::vector<std::string> letter_combinations;
    if (!digits.empty())
    {
      std::string combination {};
      LettetCombinations(digits, combination, letter_combinations, 0);      
    }
    return letter_combinations;
  }

private:

  void LettetCombinations
  (
    std::string const &digits,
    std::string &combination,
    std::vector<std::string> &letter_combinations,
    size_t offset
  )
  {
    if (offset == digits.size())
    {
      letter_combinations.push_back(combination);
    }
    else
    {
      char begin_letter {};
      char end_letter {};
      if (digits[offset] < '7')
      {
        begin_letter = 'a' + (digits[offset] - '2') * 3;
        end_letter = begin_letter + 3;
      }
      else if (digits[offset] == '7')
      {
        begin_letter = 'p';
        end_letter = 'p' + 4;
      }
      else if (digits[offset] == '8')
      {
        begin_letter = 't';
        end_letter = 't' + 3;
      }
      else
      {
        begin_letter = 'w';
        end_letter = 'w' + 4;
      }
      for (auto letter {begin_letter}; letter != end_letter; ++letter)
      {
        combination.push_back(letter);
        LettetCombinations(digits, combination, letter_combinations, offset + 1);
        combination.pop_back();
      }
    }
    return;
  }

};
