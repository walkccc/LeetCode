class Entry {
  public int price;
  public int shop;
  public int movie;

  public Entry(int price, int shop, int movie) {
    this.price = price;
    this.shop = shop;
    this.movie = movie;
  }
}

class MovieRentingSystem {
  public MovieRentingSystem(int n, int[][] entries) {
    for (int[] e : entries) {
      final int shop = e[0];
      final int movie = e[1];
      final int price = e[2];
      unrented.putIfAbsent(movie, new TreeSet<>(comparator));
      unrented.get(movie).add(new Entry(price, shop, movie));
      shopAndMovieToPrice.put(new Pair<>(shop, movie), price);
    }
  }

  public List<Integer> search(int movie) {
    return unrented.getOrDefault(movie, Collections.emptySet())
        .stream()
        .limit(5)
        .map(e -> e.shop)
        .collect(Collectors.toList());
  }

  public void rent(int shop, int movie) {
    final int price = shopAndMovieToPrice.get(new Pair<>(shop, movie));
    unrented.get(movie).remove(new Entry(price, shop, movie));
    rented.add(new Entry(price, shop, movie));
  }

  public void drop(int shop, int movie) {
    final int price = shopAndMovieToPrice.get(new Pair<>(shop, movie));
    unrented.get(movie).add(new Entry(price, shop, movie));
    rented.remove(new Entry(price, shop, movie));
  }

  public List<List<Integer>> report() {
    return rented.stream().limit(5).map(e -> List.of(e.shop, e.movie)).collect(Collectors.toList());
  }

  private Comparator<Entry> comparator = (a, b) -> {
    if (a.price != b.price)
      return Integer.compare(a.price, b.price);
    if (a.shop != b.shop)
      return Integer.compare(a.shop, b.shop);
    return Integer.compare(a.movie, b.movie);
  };

  // {movie: (price, shop)}
  private Map<Integer, Set<Entry>> unrented = new HashMap<>();

  // {(shop, movie): price}
  private Map<Pair<Integer, Integer>, Integer> shopAndMovieToPrice = new HashMap<>();

  // (price, shop, movie)
  private Set<Entry> rented = new TreeSet<>(comparator);
}
