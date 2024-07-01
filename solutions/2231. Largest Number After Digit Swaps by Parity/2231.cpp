class Solution {
 public:
  int largestInteger(int num) {
    const string s = to_string(num);
    int ans = 0;
    // maxHeap[0] := the odd digits
    // maxHeap[1] := the even digits
    vector<priority_queue<int>> maxHeap(2);

    for (const char c : s) {
      const int digit = c - '0';
      maxHeap[digit & 1].push(digit);
    }

    for (const char c : s) {
      const int i = c - '0' & 1;
      ans *= 10;
      ans += maxHeap[i].top(), maxHeap[i].pop();
    }

    return ans;
  }
};
