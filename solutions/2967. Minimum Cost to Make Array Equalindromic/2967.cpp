class Solution {
 public:
  long long minimumCost(vector<int>& nums) {
    ranges::sort(nums);
    const int median = nums[nums.size() / 2];
    const int nextPalindrome = getPalindrome(median, /*delta=*/1);
    const int prevPalindrome = getPalindrome(median, /*delta=*/-1);
    return min(cost(nums, nextPalindrome), cost(nums, prevPalindrome));
  }

 private:
  // Returns the cost to change all the numbers to `palindrome`.
  long cost(const vector<int>& nums, int palindrome) {
    return accumulate(nums.begin(), nums.end(), 0L,
                      [palindrome](long subtotal, int num) {
      return subtotal + abs(palindrome - num);
    });
  }

  // Returns the palindrome `p`, where p = num + a * delta and a > 0.
  int getPalindrome(int num, int delta) {
    while (!isPalindrome(num))
      num += delta;
    return num;
  }

  bool isPalindrome(int num) {
    const string original = to_string(num);
    const string reversed = {original.rbegin(), original.rend()};
    return original == reversed;
  }
};
