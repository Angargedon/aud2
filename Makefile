prg = test
obj = test.o dlist.o tools.o
CFLAGS += -O0 -g3

$(prg): $(obj)
	@gcc -O0 -g3 -o $@ $^

test.o: test.c dlist.h
	@gcc -O0 -g3 -c $<

dlist.o: dlist.c tools.h
	@gcc -O0 -g3 -c $<

tools.o: tools.c
	@gcc -O0 -g3 -c $<

clean:
	@rm -f prg obj

run:
	@./$(prg)

all: clean $(prg) run