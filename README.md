# 🌟 So Long 42 🌟
```
   ▄████████  ▄██████▄        ▄█        ▄██████▄  ███▄▄▄▄      ▄██████▄  
  ███    ███ ███    ███      ███       ███    ███ ███▀▀▀██▄   ███    ███ 
  ███    █▀  ███    ███      ███       ███    ███ ███   ███   ███    █▀  
  ███        ███    ███      ███       ███    ███ ███   ███  ▄███        
▀███████████ ███    ███      ███       ███    ███ ███   ███ ▀▀███ ████▄  
         ███ ███    ███      ███       ███    ███ ███   ███   ███    ███ 
   ▄█    ███ ███    ███      ███▌    ▄ ███    ███ ███   ███   ███    ███ 
 ▄████████▀   ▀██████▀       █████▄▄██  ▀██████▀   ▀█   █▀    ████████▀  
                             ▀                                            
```

<div align="center">

![42 Badge](https://img.shields.io/badge/42-so_long-000000?style=for-the-badge&logo=42&logoColor=white)
![Language](https://img.shields.io/badge/language-C-00599C?style=for-the-badge&logo=c&logoColor=white)
![Build](https://img.shields.io/badge/build-Makefile-427819?style=for-the-badge&logo=gnu&logoColor=white)
![Graphics](https://img.shields.io/badge/graphics-MiniLibX-orange?style=for-the-badge)
![Platform](https://img.shields.io/badge/platform-Linux-blue?style=for-the-badge&logo=linux&logoColor=white)
![Status](https://img.shields.io/badge/status-Bonus%20Included-success?style=for-the-badge)

</div>

## 🎮 About the Project

**so_long** is a 42 School graphics project where the goal is to build a small 2D game in **C** using **MiniLibX**.
The player must explore a map, collect every collectible, and reach the exit while respecting map rules and movement constraints.

This repository includes both the **mandatory** part and the **bonus** version, with extra animations, enemies, and a graphical move counter.

---

## ✨ Portfolio Highlights

This project demonstrates:

- **C programming fundamentals**
- **2D rendering with MiniLibX**
- **map parsing and validation**
- **event-driven input handling**
- **path validation / solvability checking**
- **memory management**
- **game loop logic**
- **sprite animation and bonus gameplay systems**

---

## 🕹️ Features

### Mandatory Part

- Load and validate `.ber` maps
- Detect invalid shapes and map content
- Check that the map is closed by walls
- Ensure there is exactly:
  - `1` player (`P`)
  - `1` exit (`E`)
  - at least `1` collectible (`C`)
- Render the map in a graphical window
- Move the player using keyboard controls
- Count and display moves
- Allow exit only after collecting everything
- Validate whether the map is actually solvable before starting

### Bonus Part

- Animated player sprites
- Animated environment elements
- Enemy spawning and rendering
- Enemy movement/interaction systems
- Idle animations
- Graphical move counter using sprite digits
- More polished visual presentation
- Multiple sample maps for testing

---

## 🗂️ Project Structure

```text
So_Long_42/
├── inc/               # headers
├── img/               # in-game textures and xpm assets
├── graphical/         # source art / sprite resources
├── libs/              # libft + MiniLibX
├── maps/
│   ├── valid/         # working maps
│   └── invalid/       # invalid maps for testing parser rules
├── srcs/              # mandatory sources
├── srcs_bonus/        # bonus sources
└── Makefile           # build rules
```

---

## 🧠 How It Works

At startup, the program:

1. checks if a map path was provided
2. validates the `.ber` extension
3. reads the map into memory
4. checks map shape and required elements
5. validates that the map is playable
6. initializes MiniLibX
7. loads textures and sprites
8. renders the game window and starts the loop

From your codebase:

- `srcs/main.c` handles the mandatory startup flow
- `srcs_bonus/main_bonus.c` extends that flow with:
  - animation setup
  - enemy initialization
  - graphical move display
  - loop hooks for animated gameplay

---

## 🧱 Map Rules

A valid map must:

- have the `.ber` extension
- be rectangular
- be surrounded by walls
- contain only valid characters
- contain exactly one player start (`P`)
- contain exactly one exit (`E`)
- contain at least one collectible (`C`)
- be solvable

### Tile Legend

- `1` → Wall
- `0` → Empty floor
- `P` → Player start
- `C` → Collectible
- `E` → Exit

---

## 🎯 Controls

- `W` → Move up
- `A` → Move left
- `S` → Move down
- `D` → Move right
- `ESC` → Exit the game
- Window close button → Quit cleanly

---

## ⚙️ Build Instructions

### Requirements

This project is built for **Linux** with **MiniLibX / X11**.

You need:

- `cc`
- `make`
- X11 development libraries
- local dependencies already included in `libs/`

### Compile mandatory version

```bash
git clone https://github.com/PatzCM/So_Long_42.git
cd So_Long_42
make
```

### Compile bonus version

```bash
make bonus
```

### Clean object files

```bash
make clean
```

### Full clean

```bash
make fclean
```

### Rebuild everything

```bash
make re
```

### Norm check

```bash
make norminette
```

---

## ▶️ Running the Game

### Mandatory

```bash
./so_long maps/valid/map1.ber
```

### Bonus

```bash
./so_long_bonus maps/valid/map1.ber
```

You can replace `map1.ber` with any valid `.ber` map in the repository.

---

## 🗺️ Included Example Maps

### Valid maps

- `maps/valid/map0.ber`
- `maps/valid/map1.ber`
- `maps/valid/map2.ber`
- `maps/valid/map3.ber`
- `maps/valid/map4.ber`

### Invalid maps

Useful for testing parser and validation errors:

- `maps/invalid/has_other_elem.ber`
- `maps/invalid/hole_in_wall.ber`
- `maps/invalid/map1.ber`
- `maps/invalid/not_rect.ber`
- `maps/invalid/only_c.ber`
- `maps/invalid/only_e.ber`
- `maps/invalid/only_e_and_p.ber`
- `maps/invalid/only_p.ber`

---

## 🖼️ Screenshots / GIFs

This repository already contains visual assets in `graphical/`, including:

- `graphical/player.png`
- `graphical/collec.png`
- `graphical/exit.png`
- `graphical/a_exit.png`


---

## 🎨 Visual Identity

This project appears to use custom assets and sprite resources from folders such as:

- `graphical/idle`
- `graphical/walk_up`
- `graphical/walk_down`
- `graphical/walk_left`
- `graphical/walk_right`
- `graphical/idle_zombie`
- `graphical/z_up`
- `graphical/z_down`
- `graphical/z_left`
- `graphical/z_right`
- `graphical/walls`

That gives the bonus version a much stronger game feel than a basic mandatory-only implementation.

---

## 📚 Technical Notes

- Main executable: `so_long`
- Bonus executable: `so_long_bonus`
- Uses local `libft` from `libs/libft`
- Uses local MiniLibX build from `libs/mlx`
- The Makefile includes a `norminette` target
- The project is primarily written in **C** with a **Makefile** build system

---

## 👩‍💻 Author

**Patricia Monteiro**

- GitHub: [PatzCM](https://github.com/PatzCM)
- Project: [So_Long_42](https://github.com/PatzCM/So_Long_42)

---

## 🏫 42 Context

This project is part of the **42 curriculum**, where the objective is not only to make a working game, but also to apply strict coding rules, validation logic, graphics programming, and clean memory handling.

It reflects practical work in:

- structured C development
- algorithmic thinking
- low-level graphics handling
- debugging and validation
- transforming a small specification into an interactive project

---
