CC=g++
CFLAGS=-O2 -g `pkg-config --cflags opencv` -std=c++11
LDFLAGS=`pkg-config --libs opencv`
BIN = ex3

HelloCV : Noise.cpp
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(BIN) Noise.cpp
