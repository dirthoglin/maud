#compiler
CC=gcc
CFLAGS=-I. -Wall -std=c99
OUTBIN=maud

# subdirectory for objects
O=linux

# not too sophisticated dependency
OBJS=	$(O)/i_main.o 	\
			$(O)/d_main.o 	\
			$(O)/l_converter.o


all:	 $(O)/$(OUTBIN)

clean:
	rm -f *.o *~
	rm -f linux/*

$(O)/$(OUTBIN):	$(OBJS) $(O)/i_main.o
	$(CC) $(CFLAGS) $(OBJS) -o $(O)/$(OUTBIN)

$(O)/%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@