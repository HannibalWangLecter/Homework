/**
*Part 5
*Author:kinsang
*/

import java.util.*;

import info.gridworld.grid.AbstractGrid;
import info.gridworld.grid.Location;

 /**
  * extends AbstractGrid<E>
  */

public class SparseBoundedGrid2<E> extends AbstractGrid<E> {

    // member
    private int gridNum;
    private int gridCol;
    private Map<Location, E> occupantMap;

    /**
     * Constructs an empty bounded
     */
    public SparseBoundedGrid2(int rows, int cols) {
        if (rows <= 0) {
            throw new IllegalArgumentException("rows less than 0");
        }
        if (cols <= 0) {
            throw new IllegalArgumentException("cols less than 0");
        }
        
        gridNum = rows;
        gridCol = cols;
        
        occupantMap = new HashMap<Location, E>();
    }
    
    /**
     * get the number of rows in this SparseBoundedGrid 
     */
    public int getNumRows() {
        return gridNum;
    }
    
    /**
     * get the number of columns in this SparseBoundedGrid
     */

    public int getNumCols() {
        return gridCol;
    }
    
    /**
     * Checks whether a location is valid
     */
    public boolean isValid(Location loc) {
        int row = loc.getRow();
        int col = loc.getCol();
        return 0 <= row && row < gridNum
                && 0 <= col && col < gridCol;
    }
    
    /**
     * Gets the locations in this grid that contain objects.
     */

    public ArrayList<Location> getOccupiedLocations() {
        ArrayList<Location> locs = new ArrayList<Location>();
        
        for (Location loc : occupantMap.keySet()) {
            locs.add(loc);
        }
        
        return locs;
    }
    
    /**
     * Returns the object at a given location in this SparseBoundedGrid
     */
    public E get(Location loc) {

        // * Precondition: loc is valid in this SparseBoundedGrid
        if (!isValid(loc)) {
            throw new IllegalArgumentException("Location " + loc
                    + " is not valid");
        }       
        
        return occupantMap.get(loc);
        
    }

    /**
     */
    public E put(Location loc, E obj) {
        if (!isValid(loc)) {
            throw new IllegalArgumentException("Location " + loc
                    + " is not valid");
        }
        if (obj == null) {
            throw new NullPointerException("obj == null");
        }
        
        // hash map
        return occupantMap.put(loc, obj);
    }

    /**
     * Removes the object at a given location from this SparseBoundedGrid
     */
    public E remove(Location loc) {

        //      * Precondition: loc is valid
        
        if (!isValid(loc)) {
            throw new IllegalArgumentException("Location " + loc
                    + " is not valid");
        }
        
        return occupantMap.remove(loc);
    }
}
