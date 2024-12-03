#!/bin/sh

if [ -z "$1" ] || [ -z "$2" ]
then
    echo "Invalid arguments!"
    exit 1
fi 

pathFile=$(dirname "$1")

mkdir -p  "$pathFile"

echo $2 > $1
