import org.opencv.core.Core;

class string_pull_visual {
	
	final int MIN_WIDTH = 250;
	final int MAX_WIDTH = 1200;
	final int MIN_HEIGHT = 250;
	final int MAX_HEIGHT = 1200;

    static void pull_simple() {       
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
    }

    public static void main(String[] args) {
        // CRITICAL: You must load the native library before using OpenCV classes
        System.loadLibrary(Core.NATIVE_LIBRARY_NAME);
        
        
    }
}