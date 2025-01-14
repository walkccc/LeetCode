WITH
  PowerToTerm AS (
    SELECT
      CONCAT(
        IF(factor > 0, '+', ''),
        factor,
        IF(power = 0, '', 'X'),
        IF(power IN (0, 1), '', CONCAT('^', power))
      ) AS term,
      power
    FROM Terms
    ORDER BY power DESC
  )
SELECT
  CONCAT(
    GROUP_CONCAT(
      term
      ORDER BY power DESC SEPARATOR ''
    ),
    '=0'
  ) AS equation
FROM PowerToTerm;
