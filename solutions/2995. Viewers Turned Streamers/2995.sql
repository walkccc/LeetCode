WITH
  FirstSessions AS (
    SELECT
      user_id,
      session_type,
      RANK() OVER(PARTITION BY user_id ORDER BY session_start) AS session_rank
    FROM Sessions
  ),
  ViewerFirst AS (
    SELECT user_id
    FROM FirstSessions
    WHERE session_rank = 1 AND session_type = 'Viewer'
  )
SELECT
  Sessions.user_id,
  COUNT(*) AS sessions_count
FROM Sessions
INNER JOIN ViewerFirst
  USING (user_id)
WHERE Sessions.session_type = 'Streamer'
GROUP BY 1
ORDER BY sessions_count DESC, Sessions.user_id DESC;
