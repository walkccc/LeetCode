struct SegmentTreeNode {
  int lo;
  int hi;
  char maxLetter;
  char prefixLetter;
  char suffixLetter;
  int maxLength;
  int prefixLength;
  int suffixLength;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
  SegmentTreeNode(int lo, int hi, char maxLetter, char prefixLetter,
                  char suffixLetter, int maxLength, int prefixLength,
                  int suffixLength, SegmentTreeNode* left = nullptr,
                  SegmentTreeNode* right = nullptr)
      : lo(lo),
        hi(hi),
        maxLetter(maxLetter),
        prefixLetter(prefixLetter),
        suffixLetter(suffixLetter),
        maxLength(maxLength),
        prefixLength(prefixLength),
        suffixLength(suffixLength),
        left(left),
        right(right) {}
  ~SegmentTreeNode() {
    delete left;
    delete right;
    left = nullptr;
    right = nullptr;
  }
};

class SegmentTree {
 public:
  explicit SegmentTree(const string& s) : root(build(s, 0, s.length() - 1)) {}
  ~SegmentTree() {
    delete root;
  }

  void update(int i, char val) {
    root = update(root, i, val);
  }

  int getMaxLength() {
    return root->maxLength;
  }

 private:
  SegmentTreeNode* root;

  SegmentTreeNode* build(const string& s, int lo, int hi) const {
    if (lo == hi)
      return new SegmentTreeNode(lo, hi, s[lo], s[lo], s[lo], 1, 1, 1);
    const int mid = (lo + hi) / 2;
    SegmentTreeNode* left = build(s, lo, mid);
    SegmentTreeNode* right = build(s, mid + 1, hi);
    return merge(left, right);
  }

  SegmentTreeNode* update(SegmentTreeNode* root, int i, char c) {
    if (root->lo == i && root->hi == i) {
      root->maxLetter = c;
      root->prefixLetter = c;
      root->suffixLetter = c;
      return root;
    }
    const int mid = (root->lo + root->hi) / 2;
    if (i <= mid) {
      SegmentTreeNode* updatedLeft = update(root->left, i, c);
      return root = merge(updatedLeft, root->right);
    } else {
      SegmentTreeNode* updatedRight = update(root->right, i, c);
      return root = merge(root->left, updatedRight);
    }
  }

  SegmentTreeNode* merge(SegmentTreeNode* left, SegmentTreeNode* right) const {
    // Get the `maxLetter` and the `maxLength`.
    char maxLetter = ' ';
    int maxLength = 0;
    if (left->maxLength > right->maxLength) {
      maxLetter = left->maxLetter;
      maxLength = left->maxLength;
    } else {
      maxLetter = right->maxLetter;
      maxLength = right->maxLength;
    }
    if (left->suffixLetter == right->prefixLetter &&
        left->suffixLength + right->prefixLength > maxLength) {
      maxLetter = left->suffixLetter;
      maxLength = left->suffixLength + right->prefixLength;
    }

    // Get the `prefixLetter` and the `prefixLength`.
    char prefixLetter = left->prefixLetter;
    int prefixLength = left->prefixLength;
    if (left->lo + prefixLength == right->lo &&
        left->prefixLetter == right->prefixLetter)
      prefixLength += right->prefixLength;

    // Get the `suffixLetter` and the `suffixLength`.
    char suffixLetter = right->suffixLetter;
    int suffixLength = right->suffixLength;
    if (right->hi - suffixLength == left->hi &&
        right->suffixLetter == left->suffixLetter)
      suffixLength += left->suffixLength;
    return new SegmentTreeNode(left->lo, right->hi, maxLetter, prefixLetter,
                               suffixLetter, maxLength, prefixLength,
                               suffixLength, left, right);
  }
};

class Solution {
 public:
  vector<int> longestRepeating(string s, string queryLetteracters,
                               vector<int>& queryIndices) {
    vector<int> ans;
    SegmentTree tree(s);

    for (int i = 0; i < queryIndices.size(); ++i) {
      tree.update(queryIndices[i], queryLetteracters[i]);
      ans.push_back(tree.getMaxLength());
    }

    return ans;
  }
};
