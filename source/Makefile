#compiler
CC=gcc
CFLAGS=-I. -Wall -std=c99
OUTBIN=maud
LIBS=-lm -lncurses

# subdirectory for objects
O=obj

# not too sophisticated dependency
OBJS=	$(O)/i_main.o 	\
			$(O)/d_main.o 	\
			$(O)/l_converter.o


all:	 $(O)/$(OUTBIN)

clean:
	rm *.o *~ obj/*

$(O)/$(OUTBIN):	$(OBJS) $(O)/i_main.o
	$(CC) $(CFLAGS) $(OBJS) -o $(O)/$(OUTBIN) $(LIBS)

$(O)/%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@