#!/bin/bash

if [[ "$1" != "" ]] ; then
    compiler="$1"
else
    compiler="bin/c_compiler"
fi

if [[ ! -f bin/c_compiler ]] ; then
    >&2 echo "Warning : cannot find compiler at path ${compiler}. Stuff probably about to break."
    have_compiler=1
fi

input_dir="test_deliverable/test_cases"
working = "tmp/test_out"

mkdir -p ${working}
