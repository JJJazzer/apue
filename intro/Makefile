
CFLAGS = -ansi -lapue -D_GNU_SOURCE
PROGS =	ls1 ls2 copy1 copy2 hellopid \
	shell1 error getugid shell2

all:	$(PROGS)

%: %.c 
	$(CC)  $@.c $(CFLAGS) -o $@

clean:
	rm -f $(PROGS) *.o

