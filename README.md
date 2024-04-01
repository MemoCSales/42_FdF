
# FdF - A wireframe model

This project is about showing a landscape as a 3D object with lines outlining all surfaces.
Using the MinilbX library, this project goal is to get familiarized with tools to open windows, create images and deal with keyboard and mouse events. (Supported in Linux)

All in pure C programming language.


## Instructions


- This project mus be written in C
- It has to be written following the Norm of 42 schools
- The functions should not quit unexpectedly (segmentation fault, bus error, double free, etc)
- All heap memory allocation must be properly freed.
- The `Makefile` must at least contain the rules: `$(NAME)`, `all`, `clean`, `fclean` and `re`. And it should not relink.

## Allowed functions

- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- All functions of the math library (-lm compiler option man man 3 math)
- All functions of the MiniLibX
- ft_printf and any equivalent
## Screenshots

![App Screenshot](https://via.placeholder.com/468x300?text=App+Screenshot+Here)


### Features (for linux)

- Create an executable program named: `./fdf`
- Press `Q` for Zoom In
- Press `E` for Zoom Out


## Installation

Clone this repo locally:

```bash
  git clone https://github.com/MemoCSales/42_FdF.git
```
Build this project in the root directory:

```bash
  make
```
    
## Deployment

To deploy this project run:

```bash
  ./fdf <map-name>.fdf
```
Go to the maps directory inside the root directory to find the name of the map you want to render.

