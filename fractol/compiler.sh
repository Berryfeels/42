#! /bin/sh

gcc "$@" -lXext -lX11 -lm -lz -Lmlx_linux -lmlx_Linux -lX11 -lXext -Lminilibx
#than run: chmod +x compiler.sh on terminal to make it executable
