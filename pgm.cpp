#include "pgm.h"
#include <iostream>
#include <vector>
#include <fstream>
#include "grayPixel.h"
using namespace std;

Pgm::Pgm(string fileName, int no_of_rotations){
	ifstream fin(fileName, ifstream::binary);
	if(!fin.is_open())
	{
		cerr<<"Failed to open file";
		return;
	}
	fin>> magicNumber;
	fin.seekg(1,fin.cur);
	char c;
	fin.get(c);
	if (c == '#')
    {
        while (c != '\n')
        {
            fin.get(c);
        }
    }
    else
    {
        fin.seekg(-1, fin.cur);
    }
    
    fin >> width >> height >> max;
	this->no_of_rotations = no_of_rotations;

	if(magicNumber == "P2") {
		grayScale = vector<vector<GrayPixel>> (height, vector<GrayPixel>(width));
		
		for(int i =0; i<height; i++){
			for(int j=0; j<width; j++){
				int g;
				fin >> g;
				GrayPixel gray(g);
				grayScale[i][j] = gray;
			}
		}
	}
	else{
		grayScale = vector<vector<GrayPixel>> (height, vector<GrayPixel>(width));

		fin.seekg(1, fin.cur);
		for(int i =0; i<height; i++){
			for(int j=0; j<width; j++){
				char* a = new char[1];
				fin.read(a,1);
				grayScale[i][j] = GrayPixel((int)a[0]);
			}
		}
	}
};

void Pgm::write(string filename, vector<vector<GrayPixel>> &arr) {
	ofstream outfile(filename, ofstream::binary);
    if (outfile.fail())
    {
        std::cout << "Failed to write " << endl;
        return;
    }

	int width_w = width, height_w = height;
	if(this->no_of_rotations & 1)
	{	
		width_w = height;
		height_w = width;
	}
	
	outfile << magicNumber << "\n" << width_w << " " << height_w << "\n" << max << "\n";

	if(magicNumber == "P2")
	{
	for (int i = 0; i < height_w; i ++)
	{
		for (int j = 0; j < width_w; j ++)
		{
			outfile << arr[i][j].getGray() << "\n";
		}
		outfile << "\n";
	}
	}
	else {
		for(int i=0;i<height_w;i++)
		{
			for(int j=0;j<width_w;j++)
			{
				char* c = new char[1];
				c[0] = (char)arr[i][j].getGray();
				outfile.write(c,1);
			}
		}
	}
    return;
}


Pgm::~Pgm(){
	grayScale.clear();
};

int Pgm::getWidth(){
	return width;
}

int Pgm::getHeight(){
	return height;
}

int Pgm::getMax(){
	return max;
}

string Pgm::getMagicNumber(){
	return magicNumber;
}

vector<vector<GrayPixel>> Pgm::getGray(){
	return grayScale;
}


