#ifndef GRAYPIXEL_H
#define GRAYPIXEL_H

#include <iostream>
using namespace std;

class GrayPixel {

private:
	int gray;
	
public:
	GrayPixel();
	GrayPixel(int g);
	~GrayPixel();
	int getGray();
};

#endif
