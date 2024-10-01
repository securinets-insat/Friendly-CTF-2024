#!/bin/bash

stop_container() {
    local directory="$1"
    echo "Stopping $directory"
    if [ -f "$directory/compose.yaml" ]; then
        docker-compose -f "$directory/compose.yaml" down
    elif [ -f "$directory/docker-compose.yaml" ]; then
        docker-compose -f "$directory/docker-compose.yaml" down
    else
        echo "No compose file found in $directory"
    fi
}

if [[ $# -eq 0 ]] ; then
    for directory in */; do
        directory="${directory%/}"  # Remove trailing slash
        if [ "$directory" != "." ] && [ "$directory" != ".." ]; then
            stop_container "$directory"
        fi
    done
else
    for directory in "$@"; do
        if [ -d "./$directory" ]; then
            stop_container "./$directory"
        else
            echo "$directory doesn't exist"
        fi
    done
fi