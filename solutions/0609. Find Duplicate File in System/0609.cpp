class Solution {
 public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> contentToFilePaths;

    for (const string& path : paths) {
      istringstream iss(path);
      string rootPath;
      iss >> rootPath;  // "root/d1/d2/.../dm"

      string fileAndContent;
      while (iss >> fileAndContent) {  // "fn.txt(fn_content)"
        const int l = fileAndContent.find('(');
        const int r = fileAndContent.find(')');
        // "fn.txt"
        const string file = fileAndContent.substr(0, l);
        // "fn_content"
        const string content = fileAndContent.substr(l + 1, r - l - 1);
        // "root/d1/d2/.../dm/fn.txt"
        const string filePath = rootPath + '/' + file;
        contentToFilePaths[content].push_back(filePath);
      }
    }

    for (const auto& [_, filePaths] : contentToFilePaths)
      if (filePaths.size() > 1)
        ans.push_back(filePaths);

    return ans;
  }
};
