
qsim: qsim.o
	gcc -g -o $@ $^

%.c: %.o
	gcc -std=c99 -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

