#include<stdio.h>
#include "cv.h"
#include "highgui.h"

int main( int argc, char** argv )
{
    IplImage* pImg; //����IplImageָ��

    //����ͼ��
    if( argc == 2 &&
        (pImg = cvLoadImage( argv[1], 1)) != 0 )
    {
        cvNamedWindow( "Image", 1 );//��������
        cvShowImage( "Image", pImg );//��ʾͼ��

        cvWaitKey(0); //�ȴ�����

        cvDestroyWindow( "Image" );//���ٴ���
        cvReleaseImage( &pImg ); //�ͷ�ͼ��
        return 0;
    }

    return -1;
}
