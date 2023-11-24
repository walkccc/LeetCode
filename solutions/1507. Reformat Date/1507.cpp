class Solution {
 public:
  string reformatDate(string date) {
    const unordered_map<string, string> monthToNumString{
        {"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"},
        {"May", "05"}, {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"},
        {"Sep", "09"}, {"Oct", "10"}, {"Nov", "11"}, {"Dec", "12"},
    };
    const int index1 = date.find_first_of(' ');
    const int index2 = date.find_first_of(' ', index1 + 1);
    const string day = index1 == 4 ? date.substr(0, 2) : string("0") + date[0];
    const string month =
        monthToNumString.at(date.substr(index1 + 1, index2 - (index1 + 1)));
    const string year = date.substr(index2 + 1);
    return year + "-" + month + "-" + day;
  }
};
