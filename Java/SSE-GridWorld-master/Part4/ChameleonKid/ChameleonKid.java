/* 
 * Part 4
 * @author Kinsang 
 */

import info.gridworld.actor.*;
import info.gridworld.grid.*;

import java.util.ArrayList;
import java.awt.Color;

/**
 * A <code>ChameleonCritterKid</code> takes on the color of neighboring actors as
 * it moves through the grid. <br />
 */
public final class ChameleonKid extends ChameleonCritter {

    //override the getActor() method
    public ArrayList<Actor> getActors() {
        Grid<Actor> gr = getGrid();
        ArrayList<Actor> actors = new ArrayList<Actor>();
        int[] dirs = { Location.AHEAD, Location.HALF_CIRCLE};

        ArrayList<Location> locs = getLocationsInDirections(dirs);
        for (Location loc : locs) {
            Actor a = gr.get(loc);
            if (a != null) {
                actors.add(a);
            }
        }

        return actors;
    }

    public ArrayList<Location> getLocationsInDirections(int[] directions) {

        ArrayList<Location> locs = new ArrayList<Location>();
        Grid gr = getGrid();
        Location loc = getLocation();
    
        for (int d : directions) {
            Location neighborLoc = loc.getAdjacentLocation(getDirection() + d);
            if (gr.isValid(neighborLoc))
                locs.add(neighborLoc);
        }
        return locs;
    }   
}
