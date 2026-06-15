// src/Main.java
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;

public class Movement {
    public static void main(String[] args) {
        // CRITICAL: You must load the native library before using OpenCV classes
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        
        System.out.println("OpenCV Loaded Successfully!");
        Mat mat = Mat.eye(3, 3, CvType.CV_8UC1);
        System.out.println("Matrix:\n" + mat.dump());
    }
}