#!/bin/bash

directories=$(find . -type d)
if [[ -z "$@" ]] ; then
	for directory in $directories ; do
		echo "starting $directory"
		docker-compose -f "$directory"/docker-compose.yml down
	done
else 
	for directory in "$@" ; do
		if test -d "./$directory" ; then
			docker-compose -f ./"$directory"/docker-compose.yml down 
		else 
			echo "$directory doesnt exist"
		fi
	done
fi