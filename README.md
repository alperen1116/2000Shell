# 2Shell

A small Linux shell written in C. Built for learning, one step at a time.

> **Status: early development (v0.1).** 2Shell is not ready to be used as a default login shell. Run it from inside bash instead.

## Features

- Interactive prompt that shows the current directory (`2Shell:~/Projects> `)
- Colored prompt, with the home directory shortened to `~`
- Runs any program on your system (`ls`, `cat`, `grep`, ...) using `fork` and `execvp`
- Built-in commands: `cd`, `help`, `exit`
- Clear error messages (`command not found`, `No such file or directory`, ...)
- `Ctrl+D` exits the shell

## Requirements

- Linux
- `gcc` and `make` (on Debian/Ubuntu: `sudo apt install build-essential`)

## Build from source

```
git clone https://github.com/YOUR-USERNAME/2shell.git
cd 2shell
gcc -Wall -o 2sh 2sh.c
./2sh
```

## Install (Debian / Ubuntu)

Download the latest `.deb` file from the Releases page, then:

```
sudo dpkg -i 2shell_0.1_amd64.deb
2sh
```

To remove it:

```
sudo apt remove 2shell
```

### Build the .deb yourself

```
chmod +x build-deb.sh
./build-deb.sh
```

This compiles the program and creates `2shell_<version>_<arch>.deb` in the project folder. The binary is installed to `/usr/bin/2sh`.

## Usage

```
$ 2sh
2Shell 0.1 - type 'help' for help
2Shell:~> ls -l
2Shell:~> cd /tmp
2Shell:/tmp> exit
```

| Command | What it does |
|---------|--------------|
| `cd [dir]` | Change directory. Without an argument, goes to your home directory. |
| `help` | Show the built-in commands. |
| `exit` | Leave the shell. |

## Known limitations

2Shell is a learning project and does not replace bash yet. Not supported at the moment:

- Redirection (`>`, `<`) and pipes (`|`)
- Wildcards (`*.c`), variables (`$HOME`) and `~` expansion
- Quotes (`"my file.txt"`)
- `Ctrl+C` handling, command history and Tab completion
- Running `.sh` scripts

## Roadmap

- [x] Read-eval loop
- [x] Split input into words
- [x] Run commands (`fork` / `execvp` / `waitpid`)
- [x] Built-in `cd`, `help`, `exit`
- [x] Prompt with current directory
- [x] Debian package
- [ ] Signal handling (`Ctrl+C`)
- [ ] Redirection (`>`, `<`)
- [ ] Pipes (`|`)
- [ ] Quotes, variables and `~`
- [ ] History and Tab completion

## Project layout

```
2sh.c          the shell source code
build-deb.sh   script that builds the .deb package
README.md      this file
```

## Contributing

Issues and suggestions are welcome. This project is mainly for learning, so clear and simple code is preferred over clever code.

## License

Not chosen yet. Add a `LICENSE` file before publishing (MIT or GPL-3.0 are common choices).

## Author

Alperen
