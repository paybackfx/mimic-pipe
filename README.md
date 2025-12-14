# mimic-pipe

## Description
mimic-pipe is a C project that replicates the behavior of the shell pipe operator (`|`). It allows for the redirection of standard input and output between commands, enabling the chaining of multiple commands where the output of one serves as the input for the next. This implementation supports standard piping, multiple consecutive pipes, and `here_doc` functionality.

## Prerequisites
- GCC or Clang compiler
- Make

## Compilation
To compile the project, run the following command in the root directory:

```sh
make
```

This will generate the `pipex` executable.

Other available Make targets:
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the executable.
- `make re`: Recompiles the project from scratch.

## Usage

### Standard Pipe
Behaves like `< file1 cmd1 | cmd2 > file2`.

```sh
./pipex file1 cmd1 cmd2 file2
```

**Example:**
```sh
./pipex infile "ls -l" "wc -l" outfile
```

### Multiple Pipes
Supports multiple commands chained together.
Behaves like `< file1 cmd1 | cmd2 | cmd3 ... | cmdN > file2`.

```sh
./pipex file1 cmd1 cmd2 cmd3 ... cmdN file2
```

**Example:**
```sh
./pipex infile "grep a" "sort" "uniq" "wc -l" outfile
```

### Here Doc
Supports `here_doc` functionality, behaving like `cmd1 << LIMITER | cmd2 >> file`.

```sh
./pipex here_doc LIMITER cmd1 cmd2 file
```

**Example:**
```sh
./pipex here_doc EOF "grep a" "wc -l" outfile
```

## Structure
- `pipex.c`: Main entry point and logic.
- `pipex_utils.c`, `pipex_utils_2.c`: Helper functions.
- `libfts/`: Custom library functions (Libft).
- `get_next_line_s/`: Implementation of `get_next_line` for reading input.
