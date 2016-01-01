/**
*Part 5
*Author:kinsang
*/
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import info.gridworld.grid.AbstractGrid;
import info.gridworld.grid.Location;

 /**
  * extends AbstractGrid<E>
  * SparseGridNode
  */
public class SparseBoundedGrid<E> extends AbstractGrid<E> {

    //memeber variable
    private List<LinkedList<OccupantInCol>> occupantArray;

    //It is fixed in total but dynamic in each row!
    private int gridCols;

    // rows are unnecessarily
    
    /**
     * Constructs an empty bounded grid with the given dimensions.
     * (Precondition: valid
     */
    public SparseBoundedGrid(int rows, int cols) {
        if (rows <= 0) {
            throw new IllegalArgumentException("rows less than 0");
        }
        if (cols <= 0) {
            throw new IllegalArgumentException("cols less than 0");
        }

        gridCols = cols;
        occupantArray = new ArrayList<LinkedList<OccupantInCol>> ();

        int i;
        for (i = 0; i < rows; i++) {
            occupantArray.add(new LinkedList<OccupantInCol>());
        }
        
    }
    
    /**
     * get the number of rows
     */
    public int getNumRows() {
        int row = occupantArray.size();
        return row;
    }
    
    /**
     * get the number of columns 
     */
    public int getNumCols() {
        return gridCols;
    }
    
    /**
     * Checks whether a location is valid.
     */
    public boolean isValid(Location loc) {
        if (loc == null) {
            return false;
        }
        int row = loc.getRow();
        int col = loc.getCol();
        if (0 <= row && row < getNumRows() && 0 <= col && col < getNumCols()) {
            return true;
        } else {
            return false;           
        }

    }
    
    /**
     * Gets the locations in this grid that occupied
     */
    public ArrayList<Location> getOccupiedLocations() {

        ArrayList<Location> locs = new ArrayList<Location>();
        int row = 0;

        // trasvel the RowList to find all !
        for (LinkedList<OccupantInCol> rowList : occupantArray) {
            for(int j = 0; j < rowList.size(); j++) {
                int col = rowList.get(j).getCol();
                Location tmpLoc = new Location(row, col);
                locs.add(tmpLoc);
            }
            row++;
        }
        
        return locs;
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

        LinkedList<OccupantInCol> rowList = occupantArray.get(row);
        if (!rowList.isEmpty()) {

            // trasvel the RowList to find it
            for (OccupantInCol occupant : rowList) {
                int occupantCol = occupant.getCol();
                if (occupantCol == col) {
                    return (E) occupant.getOccupant();
                }
            }
        }
        return null;
    }

    /**
     * Puts an object at a given location in this SparseBoundedGrid
     */
    public E put(Location loc, E obj) {

        if (!isValid(loc)) {
            throw new IllegalArgumentException("Location " + loc
                    + " is not valid");
        }

        if (obj == null) {
            throw new NullPointerException("obj == null");
        }

        // first to determine whether there exist an element!
        E originObject = get(loc);
        int row = loc.getRow();
        int col = loc.getCol();
        LinkedList<OccupantInCol> rowList = occupantArray.get(row);

        // if null add new occupant
        if (originObject == null) {
            rowList.add(new OccupantInCol(obj, col));
        } else {
            // if non null, put new obj
            for (OccupantInCol occupant : rowList) {
                if (occupant.getCol() == col) {
                    occupant.putOccupant(obj);
                }
            }
        }
        return originObject;

    }

    /**
     * Removes the object at a given location
     */
    public E remove(Location loc) {

        if (!isValid(loc)) {
            throw new IllegalArgumentException("Location " + loc
                    + " is not valid");
        }

        E obj = get(loc);
        if (obj == null) {
            // do nothing
        } else {
            int row = loc.getRow();
            int col = loc.getCol();
            LinkedList<OccupantInCol> rowList = occupantArray.get(row);

            // trasvel the RowList to find it
            for (OccupantInCol occupant : rowList) {
                if (occupant.getCol() == col) {
                    rowList.remove(occupant);
                    break;
                }
            }
        }
        return obj;
    }
}