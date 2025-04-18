WITH
  StadiumNeighbors AS (
    SELECT
      id,
      visit_date,
      people,
      LAG(people, 1) OVER(ORDER BY id) AS prev_people_1,
      LAG(people, 2) OVER(ORDER BY id) AS prev_people_2,
      LEAD(people, 1) OVER(ORDER BY id) AS next_people_1,
      LEAD(people, 2) OVER(ORDER BY id) AS next_people_2
    FROM Stadium
  )
SELECT
  id,
  visit_date,
  people
FROM StadiumNeighbors
WHERE
  people >= 100 AND (
    prev_people_1 >= 100 AND prev_people_2 >= 100
    OR prev_people_1 >= 100 AND next_people_1 >= 100
    OR next_people_1 >= 100 AND next_people_2 >= 100
  )
ORDER BY visit_date;
