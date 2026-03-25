# OPENCV_INCLUDE=/home/spidervn/setup/opencv-4.11.0/BIN/include/opencv4
# OPENCV_LIB_PATH=/home/spidervn/setup/opencv-4.11.0/BIN/lib
# OPENCV_BIN_PATH=/home/spidervn/setup/opencv-4.11.0/BIN/lib
echo ${OPENCV_LIB_PATH}
OPENCV_CMD=`pkg-config --cflags --libs opencv4`
echo ${OPENCV_CMD}
g++ board.cpp -o board $(pkg-config --cflags --libs opencv4) -I${OPENCV_INCLUDE} -L${OPENCV_LIB_PATH} -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs  -Wl,-rpath,"${OPENCV_BIN_PATH}"