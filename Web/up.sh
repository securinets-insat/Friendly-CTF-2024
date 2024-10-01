#!/bin/bash

start_container() {
    local directory="$1"
    echo "Starting $directory"
    if [ -f "$directory/compose.yaml" ]; then
        docker-compose -f "$directory/compose.yaml" up --build -d
    elif [ -f "$directory/docker-compose.yaml" ]; then
        docker-compose -f "$directory/docker-compose.yaml" up --build -d
    else
        echo "No compose file found in $directory"
    fi
}

if [[ $# -eq 0 ]] ; then
    for directory in */; do
        directory="${directory%/}"  # Remove trailing slash
        if [ "$directory" != "." ] && [ "$directory" != ".." ]; then
            start_container "$directory"
        fi
    done
else
    for directory in "$@"; do
        if [ -d "./$directory" ]; then
            start_container "./$directory"
        else
            echo "$directory doesn't exist"
        fi
    done
fi