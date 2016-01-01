/* 
 */

import info.gridworld.actor.ActorWorld;
import info.gridworld.actor.Rock;
import info.gridworld.grid.Location;

import java.awt.Color;

/**
 * This class runs a world that contains chameleon critters. <br />
 * This class is not tested on the AP CS A and AB exams.
 */
public final class BlusterCritterRunner
{
    private BlusterCritterRunner() {
        
    }

    public static void main(String[] args)
    {
        ActorWorld world = new ActorWorld();
        world.add(new Location(7, 8), new Rock());
        world.add(new Location(3, 3), new Rock());
        world.add(new Location(2, 8), new Rock(Color.BLUE));
        world.add(new Location(5, 5), new Rock(Color.PINK));
        world.add(new Location(4, 4), new BlusterCritter(5));
        world.add(new Location(5, 8), new BlusterCritter(4));
        world.add(new Location(6, 6), new BlusterCritter(3));
        world.add(new Location(3, 8), new BlusterCritter(1));
        world.show();
    }
}