src = "src"

all:
	gcc `pkg-config --cflags opencv`  histogramVideo.cpp $(src)/*.cpp -o run -lstdc++ `pkg-config --libs opencv`
clean:
	rm -r run