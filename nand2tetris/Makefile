.PHONY: all
all: check_hdl_src hw
	@:

.PHONY: check_hdl_src
check_hdl_src: $(wildcard *.hdl)
	@grep DONE $^
	@for i in $^; do if ! grep -q  DONE $$i; then echo $$i; fi; done
	@echo

hw: chips.o hw.o
	gcc -Wall -std=c11 -o $@ $^

hw.o : chips.h
chips.o : chips.h

%.o : %.c
	gcc -Wall -std=c11 -c $< -o $@

.PHONY: echo
echo:
	@echo '// DONE - Joby Poriyath'

.PHONY: clean
clean:
	@rm -vf *~ *.out hw *.o
