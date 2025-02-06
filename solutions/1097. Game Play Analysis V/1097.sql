WITH
  PlayerToInstallDate AS (
    SELECT player_id, MIN(event_date) AS install_dt
    FROM Activity
    GROUP BY 1
  )
SELECT PlayerToInstallDate.install_dt,
  COUNT(*) AS installs,
  ROUND(
    SUM(IF(Activity.event_date, 1, 0)) / COUNT(PlayerToInstallDate.install_dt),
    2
  ) AS Day1_retention
FROM PlayerToInstallDate
LEFT JOIN Activity
  ON (
    PlayerToInstallDate.player_id = Activity.player_id
    AND DATEDIFF(Activity.event_date, PlayerToInstallDate.install_dt) = 1)
GROUP BY 1;
