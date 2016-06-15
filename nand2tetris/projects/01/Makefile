.PHONY: all
all: $(wildcard *.hdl)
	@grep DONE $^
	@for i in $^; do if ! grep -q  DONE $$i; then echo $$i; fi; done

.PHONY: echo
echo:
	@echo '// DONE - Joby Poriyath'

.PHONY: clean
clean:
	@rm -vf *~ *.out
