WITH
  Posts AS (
    SELECT DISTINCT sub_id AS post_id
    FROM Submissions
    WHERE parent_id IS NULL
  )
SELECT
  Posts.post_id,
  COUNT(DISTINCT Comments.sub_id) AS number_of_comments
FROM Posts
LEFT JOIN Submissions AS Comments
  ON (Posts.post_id = Comments.parent_id)
GROUP BY 1;
