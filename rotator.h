#ifndef ROTATOR_H
#define ROTATOR_H

#include <iostream>
#include <string>
#include "ppm.h"
#include "pgm.h"
using namespace std;

class Rotator{
    private:
        static Rotator* instance;
        string inputFileName;
        string outputFileName;
        string direction;
        int degrees;

        Rotator(){
        }

    public: 

        Rotator(const Rotator&) = delete;

        static Rotator* getInstance() {
            if(!instance) instance = new Rotator;
            return instance;
        }

        string getInputFileName() { return this->inputFileName; }
        string getOutputFileName() { return this->outputFileName; }
        string getdirection() { return this->direction; }
        int getDegrees() { return this->degrees; }

        void setInputFileName(string inputFileName) { this->inputFileName = inputFileName; }
        void setOutputFileName(string outputFileName) {this->outputFileName = outputFileName; }
        void setDirection(string direction) { this->direction = direction; }
        void setDegress(int degrees) { this->degrees = degrees; }

        template <typename T>
        void rotate2dArray(vector<vector<T>> &rgb){
            vector<vector<T>> rotated;
            for (size_t i = 0; i < rgb[0].size(); i++) {
                vector<T> newRow;
                for (int j = rgb.size() - 1; j >=0; j--) {
                    newRow.push_back(rgb[j][i]);
                }
            rotated.push_back(newRow);
            }
            rgb = rotated;
        }

        void rotatePGM(int no_of_rotations) {
            Pgm ob(this->inputFileName, no_of_rotations);
            vector<vector<GrayPixel>> modified_arr = ob.getGray();
            for(int i=0;i<no_of_rotations;i++){
                rotate2dArray(modified_arr);
            }
            ob.write(this->outputFileName,modified_arr);
        }

        void rotatePPM(int no_of_rotations) {
            Ppm ob(this->inputFileName, no_of_rotations);
            vector<vector<ColorPixel>> modified_arr = ob.getRGB();
             for(int i=0;i<no_of_rotations;i++){
                 rotate2dArray<ColorPixel>(modified_arr);
             }
             ob.write(this->outputFileName,modified_arr);
        }

        void rotateImage(string extension){
            int no_of_rotations = int(degrees/90);
            if(direction=="-l")
            {
                if(no_of_rotations==1)
                {
                    no_of_rotations=3;
                }
                else if(no_of_rotations==3)
                {
                    no_of_rotations=1;
                }
            }
            if(extension == "ppm")
            {
                rotatePPM(no_of_rotations);
            }
            else {
                rotatePGM(no_of_rotations);
            }
        }
};

#endif