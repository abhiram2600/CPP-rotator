#ifndef Ppm_h
#define Ppm_h

#include <iostream>
#include <vector>
#include <string>
#include "colorPixel.h"
using namespace std;

class Ppm{

protected:
	int width, height, max, no_of_rotations;
	string magicNumber;
	vector<vector<ColorPixel>> rgb;
	
public:
	Ppm();
	Ppm(string fileName, int no_of_rotations);
	~Ppm();
	int getWidth();
	int getHeight();
	int getMax();
	vector<vector<ColorPixel>> getRGB();
	string getMagicNumber();
	void write(string filename, vector<vector<ColorPixel>> &arr);
};

#endif
