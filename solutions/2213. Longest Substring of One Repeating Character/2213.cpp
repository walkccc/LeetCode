struct SegmentTreeNode {
  int lo;
  int hi;
  char maxChar;
  char prefixChar;
  char suffixChar;
  int maxLength;
  int prefixLength;
  int suffixLength;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
  SegmentTreeNode(int lo, int hi, char maxChar, char prefixChar,
                  char suffixChar, int maxLength, int prefixLength,
                  int suffixLength, SegmentTreeNode* left = nullptr,
                  SegmentTreeNode* right = nullptr)
      : lo(lo),
        hi(hi),
        maxChar(maxChar),
        prefixChar(prefixChar),
        suffixChar(suffixChar),
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
  SegmentTree(const string& s) : root(build(s, 0, s.length() - 1)) {}
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
      root->maxChar = c;
      root->prefixChar = c;
      root->suffixChar = c;
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
    // get maxChar and maxLength
    char maxChar = ' ';
    int maxLength = 0;
    if (left->maxLength > right->maxLength) {
      maxChar = left->maxChar;
      maxLength = left->maxLength;
    } else {
      maxChar = right->maxChar;
      maxLength = right->maxLength;
    }
    if (left->suffixChar == right->prefixChar &&
        left->suffixLength + right->prefixLength > maxLength) {
      maxChar = left->suffixChar;
      maxLength = left->suffixLength + right->prefixLength;
    }

    // get prefixChar and prefixLength
    char prefixChar = left->prefixChar;
    int prefixLength = left->prefixLength;
    if (left->lo + prefixLength == right->lo &&
        left->prefixChar == right->prefixChar)
      prefixLength += right->prefixLength;

    // get suffixChar and suffixLength
    char suffixChar = right->suffixChar;
    int suffixLength = right->suffixLength;
    if (right->hi - suffixLength == left->hi &&
        right->suffixChar == left->suffixChar)
      suffixLength += left->suffixLength;

    return new SegmentTreeNode(left->lo, right->hi, maxChar, prefixChar,
                               suffixChar, maxLength, prefixLength,
                               suffixLength, left, right);
  }
};

class Solution {
 public:
  vector<int> longestRepeating(string s, string queryCharacters,
                               vector<int>& queryIndices) {
    vector<int> ans;
    SegmentTree tree(s);

    for (int i = 0; i < queryIndices.size(); ++i) {
      tree.update(queryIndices[i], queryCharacters[i]);
      ans.push_back(tree.getMaxLength());
    }

    return ans;
  }
};
