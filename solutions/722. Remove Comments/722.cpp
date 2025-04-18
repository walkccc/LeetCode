class Solution {
 public:
  vector<string> removeComments(vector<string>& source) {
    vector<string> ans;
    bool commenting = false;
    string modified;

    for (const string& line : source) {
      for (int i = 0; i < line.length();) {
        if (i + 1 == line.length()) {
          if (!commenting)
            modified += line[i];
          ++i;
          break;
        }
        const string& twoChars = line.substr(i, 2);
        if (twoChars == "/*" && !commenting) {
          commenting = true;
          i += 2;
        } else if (twoChars == "*/" && commenting) {
          commenting = false;
          i += 2;
        } else if (twoChars == "//") {
          if (!commenting)
            break;
          else
            i += 2;
        } else {
          if (!commenting)
            modified += line[i];
          ++i;
        }
      }
      if (modified.length() > 0 && !commenting) {
        ans.push_back(modified);
        modified = "";
      }
    }

    return ans;
  }
};
