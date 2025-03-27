# minishell

`minishell` is a fully functional shell built in C as part of the 42 School curriculum.  
It supports interactive user input, command parsing, redirections, pipes, environment variables, and built-in commands — all while handling signals and memory properly.

---

## Project Goal

Rebuild a simplified version of `bash`, allowing the user to:
- Run commands
- Chain them with pipes
- Redirect input/output
- Use environment variables
- Handle signals (like `CTRL+C`)
- Execute built-in functions like `cd`, `echo`, etc.

> The main challenge: **no system() or exec() wrappers — only `fork`, `execve`, `pipe`, `dup2`, etc.**

---

## Key Concepts

- Lexing & Parsing (custom tokenizer)
- Abstract Syntax Trees (AST)
- File descriptors, pipes, redirections
- Built-in commands vs binary execution
- Environment variable management
- Signals (`SIGINT`, `SIGQUIT`)
- Memory management & garbage-free runtime

---

## Supported Features

| Feature                  | Supported |
|--------------------------|-----------|
| Basic commands           | ✅        |
| Arguments & quotes       | ✅        |
| Pipes (`|`)              | ✅        |
| Input `<` and output `>` | ✅        |
| Heredoc `<<`             | ✅        |
| Append `>>`              | ✅        |
| Environment variables    | ✅        |
| Built-in commands        | ✅        |
| Signal handling          | ✅        |
| Exit codes               | ✅        |

---

## Built-in Commands

- `echo`
- `cd`
- `pwd`
- `export`
- `unset`
- `env`
- `exit`
```bash
git clone https://github.com/NathanSouchal/minishell.git
cd minishell
make
