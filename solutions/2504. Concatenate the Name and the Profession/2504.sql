SELECT
  person_id,
  CONCAT(name, '(', LEFT(profession, 1), ')') name
FROM Person
ORDER BY 1 DESC;
