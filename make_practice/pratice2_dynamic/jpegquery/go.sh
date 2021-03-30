#!/bin/sh

export LD_LIBRARY_PATH="`pwd`/jpegquery_info/bin"
echo $LD_LIBRARY_PATH
./app/jpegquery_test//bin/jpegquery_test $1
