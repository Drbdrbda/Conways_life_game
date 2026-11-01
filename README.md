# Install
## Install dependencies
```
sudo apt install libncurses-dev
```

# Game rules

## Cell's live rules

The Game of Life is a cellular automaton invented by John Horton Conway.
The field consists of cells, each of which can be in one of two states:
alive or dead. Generations follow each other according to three rules.

### 1. Survival

A live cell stays alive if it has **2 or 3** live neighbours.
Otherwise it dies from underpopulation or overpopulation.

### 2. Birth

A dead cell becomes alive if it has exactly **3** live neighbours.

### 3. Death

- A live cell with **fewer than 2** live neighbours dies from underpopulation.
- A live cell with **more than 3** live neighbours dies from overpopulation.
- A dead cell with **fewer than 3** or **more than 3** neighbours stays dead.

Neighbours are the 8 cells surrounding a given cell (horizontally, vertically,
and diagonally). The cell itself is not counted.

## Hotkeys

| Key | Action |
|-----|--------|
| `q` | Exit the game |
| `Space` | Pause / resume |
| `r` | Randomly fill the field |

## Mouse controls

| Action | Result |
|--------|--------|
| Left click on a cell | Toggle the cell state (alive ↔ dead) |