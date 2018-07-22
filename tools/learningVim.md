# Vim learning

### lesson 1.1

use `h` `j` `k` `l`

### lesson 1.2

exit without save anything: `esc` + `:q!`

### lesson 1.3

delete char: `x`

### lesson 1.4

insert before mode: `i`

### lesson 1.5

insert after mode: `a`

### lesson 2.1

delete a word: `dw`

### lesson 2.2

more deletions:
    delete the end of line: `d$`
    
### lesson 2.3

delete operators: `d`

motions:
    until the start of the next word: w
    to the end of the current word: e
    to the end of the line: $

NOTE: Pressing justing the motion while in Normal mode without an operator will move to the cursor as specified.

foramt for change command:
		operator   [number]   motion
	where:
	  operator - is what to do
	  [number] - is an optional count to repeat the motion
	  motion   - moves over the text to operate

### lesson 2.4

using numbers with motions:
     0         --> start of the line
     non-zeoro --> times

### lesson 2.5

using numbers to delete:
    like `d2w` `d3e`

### lesson 2.6

delete a line: `dd`

also can with numbers, like: `2dd`

### lesson 2.7

undo command: `u`

fix a whole line: `U`

undo the undo commands: `ctrl+u`


### lesson 3.1

put previously deleted text after the cursor: `p`

### lesson 3.2

replace a char with `e`: `re`

### lesson 3.3

deletes the word and places insert mode: `ce`

### lesson 3.4

change format:  `c  [number]  motion`

### lesson 4.1

show location in the file and the status: `ctrl-G`

move to the bottom: `G`

move to that lin number: `[number] G`

move to the start: `gg`

### lesson 4.2

search with `/{parse}`

`n` to go on
`N` to go back

with backward direction: `?` instead of `/`

go back older positions: `ctrl-O`
go newer positions: `ctrl-I`

### lesson 4.3

matching parentheses search: `%`

### lesson 4.4

substitue `:s/old/new/g` substitute 'new' for 'old'

change every occurrence of a character string between two lines
  `:#, #s/old/new/g` range of [#, #]
  `:%s/old/new/g`    change every occurrence in the whole file
  `:%s/old/new/gc`   find every occurrence in the whole file with prompt

### lesson 5.1

execute an external command: `!`

### lesson 5.2

save file: `:w FILENAME`

### lesson 5.3

visual mode: `v`

then use an operator

### lesson 5.4

retrieves the content of a file: `r`

can also read the output of an external command

### lesson 6.1

open a line below the cursor and place in insert mode: `o`

open a line about the cursor and place in insert mode: `O`

### lesson 6.2

insert on the end of line and place in insert mode: `A`

### lesson 6.3

replace mode: `R`

### lesson 6.4

copy (yank): `y`

paste:       `p`

copy can use as an operator

### lesson 6.5

set options

set ignore case: `:set ic`

set 'hlsearch' and 'incsearch': `:set hls is`
(high-light search)

disable ignore case: `:set noic`

disable hlsearch(high-light): `:nohlsearch`

**prepend "no" to switch an option off**


### lesson 7.1

get help:
    - press <HELP>
    - press <F1>
    - type :help <Enter>

jumb one to one widow
`ctrl-W` `ctrl-W`

### lesson 7.2

enable some vim feathers with `vimrc`

### lesson 7.3

command line completion

show a list of commands `ctrl+D`

and `tab` can complete








