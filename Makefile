all:
	dummy target

encode:
	g++ src/encode.cpp src/huffman.cpp -o bin/main
	bin/main.exe db/input.txt db/comp.bin

decode:
	g++ src/decode.cpp src/huffman.cpp -o bin/main
	bin/main.exe db/comp.bin db/output.txt
