#!/bin/bash

gcc -Wall badptr.c -o badptr
valgrind ./badptr
