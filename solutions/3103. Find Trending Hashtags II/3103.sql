WITH
  RECURSIVE FebruaryTweets AS (
    SELECT * FROM Tweets
    WHERE YEAR(tweet_date) = 2024 AND MONTH(tweet_date) = 2
  ),
  HashtagToTweet AS (
    SELECT
      REGEXP_SUBSTR(tweet, '#[^\\s]+') AS hashtag,
      REGEXP_REPLACE(tweet, '#[^\\s]+', '', 1, 1) AS tweet
    FROM FebruaryTweets
    UNION ALL
    SELECT
      REGEXP_SUBSTR(tweet, '#[^\\s]+') AS hashtag,
      REGEXP_REPLACE(tweet, '#[^\\s]+', '', 1, 1) AS tweet
    FROM HashtagToTweet
    WHERE POSITION('#' IN tweet) > 0
  )
SELECT
  hashtag,
  COUNT(*) AS count
FROM HashtagToTweet
GROUP BY hashtag
ORDER BY count DESC, hashtag DESC
LIMIT 3;
