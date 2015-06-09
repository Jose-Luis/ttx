set makeprg=make\ -C\ /home/momia/Development/Builds/ttx/debug/
:command -nargs=* Make make <args> | cwindow 3
function Run()
    exec "silent !urxvt -e /home/momia/Development/Builds/ttx/debug/bin/TTX &"
endfunc
function Debug()
    exec "silent !urxvt -e cgdb /home/momia/Development/Builds/ttx/debug/bin/TTX &"
endfunc
map <F4> :Make<CR>
map <F5> :call Run()<CR>
map <F6> :call Debug()<CR>
