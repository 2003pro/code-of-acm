#include<stdio.h>
#include "cv.h"
#include "highgui.h"

int        g_slidter_position  = 0;
CvCapture* g_capture = NULL;

void onTrackbarSlide(int pos)
{
    cvSetCaptureProperty(g_capture,CV_CAP_PROP_POS_FRAMES,pos);

    pos = g_slidter_position;

    printf("%d\n",pos);
}

int main( int argc, char** argv )

{
        g_capture=cvCreateFileCapture("E:\\acm\\109\\bin\\Debug\\silent violin.avi");

        int frames=(int)cvGetCaptureProperty(g_capture,CV_CAP_PROP_FRAME_COUNT);

        if(frames!=0)  cvCreateTrackbar("E:\\acm\\109\\bin\\Debug\\silent violin.avi","silent violin",&g_slidter_position,frames,onTrackbarSlide);

        IplImage* frame = NULL;

        cvNamedWindow("silent violin",0);

        CvCapture* capture=cvCreateFileCapture("E:\\acm\\109\\bin\\Debug\\violin.avi");

        while(1)
        {
            frame=cvQueryFrame(capture);

            if(!frame) break;

            cvShowImage("silent violin",frame);

            char c=cvWaitKey(33);

            if(c==27) break;

            g_slidter_position++;

            cvSetTrackbarPos("position","silent violin",g_slidter_position);

            cvDestroyWindow("silent violin");

        }
        cvReleaseCapture(&capture);

        cvDestroyWindow("silent violin");

        return 0;
}
