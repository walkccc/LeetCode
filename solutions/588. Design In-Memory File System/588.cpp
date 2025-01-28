struct TrieNode {
  map<string, shared_ptr<TrieNode>> children;  // lexicographical
  bool isFile = false;
  string content;
};

class FileSystem {
 public:
  vector<string> ls(string path) {
    auto [node, lastDir] = createDirAndGetPair(path);
    if (node->isFile)
      return {lastDir};

    vector<string> ans;

    for (const auto& [file, _] : node->children)
      ans.push_back(file);

    return ans;
  }

  void mkdir(string path) {
    createDirAndGetPair(path);
  }

  void addContentToFile(string filePath, string content) {
    shared_ptr<TrieNode> node = createDirAndGetPair(filePath).first;
    node->isFile = true;
    node->content += content;
  }

  string readContentFromFile(string filePath) {
    shared_ptr<TrieNode> node = createDirAndGetPair(filePath).first;
    return node->content;
  }

 private:
  shared_ptr<TrieNode> root = make_shared<TrieNode>();

  // e.g. createDirAndGetPair("/a//b") -> {TrieNode b, string "b"}
  pair<shared_ptr<TrieNode>, string> createDirAndGetPair(const string& path) {
    const vector<string> dirs = getDirs(path);
    shared_ptr<TrieNode> node = root;

    for (const string& dir : dirs) {
      if (!node->children.contains(dir))
        node->children[dir] = make_shared<TrieNode>();
      node = node->children[dir];
    }

    return {node, dirs.empty() ? "" : dirs.back()};
  }

  // e.g. getDirs("/a//b") -> ["a", "b"]
  vector<string> getDirs(const string& path) {
    vector<string> dirs;
    istringstream iss(path);

    for (string dir; getline(iss, dir, '/');)
      if (!dir.empty())  // Make sure that "/a//b" == "/a/b".
        dirs.push_back(dir);

    return dirs;
  }
};
