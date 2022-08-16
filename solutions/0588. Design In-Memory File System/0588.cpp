struct TrieNode {
  map<string, TrieNode*> children;  // map: lexicographical
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
    TrieNode* node = createDirAndGetPair(filePath).first;
    node->isFile = true;
    node->content += content;
  }

  string readContentFromFile(string filePath) {
    TrieNode* node = createDirAndGetPair(filePath).first;
    return node->content;
  }

 private:
  TrieNode root;

  // createDirAndGetPair("/a//b") -> {TrieNode b, string "b"}
  pair<TrieNode*, string> createDirAndGetPair(const string& path) {
    const vector<string> dirs = getDirs(path);
    TrieNode* node = &root;

    for (const string& dir : dirs) {
      if (!node->children.count(dir))
        node->children[dir] = new TrieNode;
      node = node->children[dir];
    }

    return {node, dirs.empty() ? "" : dirs.back()};
  }

  // getDirs("/a//b") -> ["a", "b"]
  vector<string> getDirs(const string& path) {
    vector<string> dirs;
    istringstream iss(path);

    for (string dir; getline(iss, dir, '/');)
      if (!dir.empty())  // "/a//b" == "/a/b"
        dirs.push_back(dir);

    return dirs;
  }
};
