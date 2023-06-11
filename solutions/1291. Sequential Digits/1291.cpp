class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;
    queue<int> q{{1, 2, 3, 4, 5, 6, 7, 8, 9}};

    while (!q.empty()) {
      const int num = q.front();
      q.pop();
      if (num > high)
        return ans;
      if (low <= num && num <= high)
        ans.push_back(num);
      const int lastDigit = num % 10;
      if (lastDigit < 9)
        q.push(num * 10 + lastDigit + 1);
    }

    return ans;
  }
};
