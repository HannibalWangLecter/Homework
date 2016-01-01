/*
*Horse.java
*
*/

import info.gridworld.actor.*;
import info.gridworld.grid.Location;
import info.gridworld.grid.Grid;

import java.util.ArrayList;

public class Horse extends Critter
{
    public static final int QUARTER_CIRCLE = 90;    

    public ArrayList<Actor> getActors()
    {
        ArrayList<Actor> actors = new ArrayList<Actor>();   

        //get the Horse's location and direction
        int direction = getDirection();
        Location currLoc = getLocation();
        
        /**
         *if it face east,south, west or north, just return the actor ahead of it
         */
        if (direction % QUARTER_CIRCLE == 0)
        {
            Location aheadLoc = currLoc.getAdjacentLocation(direction);
            if (getGrid().isValid(aheadLoc))
            {
                Actor actor = getGrid().get(currLoc.getAdjacentLocation(direction));
                if (actor != null)
                {
                    actors.add(actor);
                }
            }
        }
        /**
         *or, return the left-45-degree or right-45-degree actor
         */
        else
        {
            int[] dirs = { Location.HALF_LEFT, Location.HALF_RIGHT };
            for (Location loc : getLocationsInDirections(dirs, currLoc))
            {
                Actor a = getGrid().get(loc);
                if (a != null)
                    actors.add(a);
            }

        }
        return actors;
    }

    /*
     *just set the color
     */
    public void processActors(ArrayList<Actor> actors)
    {
        for (Actor a : actors)
        {
            a.setColor(getColor());
        }
    }
   

   /**
    *The horse will run a "8" pattern, 
    *The move to location will depend on the horse's direction
    */
   public ArrayList<Location> getMoveLocations()
    {
        //get the Horse's location and direction
        int direction = getDirection();
        Location currLoc = getLocation();
      
        //get the location ahead of the horse
        Location aheadLoc = currLoc.getAdjacentLocation(direction);

        int[] dirs = { Location.HALF_LEFT, Location.HALF_RIGHT };
        return getLocationsInDirections(dirs, aheadLoc);
    }
    

    /**
     *Moves this critter to the given location
     *if the move-to-location is the same as current location
     *    turn right 45 degrees
     *If there is a different actor
     *    at location loc, that actor is removed from the grid.
     */
    public void makeMove(Location loc)
    {
        if (loc == null)
        {
            removeSelfFromGrid();
        }
        else if (getLocation().equals(loc))
        {
            setDirection(getDirection() + Location.HALF_RIGHT);
        }
        else
            moveTo(loc);
    }

    /**
     * Finds the valid adjacent locations of this critter in different
     * directions.
     * @param directions - an array of directions (which are relative to the
     * current direction)
     * @return a set of valid locations that are neighbors of the current
     * location in the given directions
     */
    public ArrayList<Location> getLocationsInDirections(int[] directions, Location loc)
    {
        ArrayList<Location> locs = new ArrayList<Location>();
        Grid gr = getGrid();
        for (int d : directions)
        {
            Location neighborLoc = loc.getAdjacentLocation(getDirection() + d);
            if (gr.isValid(neighborLoc))
                locs.add(neighborLoc);
        }
        return locs;
    }

}

