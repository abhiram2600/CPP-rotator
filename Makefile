output: rotator.o ppm.o colorPixel.o pgm.o grayPixel.o
	g++ rotator.o ppm.o colorPixel.o pgm.o grayPixel.o -o rotator

rotator.o: rotator.cpp
	g++ -c rotator.cpp

ppm.o: ppm.cpp
	g++ -c ppm.cpp

colorPixel.o: colorPixel.cpp
	g++ -c colorPixel.cpp

pgm.o: pgm.cpp
	g++ -c pgm.cpp

grayPixel.o: grayPixel.cpp
	g++ -c grayPixel.cpp

clean:
	rm *.o rotator