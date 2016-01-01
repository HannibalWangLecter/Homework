import java.util.ArrayList;

import info.gridworld.grid.AbstractGrid;
import info.gridworld.grid.Location;

/**
  * extends AbstractGrid<E>
  * two-dimension array to implement.
  * the grid is a square which is easier.
  * the grid enlarged when needed sp it is unbounded!
  */
public class UnboundedGrid2<E> extends AbstractGrid<E> {

    public static final int INIT_LENGTH = 16;

    // it must be a square
    private int sideLength;
    private Object[][] occupantArray;    
    /**
     * Constructs the unbounded grid with a init length
     */
    public UnboundedGrid2() {
        sideLength = INIT_LENGTH;
        occupantArray = new Object[INIT_LENGTH][INIT_LENGTH];
    }

    /**
     * calculate the Cols
     */
    public int getNumCols() {
        return -1;
    }

    /**
    *calculate the Rows
     */
    public int getNumRows() {
        return -1;
    }

    /**
     * Gets the occupied locations.
     */
    public ArrayList<Location> getOccupiedLocations() {
        ArrayList<Location> locs = new ArrayList<Location>();
        
        // easy but unefficent loop
        for (int i = 0; i < sideLength; i++) {
            for (int j = 0; j < sideLength; j++) {
                Location loc = new Location(i, j);
                if (get(loc) != null) {
                    locs.add(loc);
                }
            }
        }
        
        return locs;
    }

    /**
     * Checks valid
     */
    public boolean isValid(Location loc) {
        // precondition
        if (loc == null) {
            return false;
        }
        int row = loc.getRow();
        int col = loc.getCol();
        if (0 <= row && 0 <= col) {
            return true;
        } else {
            return false;           
        }
    }
    /**
     * Returns the object at a given location
     */
    @SuppressWarnings("unchecked")
    public E get(Location loc) {
        if (!isValid(loc)) {
            throw new IllegalArgumentException("Location " + loc
                    + " is not valid");
        }
        int row = loc.getRow();
        int col = loc.getCol();
        if (row < sideLength && col < sideLength) {
            return (E) occupantArray[row][col];
        } else {
            return null;
        }
        
    }

    /**
     */
    public E put(Location loc, E obj) {
        if (!isValid(loc)) {
            throw new NullPointerException("loc is null");
        }
        if (obj == null) {
            throw new NullPointerException("obj is null");
        }

        boolean resize = false;
        int col = loc.getCol();
        int row = loc.getRow();
        int newSideLength = sideLength;

        while (newSideLength <= col || newSideLength <= row) {
            newSideLength *= 2;
            resize = true;
        }

        if (resize) {
            Object[][] newGrid = new Object[newSideLength][newSideLength];
            for (int i = 0; i < sideLength; i++) {
                System.arraycopy(occupantArray[i], 0, newGrid[i], 0, sideLength);
            }

            // resize both the array and length variable.
            sideLength = newSideLength;
            occupantArray = newGrid;
        }

        // get the old obj
        E oldObject = get(loc);

        // put the new object to the grid
        occupantArray[loc.getRow()][loc.getCol()] = obj;

        return oldObject;
    }

    /**
     */
    public E remove(Location loc) {
        if (!isValid(loc)) {
            throw new IllegalArgumentException("Location " + loc
                    + " is not valid");
        }
        E old = get(loc);
        occupantArray[loc.getRow()][loc.getCol()] = null;
        return old;
    }

}
