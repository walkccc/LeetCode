WITH
  UniqueNumbers AS (
    SELECT num
    FROM MyNumbers
    GROUP BY 1
    HAVING COUNT(num) = 1
  )
SELECT MAX(num) AS num
FROM UniqueNumbers;
