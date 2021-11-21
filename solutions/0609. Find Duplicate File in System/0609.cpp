class Solution {
 public:
  vector<vector<string>> findDuplicate(vector<string>& paths) {
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> files;  // {content: {path}}

    for (const string& path : paths) {
      istringstream iss(path);
      string rootPath;
      iss >> rootPath;  // "root/d1/d2..."

      string fileContent;
      while (iss >> fileContent) {  // "fn.txt(fn_content)"
        const int l = fileContent.find('(');
        const int r = fileContent.find(')');
        // "fn.txt"
        const string file = fileContent.substr(0, l);
        // "root/d1/d2/.../fn.txt"
        const string filePath = rootPath + '/' + file;
        // "fn_content"
        const string content = fileContent.substr(l + 1, r - l - 1);
        files[content].push_back(filePath);
      }
    }

    for (const auto& [_, filePath] : files)
      if (filePath.size() > 1)
        ans.push_back(filePath);

    return ans;
  }
};
