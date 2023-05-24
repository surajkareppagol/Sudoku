CC = gcc
CCFLAGS = -Wall -Werror -std=c17
SRCS = decorate.c sudoku.c main.c
ICNS = decorate.h sudoku.h

game: $(SRCS) $(INCS)
	@$(CC) $(SRCS) -o game $(CCFLAGS) -lncurses
	@echo "Build Done, run \"make run\" to execute."

.PHONY: clean
clean:
	@rm game
	@echo "Cleaning Done."

.PHONY: run
run:
	@clear && ./game

.PHONY: test
test:
	@./game -t
