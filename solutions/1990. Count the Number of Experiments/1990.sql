WITH
  Platforms AS (
    SELECT 'Android' AS platform
    UNION ALL
    SELECT 'IOS' AS platform
    UNION ALL
    SELECT 'Web' AS platform
  ),
  ExperimentNames AS (
    SELECT 'Reading' AS experiment_name
    UNION ALL
    SELECT 'Sports'
    UNION ALL
    SELECT 'Programming'
  )
SELECT
  Platforms.platform,
  ExperimentNames.experiment_name,
  COUNT(experiment_id) AS num_experiments
FROM Platforms
CROSS JOIN ExperimentNames
LEFT JOIN Experiments
  USING (platform, experiment_name)
GROUP BY 1, 2;
