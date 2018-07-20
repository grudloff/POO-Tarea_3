
import java.awt.image.*;
import javax.imageio.ImageIO;
import java.io.*;
import java.util.*;

public class convertPBM {

	public static void main(String[] args) {

		try {
      		String defFile = "simple_maze.pbm";
      		String outFile;
			String outputFileFormat = "jpg";

			if (args.length > 0)
				defFile = args[0];
			else {
				System.out.println("\nUsage: convertPBM INPUT.pbm OUTPUT_IMAGE\n\n\tOUTPUT_IMAGE available formats: JPG (default), GIF, PNG.\n");
				System.exit(0);
			}

			if (args.length > 1)
				outFile = args[1];
			else
				outFile = defFile.split("\\.")[0];

			String[] outFileSplitted = outFile.split("\\.");
			if (outFileSplitted.length == 2)
				outputFileFormat = outFileSplitted[1];
			else
				outFile = outFile + ".jpg";

			System.out.println(outFile+"_"+outputFileFormat);

			Scanner sc = new Scanner(new File(defFile));
      		walls scenario = (walls) new Maze(sc);


		    byte BLACK = (byte)0, WHITE = (byte)255;
		    byte[] map = {BLACK, WHITE};
		    IndexColorModel icm = new IndexColorModel(1, map.length, map, map, map);
			WritableRaster raster = icm.createCompatibleWritableRaster(scenario.getWidth(), scenario.getHeight());

			raster.setPixels(0, 0, scenario.getWidth(), scenario.getHeight(), reshapeTo1D(scenario.getArray()));
    		BufferedImage bi = new BufferedImage(icm, raster, false, null);
    		ImageIO.write(bi, outputFileFormat, new File(outFile));

		} catch (IOException e) {
			System.out.println(e.getMessage());
		}
	}
	public static int[] reshapeTo1D(boolean[][] A) {
        int[] A1D = new int[A.length * A[0].length];

        int index = 0;
        for(int i = 0;i<A.length;i++){
            for(int j = 0;j<A[0].length;j++){
                A1D[index++] = A[i][j]? 0 : 1;
            }
        }

        return A1D;
    }
}

