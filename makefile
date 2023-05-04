CC = gcc
CCFLAGS = -Wall -Werror -std=c17
SRCS = sudoku.c main.c
ICNS = sudoku.h

game: $(SRCS) $(INCS)
	@$(CC) $(SRCS) -o game $(CCFLAGS)
	@echo "Build Done, run \"make run\" to execute."

.PHONY: clean
clean:
	rm game
	@echo "Cleaning Done."

.PHONY: run
run:
	@./game

.PHONY: test
test:
	@./game -t