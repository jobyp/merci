.PHONY: all
all:
	verilator -Wall --cc simple_in_n_out.v -exe main.cc
	cd obj_dir && make -f Vsimple_in_n_out.mk Vsimple_in_n_out

.PHONY: clean
clean:
	rm -rvf obj_dir *~

