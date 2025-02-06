/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * interface HtmlParser {
 *   public List<String> getUrls(String url) {}
 * }
 */

class Solution {
  public List<String> crawl(String startUrl, HtmlParser htmlParser) {
    Queue<String> q = new ArrayDeque<>(List.of(startUrl));
    Set<String> seen = new HashSet<>(Arrays.asList(startUrl));
    final String hostname = startUrl.split("/")[2];

    while (!q.isEmpty()) {
      final String currUrl = q.poll();
      for (final String url : htmlParser.getUrls(currUrl)) {
        if (seen.contains(url))
          continue;
        if (url.contains(hostname)) {
          q.offer(url);
          seen.add(url);
        }
      }
    }

    return new ArrayList<>(seen);
  }
}
