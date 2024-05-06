select name from stars
join movies on movies.id= stars.movie_id
join people on people.id = stars.person_id
where year = 2004
order by birth ;
