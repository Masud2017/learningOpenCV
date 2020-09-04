src = "src"

all:
	gcc `pkg-config --cflags opencv`  histogram.cpp $(src)/*.cpp -o run -lstdc++ `pkg-config --libs opencv`
clean:
	rm -r run