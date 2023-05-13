" allow per-project .vimrc files,
" but don't let them do anything too weird
set exrc
set secure

" don't create a bunch of temp files
set nobackup
set nowritebackup
set noswapfile

" always show the filename on the status line
set laststatus=2
set statusline+=%F

" set up pathogen for package management
"execute pathogen#infect()

" enable the file explorer
set nocompatible
filetype plugin on

" reload .vimrc
map <C-w>r :source ~/.vimrc<CR>

" enable syntax highlighting
syntax on

" set line wrapping on
set wrap

" knock off some stoopid auto-comment crap
au FileType * setlocal formatoptions-=c formatoptions-=r formatoptions-=o
set smartindent

" undo/redo
nnoremap u :undo<CR>
nnoremap U :redo<CR>

" stop removing indentation from comments in python
inoremap # X<c-h>#

" make line changes apply to display lines, not real lines
nnoremap k gk
nnoremap gk k
nnoremap j gj
nnoremap gj j
map <Up> k
map <Down> j

" e to move forward, E to move backward
nnoremap E b

" toggle virtual edit mode
nnoremap <C-w>v :set virtualedit=all<CR>
nnoremap <C-w>V :set virtualedit=<CR>

" always show the cursor position
set ruler

" show line numbers
set number
set numberwidth=5

" toggle line numbers
nnoremap <C-w>n :set number!<CR>

" set behavior of tab completion
set wildmode=longest,list

" show incomplete commands
set showcmd

" managing splits
set splitbelow
set splitright

" cycling through buffers
nnoremap <silent> [b :bprevious<CR>
nnoremap <silent> ]b :bnext<CR>
nnoremap <silent> [B :bfirst<CR>
nnoremap <silent> ]B :blast<CR>
nmap     <silent> <C-w>' :bnext<CR>
nmap     <silent> <C-w>; :bprevious<CR>
 
" cycling through tabs
nmap <silent> [t gT
nmap <silent> ]t gt
nmap <silent> <C-w>t <C-w>T
nmap <silent> <C-w>[ gT
nmap <silent> <C-w>] gt

" allow cycling of unsaved buffers without a bang(!)
set hidden

" make window management a lot like what I use for tmux
nnoremap <silent> <C-w><Bslash> :vsplit<CR>
nnoremap <silent> <C-w>- :split<CR>
nnoremap <silent> <C-w>z <C-w>\|<C-w>_

" create new tabs
nmap <silent> <C-w>t :tabe<CR>
"" C-w T

" clang_complete
" let g:clang_library_path='/Library/Developer/CommandLineTools/usr/lib/libclang.dylib'

" tabs and spaces
set tabstop     =2
set softtabstop =2
set shiftwidth  =2
set expandtab

" toggle line wrapping
nnoremap <silent> <C-w>w :set wrap!<CR>

" show specific line widths
"set colorcolumn=80
"highlight ColorColumn ctermbg=darkgrey

" color theme
"color my_invisibles
"color elflord
color default

" show invisibles
nmap <leader>l :set list!<CR>

set encoding=utf-8
set listchars=tab:»\ ,trail:·,nbsp:·,eol:¬
set list

" toggle invisibles
nnoremap <C-w>i :set list!<CR>

