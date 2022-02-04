[![42](https://img.shields.io/badge/BornToCode-2_Circle-00babc?style=flat-square&logo=42)](https://42lausanne.ch/)

[![last-commit](https://img.shields.io/github/last-commit/MateyN/so_long?style=flat-square)](https://github.com/MateyN/so_long)

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
[![forthebadge](https://forthebadge.com/images/badges/built-with-love.svg)](https://forthebadge.com)
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li><a href="#summary">Summary</a></li>
    <li><a href="#project-structure">Project Structure</a></li>
    <li><a href="#environment">Environment</a></li>
    <li><a href="#installation">Compile</a></li>
    <ul>
        <li><a href="#mandatory">Mandatory</a></li>
	</ul>
	<li><a href="#execute">Execute</a></li>
    <ul>
        <li><a href="#controls">Controls</a></li>
	</ul>
	<li><a href="#example">Example</a></li>
	<li><a href="#links">Links</a></li>
  </ol>
</details>

# So Long

_And thanks for all the fish!_

This project is a small 2D game with `MinilibX`. You'll learn about textures, sprites and tiles.

## Summary

This project is a very small 2D game. It is built to make you work with
textures, sprites. And some very basic gameplay elements.

|                      |                                                                                                                                     |
| -------------------- | ----------------------------------------------------------------------------------------------------------------------------------  |
| **Program name**     | `so_long`                                                                                                                           |
| **Turn in files**    | `Makefile, *.h, *.c, maps`                                                                                                          |
| **Makefile**         | `NAME`, `all`, `clean`, `fclean`, `re`                                                                                              |
| **Arguments**        | a map in format `*.ber`                                                                                                             |
| **External functs.** | - `open`, `close`, `read`, `write`, `printf`, `malloc`, `free`, `perror`, `strerror`, `exit` <br> - All functions of the `MinilibX` |
| **Libft authorized** | Yes                                                                                                                                 |
| **Description**      | a small 2D game where a player escapes map after eating some collects before leaving the place.                                     |

## Project Structure

```shell
./
├── libs		  # libraries: mlx (MinilibX), get_next_line
├── includes 	          # C header files
├── srcs                  # C source files
├── image		  # game assets
├── maps		  # game maps
├── Makefile
└── README.md
```

## Environment

- MacOS 12.0.1 (Monterey, Intel)

Developed and tested in this environment.

## Compile

### Mandatory

To compile the mandatory version, run the lines below.

```shell
$ git clone https://github.com/MateyN/so_long
$ make
```

## Execute

Run compiled executable file in the root folder.

```shell
$ ./so_long [map_filename]

# example
$ ./so_long maps/map.ber
```

### Controls

- `ESC` to exit a game
- `WASD` to move

## Example

![capture](https://github.com/MateyN/so_long/blob/master/so_long/maps/example.png)

## Links

- [Subject] (https://github.com/MateyN/so_long/blob/master/so_long/en.subject.pdf)
- [Draw sprites] (https://www.pixilart.com)
