import java.io.*;
import java.util.*;

public class Maze extends walls {
   public Maze(Scanner sc) {
      String s;
      while(!sc.hasNextInt())
          sc.nextLine();
      width = sc.nextInt();
      height = sc.nextInt();
      sc.nextLine();
      array = new boolean [height][];
      for (int h=0; h<height; h++)
         array[h] = new boolean[width];
      for (int h=0; h<height; h++) 
         for (int w=0; w<width; ){
            s = sc.findInLine(".");
            if (s==null) sc.nextLine();
            else array[h][w++] = s.charAt(0)=='1';  
         }
   }
   public void rotate() {
   // to be coded
   }
   public void write(PrintStream out){
      out.println("P1");
      out.println("#Created by "+getClass().getName()+"UTFSM ELO329");
   // to be coded
   }
}