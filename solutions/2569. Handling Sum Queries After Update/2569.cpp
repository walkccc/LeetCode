class LazySegmentTree {
 public:
  explicit LazySegmentTree(const vector<int>& nums) {
    const int n = nums.size();
    tree.resize(4 * n);
    lazy.resize(4 * n);
    build(nums, 0, 0, n - 1);
  }

  //            i := index of the current node
  // [start, end] := range of the current node
  //       [l, r] := range of the query
  void updateRange(int i, int start, int end, int l, int r) {
    if (lazy[i])
      propogate(i, start, end);
    if (start > r || end < l)
      return;
    if (start >= l && end <= r) {
      flip(i, start, end);
      return;
    }
    const int mid = (start + end) / 2;
    updateRange(i * 2 + 1, start, mid, l, r);
    updateRange(i * 2 + 2, mid + 1, end, l, r);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  }

  int getTreeSum() const {
    return tree[0];
  }

 private:
  vector<int> tree;
  vector<bool> lazy;

  void build(const vector<int>& nums, int i, int start, int end) {
    if (start == end) {
      tree[i] = nums[start];
      return;
    }
    const int mid = (start + end) / 2;
    build(nums, 2 * i + 1, start, mid);
    build(nums, 2 * i + 2, mid + 1, end);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  }

  void propogate(int i, int start, int end) {
    flip(i, start, end);
    lazy[i] = false;
  }

  void flip(int i, int start, int end) {
    tree[i] = (end - start + 1) - tree[i];  // Flip 0/1.
    if (start < end) {
      lazy[2 * i + 1] = !lazy[2 * i + 1];
      lazy[2 * i + 2] = !lazy[2 * i + 2];
    }
  }
};

class Solution {
 public:
  vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2,
                                vector<vector<int>>& queries) {
    vector<long long> ans;
    LazySegmentTree tree(nums1);
    long long sumNums2 = accumulate(nums2.begin(), nums2.end(), 0LL);

    for (const vector<int>& query : queries) {
      const int type = query[0];
      const int l = query[1];
      const int r = query[2];
      if (type == 1) {
        tree.updateRange(0, 0, nums1.size() - 1, l, r);
      } else if (type == 2) {
        sumNums2 += static_cast<long long>(l) * tree.getTreeSum();
      } else {  // type == 3
        ans.push_back(sumNums2);
      }
    }

    return ans;
  }
};
