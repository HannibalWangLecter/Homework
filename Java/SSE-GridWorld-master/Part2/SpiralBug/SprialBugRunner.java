/* 
 * @author Kinsang
 */

import info.gridworld.actor.ActorWorld;
import info.gridworld.grid.Location;
import java.awt.Color;

/*
 */
public class SprialBugRunner
{
    public static void main(String[] args)
    {
        ActorWorld world = new ActorWorld();
        SprialBug tommy = new SprialBug(6); // new object
        tommy.setColor(Color.BLUE); // set coolur
        world.add(new Location(5, 5), tommy);
        world.show();
    }
}
