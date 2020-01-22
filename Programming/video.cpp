#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <zmq.h>

// g++ -o video video.cpp `pkg-config --cflags --libs opencv`

using namespace std;
using namespace cv;

void usage(char *prog) {
    printf("Usage: %s <video file>\n", prog);
    exit(0);
}

int main(int argc, char *argv[]) {

    void *context = zmq_ctx_new();
    void *publisher = zmq_socket(context, ZMQ_PUB);
    int bind = zmq_bind(publisher, "tcp://*:9000");
    
    if (argc < 2)
        usage(argv[0]);

    VideoCapture cap(argv[1]);

    if(!cap.isOpened()) {
        cout << "Error opening video stream" << endl;
        exit(-1);
    }

    int frame_width = cap.get(CV_CAP_PROP_FRAME_WIDTH);
    int frame_height = cap.get(CV_CAP_PROP_FRAME_HEIGHT);

    char width[6];
    char height[6];

    sprintf(width, "%d", frame_width);
    sprintf(height, "%d", frame_height);

    while (1) {
        Mat frame;
        cap >> frame;

        if (frame.empty())
            break;
        zmq_send(publisher, width, strlen(width), ZMQ_SNDMORE);
        zmq_send(publisher, height, strlen(height), ZMQ_SNDMORE);
        zmq_send(publisher, frame.data, (frame_height*frame_width*3), ZMQ_NOBLOCK);

        //imshow("Frame", frame);
        char c = (char) waitKey(25);
        if (c == 27)
            break;
    }
    cap.release();
    destroyAllWindows();
    zmq_close(publisher);
    zmq_ctx_destroy(context);
    return 0;
}