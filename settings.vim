set makeprg=make\ -C\ /home/momia/Development/Builds/ttx/debug/
:command -nargs=* Make make <args> | cwindow 3
map <F5> :Make<CR><C-w><Up>
