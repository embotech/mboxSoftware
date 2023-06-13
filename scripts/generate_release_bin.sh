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
# Build directory
buildir="$rootdir/tmp_build"
# Release directory
relname="mbox_software_package_v$version"
reldir="$rootdir/$relname"
# Release zip
relzip="$reldir/$relname.zip"

# Clean release dir
shopt -s extglob    # Activate extended pattern matching
[ ! -d $reldir ] && mkdir -p $reldir
rm -rf $reldir/*

# Clean build dir
[ ! -d $buildir ] && mkdir -p $buildir
cd $buildir
rm -rf .

# Configure CMake
cmake -G "Unix Makefiles" \
    -DCMAKE_TOOLCHAIN_FILE=$rootdir/cmake/aarch64.cmake \
    -DCMAKE_BUILD_TYPE=RELEASE \
    -DCMAKE_VERBOSE_MAKEFILE:BOOL=ON \
    ..

# Build
cmake --build . -j4

# Go back to root directory
cd $rootdir

# Copy executable to release directory
cp $buildir/main/mbox-obrttg-software $reldir

# Remove build directory
rm -rf $buildir

# Create documentation
python3 $rootdir/doc/update_doc.py $reldir

# Zip release
cd $reldir
zip -r -e $relzip .

echo "--> Release zip file created in $relzip"

# Go back to original directory
cd $oridir
