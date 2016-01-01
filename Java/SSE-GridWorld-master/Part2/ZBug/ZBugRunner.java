/* 
 * @author Kinsang
 */

import info.gridworld.actor.ActorWorld;
import info.gridworld.grid.Location;
import java.awt.Color;

/*
 */
public class ZBugRunner
{
    public static void main(String[] args)
    {
        ActorWorld world = new ActorWorld();
        ZBug tommy = new ZBug(6);
        tommy.setColor(Color.BLUE);
        world.add(new Location(5, 5), tommy);
        world.show();
    }
}
