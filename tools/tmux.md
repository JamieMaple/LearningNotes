# tmux

## install

mac: 

> brew install tmux

### cmd

1. `tmux -V` get version

2. `Ctrl - b` prefix, and can run tmux command

3. `Ctrl - b d` detach session, the detached session is still available

4. `tmux ls` get the tmux sessions

5. `tmux a[ttach-ssesion] -t {num|name}` attach the session number back or session name

6. `tmux new` add a tmux and default give the session id

7. `tmux new -s [name of session]` add tmux and set the name

8. `tmux kill-session -t [name]` kill tmux session

9. `tmux kil-server` kill tmux server along with all sessions

### manage panes

**To split panes, We need to be in the tmux**

1. `Ctrl - b "` split screen horizontally

2. `Ctrl - b %` split screen vertically

3. `Ctrl - b [arrow key]` move from panel to panel

4. `Ctrl - b :` resizing panes

5. `Ctrl - b :` and then `:resizing-pane -[D|U|L|R] [num]` reszing panel for down or up or left or right number of lines

