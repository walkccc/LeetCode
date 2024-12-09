SELECT
  Activity.player_id,
  Activity.event_date,
  SUM(PrevActivity.games_played) AS games_played_so_far
FROM Activity
INNER JOIN Activity AS PrevActivity
  ON (
    Activity.player_id = PrevActivity.player_id
    AND Activity.event_date >= PrevActivity.event_date)
GROUP BY 1, 2
ORDER BY 1, 2;
