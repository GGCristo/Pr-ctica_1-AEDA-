all:
	g++ src/main.cpp -o bin/main
run:
	./bin/main
debug:
	g++ -g src/main.cpp -o bin/main
test:
	g++ test/test.cpp -o bin/test
	./bin/test
clean:
	rm bin/*
