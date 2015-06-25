#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
 
#include <iostream>
#include <stdio.h>
 
using namespace std;
using namespace cv;




 
int main( )
{
    Mat image;
    image = imread("/root/src/opencv/samples/data/lena.jpg", CV_LOAD_IMAGE_COLOR);  
    namedWindow( "Lena", 1 );   
    imshow( "Lena", image );
 
    CascadeClassifier face_cascade;

    if (face_cascade.empty()){
        face_cascade.load( "/root/src/opencv/data/haarcascades/haarcascade_frontalface_alt2.xml" );
    }

    // Detect faces
    std::vector<Rect> faces;
    face_cascade.detectMultiScale( image, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30) );
 
    // Draw circles on the detected faces
    for( int i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
        ellipse( image, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
    }
     
    namedWindow( "Detected Face", 1 );  
    imshow( "Detected Face", image );
     
    waitKey(0);                   
    return 0;
}
