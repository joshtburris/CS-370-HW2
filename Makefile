CXXFLAGS=-Wall -Wextra -Wextra -Wpedantic -Werror -Wfatal-errors
CC=gcc
FILE1=Coordinator.c
FILE2=Checker.c
OUT_EXE=Coordinator
OUT_EXE2=Checker
build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILE1)
	$(CC) -o $(OUT_EXE2) $(FILE2)
clean:
	rm -f *.o $(OUT_EXE)
	rm -f *.o $(OUT_EXE2)
