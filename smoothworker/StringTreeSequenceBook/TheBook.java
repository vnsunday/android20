import java.nio.file.Path;
import java.nio.file.Paths;


public class TheBook {
	
	public static int PageBookToPDFPage(int pageNo) {
		int nBookP7 = 21;
		int nBookP8 = 24;
		
		if (pageNo % 2 == 0) {
			return nBookP8 + (pageNo - 8) * 2;
		}
		else {
			return nBookP7 + (pageNo - 7) * 2;
		}
	}
	
	public static String listPDFPage(int pageNoStart, int pageNoFinish) {
		StringBuilder sb = new StringBuilder();
		sb.append(String.format("%d", PageBookToPDFPage(pageNoStart)));
		for (int i=pageNoStart+1; i<=pageNoFinish; i++) {
			sb.append(String.format(",%d", PageBookToPDFPage(i)));
		}
		return sb.toString();
	}

	public static void main(String[] args) {
		int nP1 = 3;
		int nP2 = 6;
		
		
		int pairStart = 0;
		int pairEnd = 50;
		
		StringBuilder sb = new StringBuilder();
		
		for (int i=pairStart; i< pairEnd; ++i) {
			sb.append(String.format(",%d,%d", nP1 + i*2, nP2 + i*2 ));
		}
		
		System.out.println(sb.toString());
		System.out.println(listPDFPage(43, 60));
	}
}