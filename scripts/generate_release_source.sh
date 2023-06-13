#!/bin/bash
#
# (C) Copyright Embotech AG, Zurich, Switzerland 2013-2023
#

# Get current working directory
oridir=$(pwd)
# Get repository root directory
rootdir=$(git rev-parse --show-toplevel)
cd $rootdir
# Version
version=$(cat VERSION)
version="${version//\./_}"
# Release directory
relname="mbox_software_package_source_v$version"
reldir="$rootdir/$relname"
# Release zip
relzip="$reldir/$relname.zip"

# Check if repository is clean
dirtyFiles=$(git ls-files --others communication obrttg dependencies main logging obrttg utils main)
[ -z "$dirtyFiles" ] && \
    ( echo -e "[INFO] Release directories are clean and ready to be released." ) || \
    ( echo -e "[ERROR] Release directories are not clean:\n$dirtyFiles" && exit 1 )

# Clean release dir
shopt -s extglob    # Activate extended pattern matching
[ ! -d $reldir ] && mkdir -p $reldir
rm -rf $reldir/*

echo -e "[INFO] Zipping release $relname."
zip -r -e $relzip codegen communication dependencies main logging obrttg utils CMakeLists.txt README.md -x examples/logs/**\* > /dev/null 2>&1 

[ $? -eq 0 ] && ( echo -e "[INFO] Successfully released $relname." ) || ( echo -e "[ERROR] An error occured while zipping $relname." && exit 1 )

# Go back to original directory
cd $oridir
exit 0