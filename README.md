# Sudoku

This is the `sudoku` game created in `C` language.

## Automatic Game Solving

Use `-t` option to solve it horizontally and vertically, although it is still in development.

```bash
./sudoku -t
```

or,

```bash
make test
```

## How to play

There are 9 blocks and each block has 9 cells.

![Game board](images/gameBoard.png)

Enter the input in this format,

`Enter the block, cell number and the value 👇,`

`> 1 1 1`

Here the block number is `1`, cell number is `1` and the value to be inserted is also `1`.

## Sample GamePlay

![Generated game board](images/generatedBoard.png)

`Enter the block, cell number and the value 👇,`

`> 2 1 2`

Here the block number is **_2_**, cell number is **_1_** and the value to be inserted is also **_2_**.

![Game play](images/gamePlay.png)

To exit the game 🗙,

`Enter the block, cell number and the value 👇,`

`> 0 0 0`

![Exit game](images/exitGame.png)

### To Do's

- Integrate `ncurses` library, and make it a `TUI` application.
- Finish the automatic sudoku solver.
