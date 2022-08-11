class MovieRentingSystem {
 public:
  MovieRentingSystem(int n, vector<vector<int>>& entries) {
    for (const auto& e : entries) {
      const int shop = e[0];
      const int movie = e[1];
      const int price = e[2];
      unrented[movie].insert({price, shop});
      shopAndMovieToPrice[{shop, movie}] = price;
    }
  }

  vector<int> search(int movie) {
    vector<int> ans;
    int i = 0;

    for (const auto& priceAndShops : unrented[movie]) {
      ans.push_back(priceAndShops.second);
      if (++i >= 5)
        break;
    }

    return ans;
  }

  void rent(int shop, int movie) {
    const int price = shopAndMovieToPrice[{shop, movie}];
    unrented[movie].erase({price, shop});
    rented.insert({price, {shop, movie}});
  }

  void drop(int shop, int movie) {
    const int price = shopAndMovieToPrice[{shop, movie}];
    unrented[movie].insert({price, shop});
    rented.erase({price, {shop, movie}});
  }

  vector<vector<int>> report() {
    vector<vector<int>> ans;
    int i = 0;

    for (const auto& [_, shopAndMovie] : rented) {
      ans.push_back({shopAndMovie.first, shopAndMovie.second});
      if (++i >= 5)
        break;
    }

    return ans;
  }

 private:
  struct pairHash {
    size_t operator()(const pair<int, int>& p) const {
      return p.first ^ p.second;
    }
  };

  // {movie: (price, shop)}
  unordered_map<int, set<pair<int, int>>> unrented;

  // {(shop, movie): price}
  unordered_map<pair<int, int>, int, pairHash> shopAndMovieToPrice;

  // (price, (shop, movie))
  set<pair<int, pair<int, int>>> rented;
};
