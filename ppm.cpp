#include "ppm.h"
#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
#include "colorPixel.h"
using namespace std;

Ppm::Ppm(string fileName, int no_of_rotations){
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

    if (magicNumber == "P3")
    {
		rgb  = vector<vector<ColorPixel>> (height, vector<ColorPixel>(width));	
		for(int i =0; i<height; i++){
			for(int j=0; j<width; j++){
				int r,g,b;
				fin >> r >> g >> b;
				rgb[i][j] = ColorPixel(r,g,b);
			}
		}
    }
    else if (magicNumber == "P6")
    {
		rgb  = vector<vector<ColorPixel>> (height, vector<ColorPixel>(width));
        fin.seekg(1, fin.cur);
		for(int i=0;i<height;i++)
		{
			for(int j=0;j<width;j++)
			{
				char * a = new char[3];
				fin.read(a,3);
				rgb[i][j] = ColorPixel((int)a[0],(int)a[1],(int)a[2]);
			}
		}
    }
};

void Ppm::write(string filename, vector<vector<ColorPixel>> &arr) {
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

	if(magicNumber == "P3"){
		for (int i = 0; i < height_w; i ++)
		{
			for (int j = 0; j < width_w; j ++)
			{
				outfile << arr[i][j].getRed() << "\n" << arr[i][j].getGreen() << "\n" << arr[i][j].getBlue() << "\n";
			}
			outfile << "\n";
		}
	}
	else if(magicNumber == "P6")
	{
		for (int i = 0; i < height_w; i ++)
		{
			for (int j = 0; j < width_w; j ++)
			{
				char* c = new char[3];
				c[0] = (char)arr[i][j].getRed();
				c[1] = (char)arr[i][j].getGreen();
				c[2] = (char)arr[i][j].getBlue();
				outfile.write(c,3);
			}

		}
	}
    return;
}

Ppm::~Ppm(){
	rgb.clear();
};

int Ppm::getWidth(){
	return width;
}

int Ppm::getHeight(){
	return height;
}

int Ppm::getMax(){
	return max;
}

string Ppm::getMagicNumber(){
	return magicNumber;
}

vector<vector<ColorPixel>> Ppm::getRGB(){
	return rgb;
}


