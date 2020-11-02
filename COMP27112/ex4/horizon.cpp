#include <stdio.h>
#include <string.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream> 
#include <cmath>
#include <stdlib.h>
#define MAX_BLUR 20

// Declaration of the OpenCV variables globally
cv::Mat blurredImage;
cv::Size nullSize;
cv::Mat image;
cv::Mat differenceImage;
cv::Mat histImage;
cv::Mat histogram;
cv::Mat greyImage;
cv::Mat drawHist (cv::Mat hist, int scale);

void calculations(int, void*);

int* blur;
int value = 1;

int main ( int argc, char** argv)
{
  if(argc != 2)
  {
    std::cout <<"No image file entered!" << std::endl;
    return -1;
  } // If
  
  // Read an image file into the variable
  image = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);

  // Check image is usable
  if(!image.data)
  {
    std::cout << "Could not find or open the image" << std::endl;
    return -1;
  }
 
  // Convert the image to grey scale
  cv::cvtColor(image, greyImage, CV_RGB2GRAY);







   //create windows and show process
  cv::namedWindow("COMP27112 Ex3 - Grey Image", CV_WINDOW_AUTOSIZE);
  
  // Show images in the display 
  cv::imshow("COMP27112 Ex3 - Grey Image", greyImage); 

  // Wait for a key to be pressed
  cv::waitKey(0); 

  return 0;
} // Main


void calculations(int n, void* data)
{
} // Calculations



