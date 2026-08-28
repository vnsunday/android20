import java.util.ArrayList;
import java.util.List;

import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.MatOfPoint;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.imgproc.Imgproc;

class string_pull_visual {
	
	final int MIN_WIDTH = 250;
	final int MAX_WIDTH = 1200;
	final int MIN_HEIGHT = 250;
	final int MAX_HEIGHT = 1200;
	
	static Scalar clyellow = new Scalar(0, 255, 255);
	static Scalar clbrown = new Scalar(200, 0, 150);
	
	static double[] GenerateCurvePath(int x0, int y0, int x1, int y1, int l) throws Exception {
		// (x0, y0): starting point
		// (x1, y1): ending point
		double l1 = Math.sqrt( (x1 - x0) * (x1 - x0) + ( y1 - y0 ) * (y1 - y0));
		
		if (l1 <= l) {
			// Generate a middle point 
			double xm = (x0 + x1) / 2;
			double ym = (y0 + y1) / 2;			
			double h = Math.sqrt( l * l - ( l1  * l1 )) / 2;
			
			// Indicate the third point
			// Unit vector of AB
			double uvx = (x1 - x0) / l1;
			double uvy = (y1 - y0) / l1;
			
			// Perpendicular to the Unit 
			double puvx1 = -uvy;  // Perpendicular 1
			double puvy1 = uvx;
			double puvx2 = uvy;  // Perpndicular 2
			double puvy2 = -uvx;
			
			// Two Solutions 
			double x3_1 = xm + h * puvx1;
			double y3_1 = ym + h * puvy1;
			double x3_2 = xm + h * puvx2;
			double y3_2 = ym + h * puvy2;
			
			return new double[] { x3_1, y3_1, x3_2, y3_2 };
		}
		else {
			throw new Exception("Invalid");
		}
	}

    static void pull_simple(Mat img) throws Exception { 
    	double M2Pixel = 50;
    	/*============================================================
            
         *============================================================*/
    	int mode = 0; // Left - Right - Justify 
        double dx = 5; // In Meter
        double dy = 1; // In Meter 

        double l = 12; // In meter 
        double px = 1;
        double py = 5; 
        
        int nW = 0;
        int nH = 0;
        
        // Draw a curve with a length l 
        List<Point> cp = new ArrayList<Point>(); // curve path
        
        // 
        int x0 = 0;
        int y0 = 0;
        int x1 = (int)(dx * M2Pixel);
        int y1 = (int)(dy * M2Pixel);
        
        double [] pts = GenerateCurvePath(x0, y0, x1, y1, (int)l);
        // Generating a curve 
        // GenerateCurvePath(x0, y0, x1, y1, (int)l);
        cp.add(new Point(x0, y0)); // Starting point
        cp.add(new Point((int)pts[0], (int)pts[1]));
        cp.add(new Point(x1, x1)); // Last Point
               
        // Draw curves 
        MatOfPoint mopcp = new MatOfPoint();  // Mat of Point for the Curve-path
        mopcp.fromList(cp);
        Imgproc.polylines(img, 
        					new ArrayList<MatOfPoint>( List.of(mopcp) ), 
			        		false,  // IsClosed
			        		clbrown,
			        		2, // Thickness
			        		Imgproc.LINE_AA);
    }

    public static void main(String[] args) {
        // CRITICAL: You must load the native library before using OpenCV classes
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        Mat img = new Mat(600, 400, CvType.CV_8UC3, new Scalar(255, 255, 255));       
        
        try {
        	pull_simple(null);
        }
        catch (Exception ex) {
        }
        finally {
        }
    }
}