# Created by: Nasseef Abukamail
# This Makefile will allow you to run tests for the dictionary class
#
# Usage:
#    make run_tests
#    mingw32-make run_tests_win
#
#Variables
CC = g++
CFLAGS = -g -Wall -std=c++11

# Linking all the files and run the tests. Use your own header and
# object files.

a.out: dictionary.o dictionary.h main.o
	$(CC) $(CFLAGS) _TEST/dictionary.o _TEST/main.o -o a.out

dictionary.o: dictionary.cc dictionary.h
	$(CC) -c $(CFLAGS) dictionary.cc -o _TEST/dictionary.o

main.o: main.cc dictionary.h
	$(CC) -c $(CFLAGS) main.cc -o _TEST/main.o

######################################## R U N   T E S T s ##################################################
run_tests: dictionary.h dictionary.o
	head dictionary.cc
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc dictionary.cc -o _TEST/run_tests ; _TEST/run_tests -sr compact

run_tests_win: dictionary.h dictionary.o
	$(CC) $(CFLAGS) _TEST/TEST_cases.cc dictionary.cc -o _TEST/run_tests
	_TEST/run_tests -sr compact
##############################################################################################################

clean:
	rm -rf _TEST/*.o _TEST/run_tests a.out _TEST/a.out

# ######################################### R U N   T E S T s ##################################################
# run_tests: dictionary.h dictionary.o
# 	head dictionary.cc
# 	$(CC) $(CFLAGS) _TEST/TEST_cases.cc _TEST/dictionary.o -o _TEST/a.out && ./_TEST/a.out -sr compact
# ##############################################################################################################
