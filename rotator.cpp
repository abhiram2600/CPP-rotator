#include <iostream>
#include <string>
#include "rotator.h"
#include "ppm.h"
#include "pgm.h"
using namespace std;

Rotator *Rotator::instance = 0;


int main(int argc, char* argv[]) {
    if(argc != 5)
    {
        cerr<<"Four command line parameters needed."<<endl
            <<"Enter it in the form: input_image_name output_image_name -r(right)(or)-l(left) degree"<<endl
            <<"Ex:- ./rotator chips.ppm chips2.ppm -r 90"<<endl;
        return 0;
    }
    Rotator *rotator = rotator->getInstance();
    string ip_fname(argv[1]);
    string extension = ip_fname.substr(ip_fname.size()-3);
    rotator->setInputFileName(string(argv[1]));
    rotator->setOutputFileName(string(argv[2]));
    rotator->setDirection(string(argv[3]));
    rotator->setDegress(stoi(argv[4]));
    rotator->rotateImage(extension);
}