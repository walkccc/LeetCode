class Solution {
 public:
  vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
    deque<int> ans;
    int carry = 0;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;

    while (carry || i >= 0 || j >= 0) {
      if (i >= 0)
        carry += arr1[i--];
      if (j >= 0)
        carry += arr2[j--];
      ans.push_front(carry & 1);
      carry = -(carry >> 1);
    }

    while (ans.size() > 1 && ans.front() == 0)
      ans.pop_front();

    return {ans.begin(), ans.end()};
  }
};
