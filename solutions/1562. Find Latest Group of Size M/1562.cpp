class Solution {
 public:
  int findLatestStep(vector<int>& arr, int m) {
    if (arr.size() == m)
      return arr.size();

    int ans = -1;
    int step = 0;
    // sizes[i] := the size of the group starting from i or ending in i
    // (1-indexed)
    vector<int> sizes(arr.size() + 2);

    for (const int i : arr) {
      ++step;
      // In the previous step, there exists a group with a size of m.
      if (sizes[i - 1] == m || sizes[i + 1] == m)
        ans = step - 1;
      const int head = i - sizes[i - 1];
      const int tail = i + sizes[i + 1];
      sizes[head] = tail - head + 1;
      sizes[tail] = tail - head + 1;
    }

    return ans;
  }
};
