

public interface collidableObject {

	abstract byte getComplexity();

   abstract  boolean checkCollision(collidableObject otherObject);

   abstract  void setCollisionState(boolean state);

   default void computeCollision(collidableObject otherObject) {
		if (this.getComplexity() < otherObject.getComplexity())
			otherObject.setCollisionState(this.checkCollision(otherObject));
		else
			this.setCollisionState(otherObject.checkCollision(this));
   }
}