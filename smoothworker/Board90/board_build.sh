OPENCV_INCLUDE=/home/spidervn/setup/opencv-4.11.0/BIN/include/opencv4
OPENCV_LIB_PATH=/home/spidervn/setup/opencv-4.11.0/BIN/lib
OPENCV_BIN_PATH=/home/spidervn/setup/opencv-4.11.0/BIN/lib
echo ${OPENCV_LIB_PATH}
g++ board.cpp -o board -I${OPENCV_INCLUDE} -L${OPENCV_LIB_PATH} -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs  -Wl,-rpath,"${OPENCV_BIN_PATH}"