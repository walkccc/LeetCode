WITH
  UserToContest AS (
    SELECT gold_medal AS user_id, contest_id FROM Contests
    UNION ALL
    SELECT silver_medal AS user_id, contest_id FROM Contests
    UNION ALL
    SELECT bronze_medal AS user_id, contest_id FROM Contests
  ),
  UserToContestWithGroupId AS (
    SELECT
      user_id,
      contest_id - ROW_NUMBER() OVER(
        PARTITION BY user_id
        ORDER BY contest_id
      ) AS group_id
    FROM UserToContest
  ),
  CandidateUserIds AS (
    -- consecutive medal winners
    SELECT user_id
    FROM UserToContestWithGroupId
    GROUP BY user_id, group_id
    HAVING COUNT(*) >= 3
    UNION DISTINCT
    -- gold medal winners
    SELECT gold_medal AS user_id
    FROM Contests
    GROUP BY user_id
    HAVING COUNT(*) >= 3
  )
SELECT
  Users.name,
  Users.mail
FROM CandidateUserIds
INNER JOIN Users
  USING (user_id);
