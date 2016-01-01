/**
* A helper class of sparseGridWorld
*/

public class OccupantInCol {

    private Object occupant;
    private int col;

    /**
     * Constructor of class OccupantInCol
     */
    public OccupantInCol(Object e, int c) {
        occupant = e;
        col = c;
    }

    /**
     * get the value of col
     */
    public int getCol() {
        return col;
    }
    
    /**
     * set the value of col
     */
    public void putCol(int c) {
        col = c;
    }
    
    /**
     * get the value of occupant object
     */
    public Object getOccupant() {
        return occupant;
    }

    /**
     *set the value of occupant object
     */
    public void putOccupant(Object e) {
        occupant = e;
    }
}
