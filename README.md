<h1 align="center">FdF - A wireframe model</h1>

<p align="center">This project is about showing a landscape as a 3D object with lines outlining all surfaces.
Using the MinilbX library, this project goal is to get familiarized with tools to open windows, create images and deal with keyboard and mouse events. (Supported in Linux)
All in pure C programming language.  </p>

<p align="center">
  <a href="#Instructions">Instructions</a> &#xa0; | &#xa0;
  <a href="#Allowed_functions">Allowed functions</a> &#xa0; | &#xa0;
  <a href="#Screenshots">Screenshots</a> &#xa0; | &#xa0;
  <a href="#Features">Features</a> &#xa0; | &#xa0;
  <a href="#Installation">Installation</a> &#xa0; | &#xa0;
  <a href="#Deployment">Deployment</a> &#xa0; | &#xa0;
  <a href="#Resources">Resources</a> &#xa0; | &#xa0;
</p>

## Instructions


- This project mus be written in C
- It has to be written following the Norm of 42 schools
- The functions should not quit unexpectedly (segmentation fault, bus error, double free, etc)
- All heap memory allocation must be properly freed.
- The `Makefile` must at least contain the rules: `$(NAME)`, `all`, `clean`, `fclean` and `re`. And it should not relink.

## Allowed_functions

- `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `exit`
- All functions of the math library (-lm compiler option man man 3 math)
- All functions of the MiniLibX
- ft_printf and any equivalent

## Screenshots

<img width="850px" src=https://github.com/MemoCSales/42_FdF/blob/master/images/FdF-42.png alt="FdF"/>
<img width="850px" src=https://github.com/MemoCSales/42_FdF/blob/master/images/FdF-42-map.png alt="FdF-map"/>


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

## Resources

- [MinilibX Guide](https://harm-smits.github.io/42docs/libs/minilibx/introduction.html)
- [MinilibX Guide by Aurelien Brabant](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx)
- [Introduction of MinilibX by Oceano (youtube video)](https://www.youtube.com/watch?v=bYS93r6U0zg)

