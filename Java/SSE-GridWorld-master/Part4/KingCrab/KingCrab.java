import info.gridworld.actor.Actor;
import info.gridworld.actor.Critter;
import info.gridworld.grid.Grid;
import info.gridworld.grid.Location;

import java.awt.Color;
import java.util.ArrayList;

/**
 * A <code>KingCrab</code> looks at a limited set of neighbors when it eats and moves.
 * Neighbors have to move or disappear.
 */
public final class KingCrab extends CrabCritter {

    private Location findPlaceToRun(Actor a) {
        // There is five possible space to escape on the direction
        int to = getLocation().getDirectionToward(a.getLocation());

        Location curLoc = a.getLocation();

        Grid gr = getGrid();
        
        // AHEAD LEFT RIGHT HALF_LEFT HALF_RIGHT
        int direct[] = {0, -90, 90, -45, 45};

        int i = 0;
        for (i = 0; i < 5; i++) {
            int tmpDirect = to+direct[i];
            Location tmp = curLoc.getAdjacentLocation(tmpDirect);
            if (gr.isValid(tmp) && (gr.get(tmp) == null)) {
                a.setDirection(tmpDirect);
                return tmp;
            }
        }
        return null;

    }

    public void processActors(ArrayList<Actor> actors) {
        
        for (Actor a : actors) {
            Location runLoc = findPlaceToRun(a);

            if(runLoc != null) {
                a.moveTo(runLoc);
            } else {
                a.removeSelfFromGrid();
            }
        }
    }

}
