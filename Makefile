src = "src"

all:
	gcc `pkg-config --cflags opencv`  splitandmerging.cpp $(src)/*.cpp -o run -lstdc++ `pkg-config --libs opencv`
clean:
	rm -r run