#!/bin/sh

if [ -z $1 ] || [ -z $2 ]
then
    echo "Invalid arguments!"
    exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d $filesdir ]
then
    echo $filesdir" is not a directory or don't exist"
    exit 2
fi

fCount=$(ls $filesdir | wc -l)
ffCount=$(grep -r "${serachstr}" $filesdir | wc -l)

echo "The number of files are ${fCount} and the number of matching lines are ${ffCount}"
