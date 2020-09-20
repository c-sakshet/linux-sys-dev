compile:
	gcc -o exec code.c ../../tlpi-dist/lib/error_functions.o

clean:
	rm exec

run:
	@./exec ${ARGS} & echo "Makefile run usage:    make ARGS = \"<filename>\" run "
help:
	@echo "Usage:    make ARGS = \"<filename>\" run "