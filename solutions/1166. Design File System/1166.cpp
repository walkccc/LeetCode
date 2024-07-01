struct TrieNode {
  unordered_map<string, shared_ptr<TrieNode>> children;
  int value;
  TrieNode(int value) : value(value) {}
};

class FileSystem {
 public:
  bool createPath(string path, int value) {
    const vector<string> subpaths = getSubpaths(path);
    shared_ptr<TrieNode> node = root;

    for (int i = 0; i < subpaths.size() - 1; ++i) {
      auto it = node->children.find(subpaths[i]);
      if (it == node->children.end())
        return false;
      node = it->second;
    }

    if (node->children.count(subpaths.back()))
      return false;
    node->children[subpaths.back()] = make_shared<TrieNode>(value);
    return true;
  }

  int get(string path) {
    const vector<string> subpaths = getSubpaths(path);
    shared_ptr<TrieNode> node = root;

    for (const string& subpath : getSubpaths(path)) {
      auto it = node->children.find(subpath);
      if (it == node->children.end())
        return -1;
      node = it->second;
    }

    return node->value;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>(0);

  vector<string> getSubpaths(const string& path) {
    vector<string> subpaths;
    istringstream iss(path);
    for (string subpath; getline(iss, subpath, '/');)
      if (!subpath.empty())
        subpaths.push_back(subpath);
    return subpaths;
  }
};
