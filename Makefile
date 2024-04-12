# simple makefile
# create link for opposite
all:
	gcc -O0 -g qw2dv.c -o qw2dv
	ln -sf qw2dv dv2qw
