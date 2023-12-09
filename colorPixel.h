#ifndef COLORPIXEL_H
#define COLORPIXEL_H

#include <iostream>
using namespace std;

class ColorPixel {

private:
	int red, green, blue;
	
public:
	ColorPixel();
	ColorPixel(int r, int y, int z);
	~ColorPixel();
	int getRed();
	int getGreen();
	int getBlue();
};

#endif
