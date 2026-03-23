OPENCV_INCLUDE=/d/setup/development/OpenCV-MinGW-Build-OpenCV-4.5.5-x64/include
OPENCV_LIB_PATH=/d/setup/development/OpenCV-MinGW-Build-OpenCV-4.5.5-x64/x64/mingw/lib
OPENCV_BIN_PATH=/d/setup/development/OpenCV-MinGW-Build-OpenCV-4.5.5-x64/x64/mingw/bin
echo ${OPENCV_LIB_PATH}
g++ board.cpp -o board -I${OPENCV_INCLUDE} -L${OPENCV_LIB_PATH} -lopencv_core -lopencv_highgui -lopencv_imgproc -Wl,-rpath,"${OPENCV_BIN_PATH}"