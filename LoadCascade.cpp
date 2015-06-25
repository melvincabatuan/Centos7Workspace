#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace cv;
using std::cout;
using std::endl;



class MyClassifier : public cv::CascadeClassifierImpl{
public:
    using CascadeClassifierImpl::CascadeClassifierImpl;
    using CascadeClassifierImpl::empty;
    using CascadeClassifierImpl::read;
    using CascadeClassifierImpl::load;
    using CascadeClassifierImpl::detectMultiScale;
    using CascadeClassifierImpl::getOriginalWindowSize;
    using CascadeClassifierImpl::getFeatureType;
};

 

/** Global variables */
String face_cascade_name = "lbpcascade_frontalface.xml";
MyClassifier face_cascade;


/** @function main */
int main( void )
{
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading face cascade\n"); return -1; };
 
    printf("--Everything is OK!\n");

    cout<<"face_cascade.getFeatureType() = "<<face_cascade.getFeatureType()<<endl;
    printf("NOTE: enum { HAAR = 0, LBP = 1 }; // supported feature types\n");

    cout<<"face_cascade.isOldFormatCascade() = "<<face_cascade.isOldFormatCascade()<<endl;

    cout<<"face_cascade.getOriginalWindowSize() = "<<face_cascade.getOriginalWindowSize()<<endl;


   cout<<"face_cascade.getFeatureType() = "<<face_cascade.getFeatureType()<<endl;

  // cout<<"face_cascade.tryOpenCL = "<<face_cascade.data.tryOpenCL<<endl;

    return 0;
}
