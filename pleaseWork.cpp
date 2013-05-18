#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "MartinFox/OCVCapture.h"


int main() {

   OCVCapture cap;

   // Set desired size in OCVCapture.cpp
   //cap.setDesiredSize(320, 240);
   //cap.setDesiredSize(640, 480);
   cap.setVerbose(true);
   cap.open();

   if (!cap.isOpen())
   {
      std::cerr << "Failed to open camera" << std::endl;
      return -1;
   }
   std::cout << "Capture " << cap.width() << " x " << cap.height();
   std::cout << " pixels at " << cap.frameRate() << " fps" << std::endl;

   std::cout << "Grabbing 20 'trash' frames" << std::endl;
   // The first several frames tend to come out black.
   cv::Mat frame;
   for (int i = 0; i < 20; i++)
   {
      cap.grab();
      cap.rgb(frame);
      usleep(5000);
   }

//      cv::VideoWriter vid("testVid.avi",CV_FOURCC('D','I','V','X'),7,
//                           frame.size(),true);
   //cv::namedWindow("Window");


   bool done = false;
   bool paused = false;

   unsigned int frame_count = 0;

   std::cout << "Entering main loop" << std::endl;
   for (int i = 0; i<300; i++)
  {
//      if (!paused)
//         done = !cap.grab();

//         if (!done)
//         {
	    cap.grab();
            cap.rgb(frame);
//            vid << frame;

            std::cout << "\rFrame:  " << frame_count++ << std::flush;
            //cv::imshow("Window",frame);

	    char str[50];
            if (frame_count % 30 == 0)
               {
                  sprintf(str,"frame_%d.jpg",frame_count);
                  //cv::imwrite(str,frame);
		  //cv::imshow("Window",frame);
		  //cv::waitKey(0);
               }
  }

//         if (!done)
//         {
//            int key = cv::waitKey(10);
//            switch (key)
//            {
//               case 27:
//                  done = true;
//                  break;
//               case ' ':
//                  paused = !paused;
//                  break;
//             }
//          }
//      }
//
      cap.close();

   return 0;
}
