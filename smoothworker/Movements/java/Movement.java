// src/Main.java
import org.opencv.core.Core;
import org.opencv.core.CvType;
import org.opencv.core.Mat;
import org.opencv.core.Point;
import org.opencv.core.Scalar;
import org.opencv.highgui.*;
import org.opencv.imgproc.Imgproc;

public class Movement {
	
	static double vector_length(double dx, double dy) {
	    return Math.sqrt(dx*dx + dy*dy);
	}
	
	// Rotating clockwise
	static double[] rotate_vector_cw(double[] vec, double radian) {
		
		double dL = vector_length(vec[0], vec[1]);
		double dRad  = vec[0] == 0 ? 
				Math.PI / 2 : 
				Math.atan(vec[1] / vec[0]);

		return new double[] {
				Math.cos(dRad + radian) * dL, 
				Math.sin(dRad + radian) * dL
		};
	}
	
	// lw: line-width
	public static int draw_a_vector(Mat img, Point p1, Point p2, int lw, Scalar color) {
		
		Scalar clred = new Scalar(0, 0, 255);
		Scalar clblue = new Scalar(255, 0, 0);
		Scalar clblack = new Scalar(0, 0, 0);
		Scalar clyl = new Scalar(0, 255, 255);
		
		Imgproc.line(img, p1, p2, color, lw);
		// Draw Arrow.
	    double dVlen = Math.sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
	                            (p1.y - p2.y) * (p1.y - p2.y) );
	    double darrow_ear = Math.max(15.0, dVlen/10); // Pixel
	    double reverse_vx = p1.x - p2.x;
	    double reverse_vy = p1.y - p2.y;

	    reverse_vx = reverse_vx * darrow_ear / dVlen;  // Unit vector 
	    reverse_vy = reverse_vy * darrow_ear / dVlen;  // 

	    double[] vreverse = { reverse_vx, reverse_vy } ;
	    double[] vear1 = rotate_vector_cw(vreverse, Math.PI/10.0);
	    double[] vear2 = rotate_vector_cw(vreverse, -Math.PI/10.0);
	    
	    Point p3 = new Point(p2.x + vear1[0], p2.y + vear1[1]);
	    Point p4 = new Point(p2.x + vear2[0], p2.y + vear2[1]);

	    Imgproc.line(img, p2, p3, clred, lw);
	    Imgproc.line(img, p2, p4, clblue, lw);
	    Imgproc.circle(img, p1, 10, clblack);
	    Imgproc.circle(img, p2, 10, clyl);

		return 0;
	}
	
    public static void main(String[] args) {
        // CRITICAL: You must load the native library before using OpenCV classes
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        
        System.out.println("OpenCV Loaded Successfully!");
        // Mat mat = Mat.eye(3, 3, CvType.CV_8UC1);
        Mat img = new Mat(400,400, CvType.CV_8UC3, new Scalar(255, 255, 255));
       
        // 
        draw_a_vector(img, new Point(10, 100), new Point(200, 100), 2, new Scalar(0, 0, 255) );
        
        Scalar clblack = new Scalar(0, 0, 0);
        Scalar clyl = new Scalar(0, 255, 255);
        double[] v1 = { 50, 50 };
        double[] v2 = rotate_vector_cw(v1, Math.PI / 9); // PI / 9 = 20 degree
        Point p0 = new Point(30, 30);
       
        
        Imgproc.line(img, p0, new Point(p0.x + v1[0], p0.y + v1[1]), clblack, 2);
        Imgproc.line(img, p0, new Point(p0.x + v2[0], p0.y + v2[1]), clyl, 2);
        
        // 
        HighGui.imshow(null, img);
        HighGui.waitKey();
        HighGui.destroyAllWindows();
        System.exit(0);
    }
}