Union
Sometimes we just want to stack one dataset on top of the other. Well, the UNION operator allows us to do that.

Suppose we have two tables and they have the same columns.

table1:

pokemon	type
Bulbasaur	Grass
Charmander	Fire
Squirtle	Water

table2:

pokemon	type
Snorlax	Normal

If we combine these two with UNION:

SELECT *
FROM table1
UNION
SELECT *
FROM table2;
The result would be:

pokemon	type
Bulbasaur	Grass
Charmander	Fire
Squirtle	Water
Snorlax	Normal

SQL has strict rules for appending data:

Tables must have the same number of columns.
The columns must have the same data types in the same order as the first table.


 SELECT users.id 
 from users
 left join premium_users
 on users.id= premium_users.user_id
 where premium_users.user_id is NULL;


 WITH january AS (
  SELECT *
  FROM plays
  WHERE strftime("%m", play_date) = '01'
),
february AS (
  SELECT *
  FROM plays
  WHERE strftime("%m", play_date) = '02'

)
/*
Write query here
*/
SELECT january.user_id from january
left join february
on february.user_id = january.user_id
WHERE february.user_id IS NULL;