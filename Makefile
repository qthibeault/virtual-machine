all:
	mkdir -p bin
	clang -o bin/vm src/main.c

clean:
	rm -r bin
