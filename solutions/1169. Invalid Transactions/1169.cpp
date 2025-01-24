struct Transaction {
  string name;
  int time;
  int amount;
  string city;
};

class Solution {
 public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    vector<string> ans;
    unordered_map<string, vector<Transaction>> nameToTransactions;

    for (const string& t : transactions) {
      const Transaction transaction = getTransaction(t);
      nameToTransactions[transaction.name].push_back(transaction);
    }

    for (const string& t : transactions) {
      const Transaction currTransaction = getTransaction(t);
      if (currTransaction.amount > 1000) {
        ans.push_back(t);
      } else if (const auto it = nameToTransactions.find(currTransaction.name);
                 it != nameToTransactions.cend()) {
        // Iterate through all the transactions with the same name, check if
        // they're within 60 minutes in a different city.
        for (Transaction transaction : it->second)
          if (abs(transaction.time - currTransaction.time) <= 60 &&
              transaction.city != currTransaction.city) {
            ans.push_back(t);
            break;
          }
      }
    }

    return ans;
  }

 private:
  Transaction getTransaction(const string& t) {
    istringstream iss(t);
    vector<string> s(4, "");
    for (int i = 0; getline(iss, s[i++], ',');)
      ;
    return {s[0], stoi(s[1]), stoi(s[2]), s[3]};  // [name, time, amount, city]
  }
};
