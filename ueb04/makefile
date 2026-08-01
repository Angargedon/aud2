cc = gcc -Wall
prg = main
obj = main.o tools.o datetime.o menu.o teams.o database.o
CFLAGS += -O0 -g3



$(prg): $(obj)
	@$(cc) -O0 -g3 -o $@ $^

main.o: main.c
	@$(cc) -O0 -g3 -c $<

tools.o: tools.c
	@$(cc) -O0 -g3 -c $<

datetime.o: datetime.c datastructure.h
	@$(cc) -O0 -g3 -c $<

menu.o: menu.c tools.h
	@$(cc) -O0 -g3 -c $<

teams.o: teams.c datastructure.h tools.h datetime.h
	@$(cc) -O0 -g3 -c $<

database.o: database.c tools.h datastructure.h datetime.h
	@$(cc) -O0 -g3 -c $<
	
clean:
	@rm -f $(prg) $(obj)

run:
	@./$(prg)

all: clean $(prg) run