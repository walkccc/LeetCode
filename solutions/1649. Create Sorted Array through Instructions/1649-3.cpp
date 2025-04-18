struct Item {
  int num;
  int index;
};

class Solution {
 public:
  int createSortedArray(vector<int>& instructions) {
    constexpr int kMod = 1'000'000'007;
    const int n = instructions.size();
    int ans = 0;
    vector<Item> items;
    // lesser[i] := the number of numbers < instructions[i]
    vector<int> lesser(n);
    // greater[i] := the number of numbers > instructions[i]
    vector<int> greater(n);

    for (int i = 0; i < n; ++i)
      items.push_back({instructions[i], i});

    mergeSort(items, 0, n - 1, lesser, greater);

    for (int i = 0; i < n; ++i) {
      ans += min(lesser[i], greater[i]);
      ans %= kMod;
    }

    return ans;
  }

 private:
  void mergeSort(vector<Item>& items, int l, int r, vector<int>& lesser,
                 vector<int>& greater) {
    if (l >= r)
      return;

    const int m = (l + r) / 2;
    mergeSort(items, l, m, lesser, greater);
    mergeSort(items, m + 1, r, lesser, greater);
    merge(items, l, m, r, lesser, greater);
  }

  void merge(vector<Item>& items, int l, int m, int r, vector<int>& lesser,
             vector<int>& greater) {
    int lo = l;  // the first index s.t. items[lo].num >= items[i].num
    int hi = l;  // the first index s.t. items[hi].num > items[i].num

    for (int i = m + 1; i <= r; ++i) {
      while (lo <= m && items[lo].num < items[i].num)
        ++lo;
      while (hi <= m && items[hi].num <= items[i].num)
        ++hi;
      lesser[items[i].index] += lo - l;
      greater[items[i].index] += m - hi + 1;
    }

    vector<Item> sorted(r - l + 1);
    int k = 0;      // sorted's index
    int i = l;      // left's index
    int j = m + 1;  // right's index

    while (i <= m && j <= r)
      if (items[i].num < items[j].num)
        sorted[k++] = items[i++];
      else
        sorted[k++] = items[j++];

    // Put the possible remaining left part into the sorted array.
    while (i <= m)
      sorted[k++] = items[i++];

    // Put the possible remaining right part into the sorted array.
    while (j <= r)
      sorted[k++] = items[j++];

    copy(sorted.begin(), sorted.end(), items.begin() + l);
  }
};
