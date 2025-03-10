class Solution {
 public:
  vector<int> rearrangeBarcodes(vector<int>& barcodes) {
    vector<int> ans(barcodes.size());
    vector<int> count(10001);
    int i = 0;  // ans' index

    for (const int b : barcodes)
      ++count[b];

    const auto maxIt = ranges::max_element(count);
    const int maxNum = maxIt - count.begin();

    auto fillAns = [&](int num) {
      while (count[num]-- > 0) {
        ans[i] = num;
        i = i + 2 < barcodes.size() ? i + 2 : 1;
      }
    };

    fillAns(maxNum);
    for (int num = 1; num < 10001; ++num)
      fillAns(num);

    return ans;
  }
};
