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
public final class RockHound extends Critter {

    //override the getActor() method
    public void processActors(ArrayList<Actor> actors) {
        int n = actors.size();
        if (n == 0) {
            return;
        }
        int i = 0;
        for (i = 0; i < n; i++) {
            Actor a = actors.get(i);
            if (!(a instanceof Critter)) {
                a.removeSelfFromGrid();
            }
        }
    }  
}
