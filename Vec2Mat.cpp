#include "opencv2/core/core.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::vector;

using cv::Mat;





main(void){

int r=3;
int c=3;


Mat M(r,c,CV_32FC1);

for(int i=0;i<r*c;++i)
{
    M.at<float>(i)=i;
}

// print out matrix
cout << M << endl;





// Create vector from matrix data (data with data copying)

vector<float> V;
V.assign((float*)M.datastart, (float*)M.dataend);

// print out vector
cout << "Vector" << endl;
for(int i=0;i<r*c;++i)
{
    cout << V[i] << endl;
}




/**********************   Create matrix from vector *************************/
/*
// Without copying data (only pointer assigned)
//Mat M2=Mat(r,c,CV_32FC1,(float*)V.data());

// With copying data
Mat M2=Mat(r,c,CV_32FC1);
memcpy(M2.data,V.data(),V.size()*sizeof(float));


// Print out matrix created from vector
cout << "Second matrix" << endl;
cout << M2 <<endl;
*/




/**********************  Vector 2 Mat Conversion using memcpy() *************************/
/*
// With copying data
Mat M3=Mat(r*c, 1,CV_32FC1);
memcpy(M3.data,V.data(),V.size()*sizeof(float));


// Print out matrix created from vector
cout << "Third matrix" << endl;
cout << M3 <<endl;
*/




/**********************  Vector 2 Mat Conversion using copyTo() *************************/
/*
Mat M4;
Mat(V).copyTo(M4);
cout << "Fourth matrix" << endl;
cout << M4 <<endl;
*/




/**********************  Vectorize Matrix *************************/
Mat row = M.reshape(1,1);
// print out matrix
cout << row << endl;




/**********************  Push_back a row to matrix *************************/

int d=9;
Mat N(r,d,CV_32FC1);

for(int i=0;i<r*d;++i)
{
    N.at<float>(i)=i;
}

// print out matrix
cout << N << endl;


N.push_back(row);

// print out matrix
cout << "N after push_back = "<< endl;
cout << N << endl;
cout << N.size() << endl;


// Wait for a key
getchar();

}
