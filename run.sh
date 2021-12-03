#!/bin/bash

cmake .
make clean && make -j
./bin/cuckoo_filter 30 test.txt