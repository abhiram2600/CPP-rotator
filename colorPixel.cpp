#include "colorPixel.h"
#include <iostream>
using namespace std;

ColorPixel::ColorPixel(){
	this->red=0;
	this->green=0;
	this->blue=0;
}

ColorPixel::ColorPixel(int r, int g, int b){
	this->red = r;
	this->green = g;
	this->blue = b;
}

ColorPixel::~ColorPixel(){}

int ColorPixel::getRed(){
	return red;
}

int ColorPixel::getGreen(){
	return green;
}

int ColorPixel::getBlue(){
	return blue;
}


