# Sudoku

This is the `Sudoku` game created in **c** language.

---

## Trying to solve it automatically !

I have read that there are many different algorithms and strategies that can be applied to solve **sudoku**.But here i'm trying to implement it on my own.

I created two functions to solve it horizontally and vertically.

```bash
./sudoku -hv
```

Use `-hv` option to solve it horizontally first and then vertically, but it's not correct it's still in development.

## How to play?

In this game there are 9 blocks and each block has 9 cells.

![Game board](images/gameBoard.png)

So you need to enter the input in this format,

`Enter the block, cell number and the value 👇,`

`> 1 1 1`

Here the block number is **_1_**, cell number is **_1_** and the value to be inserted is also **_1_**.

---

## Output

![Generated game board](images/generatedBoard.png)

`Enter the block, cell number and the value 👇,`

`> 2 1 2`

Here the block number is **_2_**, cell number is **_1_** and the value to be inserted is also **_2_**.

![Game play](images/gamePlay.png)

To exit the game 🗙,

`Enter the block, cell number and the value 👇,`

`> 0 0 0`

![Exit game](images/exitGame.png)
