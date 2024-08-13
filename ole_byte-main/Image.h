#include<iostream>
#include <fstream>
#include <string>
#include"/usr/local/cs/cs251/show_mem.h"


using namespace std;

struct Pixel{
    unsigned char red, green, blue;
};

class Image{
    private:
        unsigned int width;
        unsigned int height;
        unsigned int depth; 
        Pixel **data;

    public:
        Image(){
            width = 1;
            height = 1;
            data = new Pixel*[height];
            for(unsigned int i = 0; i < height; i++){
                data[i] = new Pixel[width]; 
            }
        }

         void set_to_file(string filename){   //function where the user provides the desired file name as the object will be initialized accordingly
            ifstream img_reader(filename);
            char name[3];
            img_reader >> name >> width >> height; //getting the width and height from the .ppm file provided
            data = new Pixel*[height];
            for(unsigned int i = 0; i < height; i++){
            data[i] = new Pixel[width];
            }

            img_reader >> depth;
            img_reader.get();
            
            for(unsigned int i =0; i < height; i++){
                 img_reader.read(reinterpret_cast<char *>(data[i]), 3*width);
            }
            img_reader.close(); 
            _write_image("output.ppm", reinterpret_cast<char **>(data), width, height);
        }

        unsigned int getHeight(){
            return height;
        }   

        void print(){
            _write_image("output.ppm", reinterpret_cast<char **>(data), width, height);
        } 

        ~Image(){
            for(unsigned int i = 0; i < height; i++){
                delete [] data[i];
             }
             delete [] data;
        }

        void rotate();
        void crop();
        void circular_crop();
        void adjust_saturation();
        void adjust_contrast();
};
