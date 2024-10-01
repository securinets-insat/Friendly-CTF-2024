#!/bin/bash

directories=$(find . -type d)
if [[ -z "$@" ]] ; then
	for directory in $directories ; do
		if [ "$directory" != "." ]; then
			echo "starting $directory"
			docker-compose -f "$directory"/docker-compose.yml up --build -d
		fi

	done
else 
	for directory in "$@" ; do
		if test -d "./$directory" ; then
			docker-compose -f ./"$directory"/docker-compose.yml up --build -d 
		else 
			echo "$directory doesnt exist"
		fi
	done
fi