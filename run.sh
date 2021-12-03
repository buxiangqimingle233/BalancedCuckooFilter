#!/bin/bash

cmake .
make clean && make -j
./bin/cuckoo_filter 2048 test.txt