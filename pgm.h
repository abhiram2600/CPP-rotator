#ifndef PGM_H
#define PGM_H

#include <iostream>
#include <vector>
#include <string>
#include "grayPixel.h"
using namespace std;

class Pgm{

protected:
	int width, height, max, no_of_rotations;
	string magicNumber;
	vector<vector<GrayPixel>> grayScale;
	
public:
	Pgm();
	Pgm(string fileName,int no_of_rotations);
	~Pgm();
	int getWidth();
	int getHeight();
	int getMax();
	vector<vector<GrayPixel>> getGray();
	string getMagicNumber();
	void write(string filename, vector<vector<GrayPixel>> &arr);
};

#endif
