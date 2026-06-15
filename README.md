# so_long

A small 2D tile-based game built in C for the 42 curriculum, using MiniLibX. The objective is simple: collect every collectible on the map, then reach the exit without getting trapped.

## Overview

This project focuses on:

- reading and validating `.ber` map files
- rendering a 2D game window with MiniLibX
- handling keyboard input and player movement
- enforcing game rules such as walls, collectibles, and exits
- checking whether a map is actually solvable
- extending the mandatory version with animations and enemies in the bonus version

The repository includes both the mandatory and bonus implementations.

## Features

### Mandatory

- rectangular map validation
- closed walls around the map
- required map contents validation (`P`, `E`, `C`, `0`, `1`)
- player movement with move counting
- collectible tracking
- exit unlock flow after collecting everything
- map path validation before the game starts

### Bonus

- animated sprites
- enemy spawning and rendering
- player idle animation
- extra tile and movement animations
- graphical move counter
- multiple sample maps

## Project Structure

- `srcs/` — mandatory source files
- `srcs_bonus/` — bonus source files
- `inc/` — headers
- `img/` — textures and animation assets
- `maps/valid/` — playable example maps
- `maps/invalid/` — invalid test maps for parser/validator checks
- `libs/libft/` — custom C utility library
- `libs/mlx/` / `libs/minilibx-linux` — MiniLibX dependency
- `Makefile` — build rules for mandatory and bonus targets

## Build

### Requirements

This project is configured for MiniLibX on Linux/X11.

You will need:

- `cc`
- `make`
- X11 development libraries
- the bundled MiniLibX sources in `libs/`

### Compile mandatory

```bash
make
```

### Compile bonus

```bash
make bonus
```

### Clean objects

```bash
make clean
```

### Full clean

```bash
make fclean
```

### Rebuild

```bash
make re
```

## Run

### Mandatory

```bash
./so_long maps/valid/map1.ber
```

### Bonus

```bash
./so_long_bonus maps/valid/map1.ber
```

You can replace the example map with any valid `.ber` file.

## Map Rules

A valid map must:

- use the `.ber` extension
- be rectangular
- be surrounded by walls
- contain exactly one player start (`P`)
- contain exactly one exit (`E`)
- contain at least one collectible (`C`)
- contain only valid characters
- be solvable

### Tile Legend

- `1` — wall
- `0` — empty floor
- `P` — player start
- `C` — collectible
- `E` — exit

## Controls

- `W` — move up
- `A` — move left
- `S` — move down
- `D` — move right
- `ESC` — quit the game
- window close button — exit cleanly

## Example Maps

Included sample maps:

### Valid maps

- `maps/valid/map0.ber`
- `maps/valid/map1.ber`
- `maps/valid/map2.ber`
- `maps/valid/map3.ber`
- `maps/valid/map4.ber`

### Invalid maps

These are useful for testing validation and error handling:

- `maps/invalid/has_other_elem.ber`
- `maps/invalid/hole_in_wall.ber`
- `maps/invalid/map1.ber`
- `maps/invalid/not_rect.ber`
- `maps/invalid/only_c.ber`
- `maps/invalid/only_e.ber`
- `maps/invalid/only_e_and_p.ber`
- `maps/invalid/only_p.ber`

## What the Code Does

At startup, the program:

1. checks the input argument and file extension
2. loads the map into memory
3. validates shape and required elements
4. verifies the map can be completed
5. initializes the window and textures
6. renders the game and starts the event loop

The bonus version additionally initializes animations, enemies, and graphical counters before entering the main loop.

## Notes

- The default bonus target builds `so_long_bonus`.
- The project uses `libft` and MiniLibX from the local `libs/` directory.
- The Makefile also includes a `norminette` target for style checks.

## Author

**Patricia Monteiro**

GitHub: [PatzCM](https://github.com/PatzCM)

## License

This repository does not currently include a license file. If you want, you can add one later.
