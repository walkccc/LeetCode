WITH
  FilteredPosts AS (
    SELECT *
    FROM Posts
    WHERE post_date BETWEEN '2024-02-01' AND '2024-02-28'
  ),
  AvgWeeklyPosts AS (
    SELECT user_id, COUNT(*) / 4.0 AS avg_weekly_posts
    FROM FilteredPosts
    GROUP BY 1
  ),
  UserTo7dayPosts AS (
    SELECT
      FirstPost.user_id,
      COUNT(*) AS sevenday_posts
    FROM Posts AS FirstPost
    INNER JOIN Posts AS FollowingPost
      ON (
        FirstPost.user_id = FollowingPost.user_id
        AND FollowingPost.post_date BETWEEN FirstPost.post_date
        AND DATE_ADD(FirstPost.post_date, INTERVAL 6 DAY))
    GROUP BY FirstPost.user_id, FirstPost.post_date
  ),
  UserToMax7dayPosts AS (
    SELECT user_id, MAX(sevenday_posts) AS max_7day_posts
    FROM UserTo7dayPosts
    GROUP BY 1
  )
SELECT *
FROM UserToMax7dayPosts
INNER JOIN AvgWeeklyPosts
  USING (user_id)
WHERE UserToMax7dayPosts.max_7day_posts >= 2 * AvgWeeklyPosts.avg_weekly_posts
ORDER BY user_id;
