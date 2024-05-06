select distinct name from movies
join stars on movies.id = stars.movie_id
join people on people.id = stars.person_id
where  movie_id in
(select movie_id from movies
join stars on movies.id= stars.movie_id
join people on people.id = stars.person_id
where  people.name  =  "Kevin Bacon" AND people.birth = "1958"
)
and people.name !=  "Kevin Bacon";

