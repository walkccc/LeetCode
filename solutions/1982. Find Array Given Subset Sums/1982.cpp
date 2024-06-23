class Solution {
 public:
  vector<int> recoverArray(int n, vector<int>& sums) {
    ranges::sort(sums);
    return recover(sums);
  }

 private:
  vector<int> recover(const vector<int>& sums) {
    if (sums.size() == 1)  // sums[0] must be 0.
      return {};

    // Either num or -num must be in the final array.
    //  num + sumsExcludingNum = sumsIncludingNum
    // -num + sumsIncludingNum = sumsExcludingNum
    unordered_map<int, int> count;
    for (const int sum : sums)
      ++count[sum];

    const int num = sums[1] - sums[0];
    vector<int> sumsExcludingNum;
    vector<int> sumsIncludingNum;
    bool chooseSumsIncludingNum = false;

    for (const int sum : sums) {
      if (count[sum] == 0)
        continue;
      --count[sum];
      --count[sum + num];
      sumsExcludingNum.push_back(sum);
      sumsIncludingNum.push_back(sum + num);
      if (sum + num == 0)
        chooseSumsIncludingNum = true;
    }

    // Choose `sumsExludingNum` by default since we want to gradually strip
    // `num` from each sum in `sums` to have the final array. However, we should
    // always choose the group of sums with 0 since it's a must-have.
    vector<int> recovered =
        recover(chooseSumsIncludingNum ? sumsIncludingNum : sumsExcludingNum);
    recovered.push_back(chooseSumsIncludingNum ? -num : num);
    return recovered;
  }
};
