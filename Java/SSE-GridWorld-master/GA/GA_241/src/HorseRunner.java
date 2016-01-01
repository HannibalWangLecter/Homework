import info.gridworld.actor.*;
import info.gridworld.actor.Rock;
import info.gridworld.grid.Location;

import java.awt.Color;

/**
 * This class runs a world that contains chameleon critters. <br />
 * This class is not tested on the AP CS A and AB exams.
 */
public class HorseRunner
{
    public static final int THREE = 3;
    public static final int FOUR = 4;
    public static final int FIVE = 5;
    public static final int SIX = 6;
    public static final int SEVEN = 7;
    public static final int EIGHT = 8;
    
    public static void main(String[] args)
    {
        ActorWorld world = new ActorWorld();
        world.add(new Location(SEVEN, EIGHT), new Rock());
        world.add(new Location(THREE, THREE), new Rock());
        world.add(new Location(2, EIGHT), new Rock(Color.BLUE));
        world.add(new Location(FIVE, FIVE), new Rock(Color.PINK));
        world.add(new Location(1, FIVE), new Rock(Color.RED));
        world.add(new Location(SEVEN, 2), new Rock(Color.YELLOW));
        world.add(new Location(FIVE, FIVE), new Flower(Color.YELLOW));
        world.add(new Location(FOUR, FOUR), new Horse());
        //world.add(new Location(FIVE, EIGHT), new Horse());
        world.show();
    }
}
