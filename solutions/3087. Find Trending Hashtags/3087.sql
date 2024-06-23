SELECT
  CONCAT(
    '#',
    SUBSTRING_INDEX(SUBSTRING_INDEX(tweet, '#', -1), ' ', 1)
  ) AS hashtag,
  COUNT(*) AS hashtag_count
FROM Tweets
WHERE MONTH(tweet_date) = 2
GROUP BY hashtag
ORDER BY hashtag_count DESC, hashtag DESC
LIMIT 3;
