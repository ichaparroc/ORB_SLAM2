/**
* This file is part of ORB-SLAM2.
*
* Copyright (C) 2014-2016 Raúl Mur-Artal <raulmur at unizar dot es> (University of Zaragoza)
* For more information see <https://github.com/raulmur/ORB_SLAM2>
*
* ORB-SLAM2 is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* ORB-SLAM2 is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with ORB-SLAM2. If not, see <http://www.gnu.org/licenses/>.
*/


#include<iostream>
#include<algorithm>
#include<fstream>
#include<chrono>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#include<opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include <opencv2/highgui/highgui.hpp>

using namespace std;
//using namespace cv;

int main(int argc, char **argv)
{   
	
    cv::VideoCapture cap1; // open the default camera
    if(!cap1.open(0))  // check if we succeeded
	{        
		cout<<"no se puede cargar la camara";
		return -1;
    }
	cvNamedWindow( "w", 1);
	while(1)
	{
		cv::Mat im;
		cap1 >> im;
        
		if(im.empty())
        {          
			cout<<"imagen vacia";        	
			return 1;
        }

        // Pass the image to the SLAM system
    	cv::imshow("w",im);
		cout<<"hola"; 
		if(cv::waitKey(30) >= 0) break;
    }

	//cap1.close();
    return 0;
}

