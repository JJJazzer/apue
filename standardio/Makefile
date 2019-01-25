
CFLAGS = -ansi -lapue -D_GNU_SOURCE
PROGS  = copy1 copy2 fread printf tmpnam mktemp

all:	$(PROGS)

%: %.c 
	$(CC)  $@.c $(CFLAGS) -o $@

clean:
	rm -f $(PROGS) *.o

