#! /bin/sh

gcc "$@" -Linclude/minilibx/ -lmlx_Linux -Linclude/libft -lft -lXext -lX11 -lm -lz
#than run: chmod +x compiler.sh on terminal to make it executable
