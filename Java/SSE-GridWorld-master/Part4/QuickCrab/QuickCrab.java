import info.gridworld.actor.Actor;
import info.gridworld.actor.Critter;
import info.gridworld.grid.Grid;
import info.gridworld.grid.Location;

import java.awt.Color;
import java.util.ArrayList;

/**
 * A <code>QuickCrab</code> looks at a limited set of neighbors when it eats and moves.
 * <br />
 * This class is not tested on the AP CS A and AB exams.
 */
public final class QuickCrab extends CrabCritter {

    public ArrayList<Location> getMoveLocations() {
        ArrayList<Location> loc = getQuickLocations();
        if (loc.size() != 0) {
            return loc;
        } else {
            return super.getMoveLocations();
        }
    }


    //get move location with 
    private ArrayList<Location> getQuickLocations() {

        Grid gr = getGrid();
        int curDirect = getDirection();
        Location curLoc = getLocation();

        ArrayList<Location> locs = new ArrayList<Location>();

        // judge left
        int leftDirect = getDirection()+Location.LEFT;
        Location leftNear = curLoc.getAdjacentLocation(leftDirect);
        if ((gr.isValid(leftNear)) && (gr.get(leftNear)==null)) {
            Location leftFar = leftNear.getAdjacentLocation(leftDirect);
            if (gr.isValid(leftFar) && (gr.get(leftFar) == null)) {
                locs.add(leftFar);
            }
        }

        //judge right
        int rightDirect = getDirection()+Location.RIGHT;
        Location rightNear = curLoc.getAdjacentLocation(rightDirect);
        if ((gr.isValid(rightNear)) && (gr.get(rightNear)==null)) {
            Location rightFar = rightNear.getAdjacentLocation(rightDirect);
            if (gr.isValid(rightFar) && (gr.get(rightFar) == null)) {
                locs.add(rightFar);
            }
        }        

        return locs;
    }

}
