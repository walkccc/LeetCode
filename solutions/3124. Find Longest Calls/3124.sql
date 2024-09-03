WITH
  RankedCalls AS (
    SELECT
      Contacts.first_name,
      Calls.type,
      Calls.duration,
      RANK() OVER(
        PARTITION BY type
        ORDER BY duration DESC
      ) AS `rank`
    FROM Calls
    INNER JOIN Contacts
      ON (Calls.contact_id = Contacts.id)
  )
SELECT
  first_name,
  type,
  CONCAT(
    LPAD(FLOOR(duration / 3600), 2, '0'), ':',
    LPAD(FLOOR((duration % 3600) / 60), 2, '0'), ':',
    LPAD(FLOOR(duration % 60), 2, '0')
  ) AS duration_formatted
FROM RankedCalls
WHERE `rank` <= 3
ORDER BY type, duration DESC, first_name DESC;
