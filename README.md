# pipex

## Description
This project reproduces the behavior of the shell pipe command `|` in C. It redirects the output of the first command to the input of the second command, handling file redirection and execution permissions.

## Structure
- **srcs/**: Main source files.
- **libft/**: Libft library sources.
- **gnl/**: Get Next Line sources.
- **includes/**: Header files.

## Prerequisites
- GCC compiler
- Make

## Compilation
To compile the project, simply run `make` at the root of the repository:
```bash
make
```
This will generate the `pipex` executable.

## Usage

### Standard Execution
The program is executed as follows:
```bash
./pipex file1 cmd1 cmd2 file2
```
This behaves exactly like the following shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

**Arguments:**
- `file1`: The input file.
- `cmd1`: The first command to execute.
- `cmd2`: The second command to execute.
- `file2`: The output file.

### Multiple Pipes
The program supports multiple commands:
```bash
./pipex file1 cmd1 cmd2 cmd3 ... cmdN file2
```
Behaves like:
```bash
< file1 cmd1 | cmd2 | cmd3 ... | cmdN > file2
```

### Here Doc
Support for `here_doc` is also included:
```bash
./pipex here_doc LIMITER cmd1 cmd2 file2
```
Behaves like:
```bash
cmd1 << LIMITER | cmd2 >> file2
```

## Cleaning
To remove object files and the executable, you can use:
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the executable.
- `make re`: Recompiles the project.
