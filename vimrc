"设置文件编码
set encoding=utf-8
set fileencodings=utf-8
set termencoding=utf-8


let g:solarized_termcolors=256
"设置主题
syntax on
set background=dark
colorscheme onehalfdark
"常用主题onedark,xcodelight,xcodedark,xcodewwdc
"gotham,gotham256,solarized

set cursorline
"设置保持历史记录10000
set history=10000

"打开文件时禁止折叠
set nofoldenable
"按照语法高亮进行折叠
set fdm=indent

set display=lastline
" scrolloff控制光标上下的边距为多少时翻页，emmm，说的有点抽象，改改这个数字就很清楚了
set scrolloff=5
set matchtime=2
set matchpairs+=<:>
" 显示行号可以通过在命令行中设置:set nonumber关闭行号。要想永久关闭或者开启就要在vimrc中设置了
set number
set showcmd
set showmatch

" 设置文件不备份，这里被注释掉；
set nobackup
set noundofile
set noswapfile
"set backupext=.bak
"set backupdir=~/.vim/vim_bak/

"语法高亮
set syntax=on
" 去掉输入错误的提示声音
set noeb
" 在处理未保存或只读文件的时候，弹出确认
set confirm
" 自动缩进
set autoindent
set cindent

" 设置tab为四个空格空格代替Tab。空格比起制表符拥有更好的兼容性
" 注意: 插入模式下输入【ctrl+v+i】可以强制输入一个tab
" 针对已经存在的制表符，可以通过:%retab将制表符替换成四个空格
set tabstop=4     " tabstop 表示一个 tab 显示出来是多少个空格的长度，默认8
set softtabstop=4 " softtabstop 表示在编辑模式的时候按退格键的时候退回缩进的长度，当使用 expandtab 时特别有用
set expandtab     " 当设置成 expandtab 时，缩进用空格来表示，noexpandtab 则是用制表符表示一个缩进
set autoindent    " 自动缩进
set cindent       " 自动缩进补充
set shiftwidth=4  " 自动缩进空白字符个数
" 行尾部的空格会显示红色
highlight WhitespaceEOL ctermbg=red guibg=red
match WhitespaceEOL /\s\+$/

" 显示行号
set number
" 历史记录数
set history=1000
"禁止生成临时文件
set nobackup
set noswapfile
"搜索忽略大小写
set ignorecase

set incsearch

set autoread
set autowrite

" 鼠标定位
" 鼠标定位和鼠标拷贝似乎不能共存，按住shift再使用鼠标拷贝
set mouse=a

" 设置光标的形态
" 普通模式下为光标方块，插入模式下为竖线
let &t_SI.="\e[6 q" "SI = INSERT mode
let &t_SR.="\e[4 q" "SR = REPLACE mode
let &t_EI.="\e[1 q" "EI = NORMAL mode (ELSE)

" 设置光标颜色
highlight Cursor guifg=white guibg=white
highlight iCursor guifg=white guibg=white
set guicursor=n-v-c:block-Cursor
set guicursor+=i:ver100-iCursor
set guicursor+=n-v-c:blinkon0
set guicursor+=i:blinkwait10


" 垂直分割线颜色
" 就是分页的时候的那条分割线
hi VertSplit guibg=#31312D guifg=#526A83 ctermfg=White ctermbg=Black term=none cterm=none gui=none

"===============================================================
"powerline
set laststatus=2
let g:Powerline_symbols='unicode'

"===============================================================
"airline
" tabline，也就是上方的tab列表
let g:airline#extensions#tabline#enabled = 1
" 显示tab的分割
let g:airline#extensions#tabline#show_splits = 0
" 不显示buffer
let g:airline#extensions#tabline#show_buffers = 0
" tab的显示风格
let g:airline#extensions#tabline#alt_sep = 1
let g:airline#extensions#tabline#left_sep = ' '
" 不同tab的左间隔符
let g:airline#extensions#tabline#left_alt_sep = '◀'

let g:airline#extensions#tabline#tab_nr_type = 1 " tab number
let g:airline#extensions#tabline#show_tab_nr = 0

" let g:airline#extensions#tabline#formatter = 'default'
" 只显示文件名字
let g:airline#extensions#tabline#formatter = 'unique_tail'
" 超出长度显示...
let g:airline#extensions#tabline#overflow_marker = '…'
let g:airline_powerline_fonts = 1

" 关闭一堆不需要的
let g:airline#extensions#tabline#buffer_nr_show = 0
let g:airline#extensions#tabline#exclude_preview = 0
"if !exists('g:airline_symbols')
"  let g:airline_symbols = {}
"endif

" 设置主题

let g:airline#extensions#tabline#enabled = 1

let g:airline_left_sep = '▶'
let g:airline_left_alt_sep = '❯'
let g:airline_right_sep = '◀'
let g:airline_right_alt_sep = '❮'

"===========================================
set nocompatible              " 去除VI一致性,必须要添加
filetype off                  " 必须要添加

" 设置包括vundle和初始化相关的runtime path
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" 另一种选择, 指定一个vundle安装插件的路径
"call vundle#begin('~/some/path/here')

" 让vundle管理插件版本,必须
Plugin 'VundleVim/Vundle.vim'

" 以下范例用来支持不同格式的插件安装.
" 请将安装插件的命令放在vundle#begin和vundle#end之间.
" Github上的插件
" 格式为 Plugin '用户名/插件仓库名'
Plugin 'tpope/vim-fugitive'
" 来自 http://vim-scripts.org/vim/scripts.html 的插件
" Plugin '插件名称' 实际上是 Plugin 'vim-scripts/插件仓库名' 只是此处的用户名可以省略
" 由Git支持但不再github上的插件仓库 Plugin 'git clone 后面的地址'
Plugin 'git://git.wincent.com/command-t.git'
" 本地的Git仓库(例如自己的插件) Plugin 'file:///+本地插件仓库绝对路径'

" 正确指定路径用以设置runtimepath. 以下范例插件在sparkup/vim目录下
Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}

"代码检查
Plugin 'scrooloose/syntastic'

"文件树
Plugin 'scrooloose/nerdtree'

"NERDTree 配置:F2快捷键显示当前目录树
map <F3> :NERDTreeToggle<CR>
let NERDTreeWinSize=25

"状态栏优化
Plugin 'vim-airline/vim-airline'
"Plugin 'vim-airline/vim-airline-themes'

"彩虹括号
Plugin 'luochen1990/rainbow'
let g:rainbow_active = 1 "0 if you want to enable it later via :RainbowToggle


" 你的所有插件需要在下面这行之前
call vundle#end()            " 必须
filetype plugin indent on    " 必须 加载vim自带和插件相应的语法和文件类型相关脚本
" 忽视插件改变缩进,可以使用以下替代:
"filetype plugin on
"
" 常用的命令
" :PluginList       - 列出所有已配置的插件
" :PluginInstall  	 - 安装插件,追加 `!` 用以更新或使用 :PluginUpdate
" :PluginSearch foo - 搜索 foo ; 追加 `!` 清除本地缓存
" :PluginClean      - 清除未使用插件,需要确认; 追加 `!` 自动批准移除未使用插件
"
" 查阅 :h vundle 获取更多细节和wiki以及FAQ
" 将你自己对非插件片段放在这行之后

"======================================================================


"================================================================
"tagbar
"设置tagbar使用的ctags的插件,必须要设置对
let g:tagbar_ctags_bin='/usr/bin/ctags'
""设置tagbar的窗口宽度
let g:tagbar_width=35
"设置tagbar的窗口显示的位置,为右边
let g:tagbar_left=0
"打开文件自动 打开tagbar
"autocmd BufReadPost *.cpp,*.c,*.h,*.hpp,*.cc,*.cxx call tagbar#autoopen()
"映射tagbar的快捷键
map <F9> :TagbarToggle<CR>
" 设置焦点在tagbar
let g:tagbar_autofocus=1

"==============================================================
"nerdtree
"vim打开空文件时直接打开文件树
"autocmd StdinReadPre * let s:std_in=1
"autocmd VimEnter * if argc() == 0 && !exists("s:std_in") | NERDTree | endif

"vim打开文件夹时打开文件树
autocmd StdinReadPre * let s:std_in=1
autocmd VimEnter * if argc() == 1 && isdirectory(argv()[0]) && !exists("s:std_in") | exe 'NERDTree' argv()[0] | wincmd p | ene | exe 'cd '.argv()[0] | endif

autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTree") && b:NERDTree.isTabTree()) | q | endif

" 文件树列表显示在左侧
let g:NERDTreeWinPos="left"
" 宽度为30
let g:NERDTreeWinSize=30
" let g:NERDTreeShowLineNumbers=1
" let g:neocomplcache_enable_at_startup = 1

" NERDTress File highlighting
function! NERDTreeHighlightFile(extension, fg, bg, guifg, guibg)
        exec 'autocmd filetype nerdtree highlight ' . a:extension .' ctermbg='.a:bg .' ctermfg='. a:fg .' guibg='. a:guibg .' guifg='. a:guifg
        exec 'autocmd filetype nerdtree syn match ' . a:extension .' #^\s\+.*'.a:extension .'$#'
endfunction

" 根据文件类型不同做的颜色配置。配合nerdtree的配色插件还蛮多的，做出vscode那种效果也是完全可以做到的
call NERDTreeHighlightFile('cpp', 'blue', 'none', 'blue', '#151515')
call NERDTreeHighlightFile('cc', 'blue', 'none', 'blue', '#151515')
call NERDTreeHighlightFile('c', 'blue', 'none', 'blue', '#151515')
call NERDTreeHighlightFile('h', 'yellow', 'none', 'yellow', '#151515')
call NERDTreeHighlightFile('hpp', 'yellow', 'none', 'yellow', '#151515')
call NERDTreeHighlightFile('md', 'blue', 'none', '#3366FF', '#151515')
call NERDTreeHighlightFile('json', 'yellow', 'none', 'yellow', '#151515')
call NERDTreeHighlightFile('html', 'yellow', 'none', 'yellow', '#151515')
call NERDTreeHighlightFile('css', 'cyan', 'none', 'cyan', '#151515')
call NERDTreeHighlightFile('js', 'Red', 'none', '#ffa500', '#151515')
"======================================================================

"=====ycm
let g:ycm_global_ycm_extra_conf='~/.ycm_extra_conf.py'

let g:ycm_confirm_extra_conf = 0

"代码检查
" Syntastic config start
"syntastic
"设置error和warning的标志
let g:syntastic_enable_signs = 1
let g:syntastic_error_symbol='✗'
let g:syntastic_warning_symbol='►'
"总是打开Location List（相当于QuickFix）窗口，如果你发现syntastic因为与其他插件冲突而经常崩溃，将下面选项置0
let g:syntastic_always_populate_loc_list = 1
"自动打开Locaton List，默认值为2，表示发现错误时不自动打开，当修正以后没有再发现错误时自动关闭，置1表示自动打开自动关闭，0表示关闭自动打开和自动关闭，3表示自动打开，但不自动关闭
let g:syntastic_auto_loc_list = 1
"修改Locaton List窗口高度
let g:syntastic_loc_list_height = 5
"打开文件时自动进行检查
let g:syntastic_check_on_open = 1
"自动跳转到发现的第一个错误或警告处
let g:syntastic_auto_jump = 1
"进行实时检查，如果觉得卡顿，将下面的选项置为1
let g:syntastic_check_on_wq = 1
"高亮错误
let g:syntastic_enable_highlighting=1
"让syntastic支持C++11
let g:syntastic_cpp_compiler = 'clang++'
let g:syntastic_cpp_compiler_options = ' -std=c++11 -stdlib=libc++'
"设置pyflakes为默认的python语法检查工具
let g:syntastic_python_checkers = ['pyflakes']
"修复syntastic使用:lnext和:lprev出现的跳转问题，同时修改键盘映射使用sn和sp进行跳转
function! <SID>LocationPrevious()
  try
    lprev
  catch /^Vim\%((\a\+)\)\=:E553/
    llast
endtry
endfunction
function! <SID>LocationNext()
  try
    lnext
  catch /^Vim\%((\a\+)\)\=:E553/
    lfirst
endtry
endfunction
nnoremap <silent> <Plug>LocationPrevious    :<C-u>exe 'call <SID>LocationPrevious()'<CR>
nnoremap <silent> <Plug>LocationNext        :<C-u>exe 'call <SID>LocationNext()'<CR>
nmap <silent> sp    <Plug>LocationPrevious
nmap <silent> sn    <Plug>LocationNext
"关闭syntastic语法检查, 鼠标复制代码时用到, 防止把错误标志给复制了
nnoremap <silent> <Leader>ec :SyntasticToggleMode<CR>
function! ToggleErrors()
    let old_last_winnr = winnr('$')
    lclose
    if old_last_winnr == winnr('$')
        " Nothing was closed, open syntastic error location panel
        Errors
    endif
endfunction

" Syntastic config end
