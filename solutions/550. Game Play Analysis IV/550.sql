WITH
  Players AS (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY 1
  )
SELECT ROUND(
    COUNT(Players.player_id) / (
      SELECT COUNT(DISTINCT Activity.player_id)
      FROM Activity
    ),
    2
  ) AS fraction
FROM Players
INNER JOIN Activity
  ON (
    Players.player_id = Activity.player_id
    AND DATEDIFF(Players.first_login, Activity.event_date) = -1)
