import java.util.ArrayList;
import java.util.List;

import org.opencv.core.Core;
import org.opencv.core.Mat;
import org.opencv.core.Point;

class string_pull_visual {
	
	final int MIN_WIDTH = 250;
	final int MAX_WIDTH = 1200;
	final int MIN_HEIGHT = 250;
	final int MAX_HEIGHT = 1200; 
	
	static void GenerateCurvePath(int x0, int y0, int x1, int y1, int l) {
		// (x0, y0): starting point
		// (x1, y1): ending point
	}

    static void pull_simple(Mat img) {       
        /*============================================================
            double M2Pixel = 50;
         *============================================================*/
        double dx = 5; // In Meter
        double dy = 1; // In Meter 

        double l = 12; // In meter 
        double px = 1;
        double py = 5; 
        
        int nW;
        int nH;
        
        // Draw a curve with a length l 
        List<Point> cp = new ArrayList<Point>(); // curve path
        cp.add(new Point(0, 0)); // Starting point
        cp.add(new Point(dx, dy)); // Last Point
    }

    public static void main(String[] args) {
        // CRITICAL: You must load the native library before using OpenCV classes
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
    }
}