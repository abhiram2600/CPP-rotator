#include "grayPixel.h"
#include <iostream>

GrayPixel::GrayPixel(){
	this->gray=0;
}

GrayPixel::GrayPixel(int g){
	this->gray = g;
}

GrayPixel::~GrayPixel(){}

int GrayPixel::getGray(){
	return gray;
}



