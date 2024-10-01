#!/bin/bash

directories=$(find . -type d)
if [[ -z "$@" ]] ; then
	for directory in $directories ; do
		echo "starting $directory"
		docker-compose -f "$directory"/compose.yaml down
	done
else 
	for directory in "$@" ; do
		if test -d "./$directory" ; then
			docker-compose -f ./"$directory"/compose.yaml down 
		else 
			echo "$directory doesnt exist"
		fi
	done
fi