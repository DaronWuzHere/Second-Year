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

  // Blur the image
  blur = &value;
  calculations(*blur, NULL);

   //create windows and show process
  cv::namedWindow("COMP27112 Ex3 - Original Image", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("COMP27112 Ex3 - Grey Image", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("COMP27112 Ex3 - Blurred Image", CV_WINDOW_AUTOSIZE);  
  cv::namedWindow("COMP27112 Ex3 - Difference Between Images", 
                  CV_WINDOW_AUTOSIZE);
  cv::namedWindow("COMP27112 Ex3 - Histogram", CV_WINDOW_AUTOSIZE); 
  cv::createTrackbar("Blur","COMP27112 Lab 3 - Blurred Image", 
                     blur, MAX_BLUR, calculations, NULL);
  
  // Show images in the display 
  cv::imshow("COMP27112 Ex3 - Original Image", image);
  cv::imshow("COMP27112 Ex3 - Grey Image", greyImage); 
  cv::imshow("COMP27112 Ex3 - Blurred Image", blurredImage);

  // Wait for a key to be pressed
  cv::waitKey(0); 

  return 0;
} // Main


void calculations(int n, void* data)
{
  cv::GaussianBlur(greyImage, blurredImage, nullSize, n);

  // Get the difference of the orignal and blurred image
  cv::subtract(greyImage, blurredImage, differenceImage);
  
  // Prevent the negative image
  cv::add(blurredImage, 128, differenceImage);

  
  float range[] = {0, 256};
  const float* histRange = {range};

  int histSize = 256; 
  cv::calcHist(&differenceImage, 1 , 0, cv::Mat(), histogram, 1, &histSize,
               &histRange);

  // Calculate the standard deviation
  double average = 0;
  double sum = 0;
  double count = 0;
  double deviation = 0;
  for(int i = 0; i < histogram.rows; i++)
  {
    for(int n = 0;n < histogram.cols; n++)
    {
      sum += histogram.at<double>(i,n);
      count++;
    }
  }
  // Recalculate the average
  average = sum / count;

  for(int i = 0; i < histogram.rows; i++)
  {
    for(int n = 0; n < histogram.cols; n++)
    {
      deviation += pow(histogram.at<double>(i,n) - average, 2);
    }
  }
  deviation = sqrt(deviation / count);
  histImage = drawHist(histogram, 2);

  // Send standard deviation for histogram to use
  char deviationText[50];
  sprintf(deviationText, "Standard Deviation: %f\n", deviation);
  putText(histImage, deviationText, cv::Point(0,30), 
          CV_FONT_HERSHEY_PLAIN,1, (255, 255, 255), 1, 8, false);


  // Display the windows 
  cv::imshow("COMP27112 Ex3 - Blurred Image", blurredImage);
  cv::imshow("COMP27112 Ex3 - Difference Between Images", differenceImage);
  cv::imshow("COMP27112 Ex3 - Histogram", histImage);

  cv::imwrite("difference.bmp", differenceImage);
  cv::imwrite("histogram.bmp", histImage);


} // Calculations


//From Lab Manual:
// This method takes a histogram  cv::Mat and  returns a cv::Mat  
// containing the actual drawing of the histogram4
cv::Mat drawHist (cv::Mat hist, int scale)
{
  double mx = 0;
  cv::minMaxLoc(hist, 0, &mx, 0, 0);
  cv::Mat result = cv::Mat::zeros(256 * scale, 256 * scale, CV_8UC1);

  for(int i = 0; i < 255; i++)
  {
    // Get the  histogram  values
    float histValue = hist.at<float>(i, 0);
    float nextValue = hist.at<float>(i + 1, 0);
   
    // Create  4  points for the poly
    cv::Point p1 = cv::Point(i * scale, 256 * scale);
    cv::Point p2 = cv::Point(i * scale + scale, 256 * scale);
    cv::Point p3 = cv::Point(i * scale + scale, 
                            (256-nextValue * 256/mx) * scale);
    cv::Point p4 = cv::Point(i * scale, (256 - nextValue * 256/mx) * scale);

    //Draw the  poly ( Ending  in  p1 )
    int numPoints = 5;
    cv::Point points [] = {p1, p2, p3, p4, p1};
    cv::fillConvexPoly(result, points, numPoints, cv::Scalar::all(256), 0, 0);
  }
  return result;
} // DrawHist
