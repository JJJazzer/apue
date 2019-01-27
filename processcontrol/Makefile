
CFLAGS = -ansi -lapue -D_GNU_SOURCE
PROGS  = forkvar prexit zombie complete

all:	$(PROGS)

%: %.c 
	$(CC)  $@.c $(CFLAGS) -o $@

clean:
	rm -f $(PROGS) *.o

