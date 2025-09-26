<!-- PROJECT LOGO -->

<br />
<div align="center">
  <h1>get_next_line</h1>
  <p align="center">
    Implementation of the 42 school project <b>get_next_line</b> in C  
    <br />
  </p>
</div>

<!-- TABLE OF CONTENTS -->

## Contents

* [About the Project](#about-the-project)
* [Implemented Functions](#implemented-functions)
* [Project Structure](#project-structure)
* [Build](#build)
* [Usage](#usage)
* [Example](#example)

## About the Project

The **get\_next\_line** project is part of the 42 school curriculum.
Its goal is to implement a function that reads a line from a file descriptor efficiently, handling multiple file descriptors simultaneously and supporting arbitrary buffer sizes.

This repository contains a C implementation of the project, including the mandatory and bonus parts.

## Implemented Functions

* **get\_next\_line(int fd)** – reads a line from the given file descriptor and returns it as a string.
* **get\_next\_line\_bonus(int fd)** – extended version handling multiple file descriptors.
* Helper functions for string manipulation (ft\_strlen, ft\_strchr, ft\_strdup, ft\_substr, ft\_strjoin, etc.).

## Project Structure

```
├── get_next_line.c          # Core function implementation
├── get_next_line.h          # Header file with prototypes
├── get_next_line_utils.c    # Utility functions (string operations)
├── get_next_line_bonus.c    # Bonus implementation (multi-fd support)
├── get_next_line_bonus.h
└──  get_next_line_utils_bonus.c
```

## Build

```sh
# Compile the mandatory part
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# Compile the bonus part
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```

## Usage

```sh
./gnl < testfile.txt
```

## Example

```c
int fd = open("example.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```
