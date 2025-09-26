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
* [Usage](#usage)

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
└── get_next_line_utils_bonus.c
```
## Usage

To use this function, simply include the headers and call get_next_line in your program. For a `main.c`, here an example

#### Example

```c
#include "get_next_line.h"

main() {

  char *line;

  while ((line = get_next_line(STDIN_FILENO)) != NULL)
  {
      printf("%s", line);
      free(line);
  }
  close(fd);
  return(0);
}
```

In order to build this add your wished BUFFER_SIZE as a flag. You can also add flags like -Wall -Wextra -Werror for extra security. 

```sh
# Compile the mandatory part
cc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl

# Compile the bonus part
cc -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o gnl_bonus
```
Then you can run the program as following:

```sh
./gnl < testfile.txt
```


