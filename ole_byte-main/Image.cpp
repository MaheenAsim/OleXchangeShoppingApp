#include<iostream>
#include "Image.h"
using namespace std;

int main(){
    Image img;
    img.set_to_file("big.ppm");
    img.print();
}