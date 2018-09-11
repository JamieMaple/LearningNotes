# `fish` 学习笔记

### Quotes: `'` 和 `"`

> When using double quoted string, `variable expansion` still takes place.
> Other than that, no other kind of expansion (including brace expansion and parameter expansion).

### Escape

### IO redirection

> Most programs use three input/output streams, each represented by a number called a file descriptor (fd).

These are:
- Standard Input,  FD 0
- Standard Output, FD 1
- Standard Error,  FD 2

The reason for two output file descriptors is to allow separation of errors and warnings from regular program output.

- read standard input from a file: `< source_file`
- write standard error to a file: `> destination`
- append standard output to a file: `^ destination`
- append standard error to a file: `^^ destination`
- not overwrite an existing file: `>? destination` `^? destination`

`destination` can be :

- `filename`
- ampersand (&) followed by the number of anohter file descriptor.
- ampersand followed by a minus sign (&-).The file descriptor will be closed.

### Piping

> The user can string together multiple commands into a so called pipeline

pip character `|`

use a different output file descriptor by prepending the desired FD numbers

`make fish 2>| less`

### Background jobs

to create a background job, append an & (ampersand) to your command. `emacs &`

### Job Control

`Ctrl + z` can return control to fish

and then can using `fg` (foreground) go back

`jobs` can get curently started jobs

### Functions

``` fish
function ll
    ls -l $argv
end
```

definition of ll, can use with the argument '-l',
and the `$argv` should be called when ll is invoked,
`$argv` is an array variable


### Variable expansion

`$` with a string of characters

### Variable Scope

``` fish
begin
    set -l pirate 'There be treasure in them thar hills'
end
```

variable scope for functions, all current local variables temporarily disappear.

### Some Special Variables

### Some Status Variables

### Vim mode

### Copy and paste

### searchable history



