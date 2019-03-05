# VimScript hard way

> use `:h[elp] <command>`

### echo

`:echo 'Hello, World'`

`echom[essage]` with `messages`

### comments

### setting options

`:set <option>`

1. boolean

   `:set <option>` turn on, `:set no<option>` turn off

   toggling options: `:set <option>!`

   checking options: `:set <option>?`

2. values

   `:set <option>=<value>`

### mapping keys

1. `:map <target> <old>` can also map keys in visual mode 
1. `:nmap` only in normal mod

1. `:vmap` only in visual mod

1. `:imap` only in insert mod

1. `:nunmap` remove map key

1. `noremap` will never recursing

### leaders

1. `:let mapleader = "-"`

1. `<leader>`

1. local leader `<localleader>`

### Editing vimrc

1. `$MYVIMRC`

1. `source`

### Abbreviations

1. `iabbrev`

1. `iskeyword`

### More way to exit insert mode

1. `<esc>`

1. `<c-c>`

1. `<c-[>`

### Buffer-Local Options and Mappings

1. `map-local` and `:map <buffer> <leader>x xx`

1. `setlocal` set locally

1. `local-options`

### Autocommand

1. `:autocmd [event] [pattern] [command to run]`


