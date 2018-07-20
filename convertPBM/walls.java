
class walls  implements collidableObject {

   public boolean hasWall(point2D p) {
   	  if ((p.x > 0 && p.x <= width) && (p.y > 0 && p.y <= height))
      	return array[(int)p.x][(int)p.y];
      return false;
   }

   public boolean checkCollision(collidableObject obj) {
   	  if (obj instanceof point2D) {
   	  	return hasWall((point2D) obj);
   	  }
   	  return false;
   }


	public byte getComplexity() {
		return complexity;
	}

   public boolean[][] getArray() {
      return array;
   }

   public int getHeight() {
      return height;
   }

   public int getWidth() {
      return width;
   }

	public void setCollisionState(boolean state) {}

   int width, height;
   boolean [][] array;
   byte complexity = 5;
}