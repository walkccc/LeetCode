class Creator {
  public long popularity; // the popularity sum
  public String videoId;  // the video id that has the maximum view
  public int maxView;     // the maximum view of the creator
  public Creator(long popularity, String videoId, int maxView) {
    this.popularity = popularity;
    this.videoId = videoId;
    this.maxView = maxView;
  }
}

class Solution {
  public List<List<String>> mostPopularCreator(String[] creators, String[] ids, int[] views) {
    List<List<String>> ans = new ArrayList<>();
    Map<String, Creator> nameToCreator = new HashMap<>();
    long maxPopularity = 0;

    for (int i = 0; i < creators.length; ++i) {
      if (!nameToCreator.containsKey(creators[i])) {
        nameToCreator.put(creators[i], new Creator(views[i], ids[i], views[i]));
        maxPopularity = Math.max(maxPopularity, (long) views[i]);
        continue;
      }
      Creator creator = nameToCreator.get(creators[i]);
      creator.popularity += views[i];
      maxPopularity = Math.max(maxPopularity, (long) creator.popularity);
      if (creator.maxView < views[i] ||
          creator.maxView == views[i] && creator.videoId.compareTo(ids[i]) > 0) {
        creator.videoId = ids[i];
        creator.maxView = views[i];
      }
    }

    for (Map.Entry<String, Creator> entry : nameToCreator.entrySet())
      if (entry.getValue().popularity == maxPopularity)
        ans.add(Arrays.asList(entry.getKey(), entry.getValue().videoId));

    return ans;
  }
}
