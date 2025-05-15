class Solution {
 public:
  bool phonePrefix(vector<string>& numbers) {
    ranges::sort(numbers);
    for (int i = 1; i < numbers.size(); ++i)
      if (numbers[i].starts_with(numbers[i - 1]))
        return false;
    return true;
  }
};
