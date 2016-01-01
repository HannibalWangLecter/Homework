/* 
 * @author Kinsang
 */

import info.gridworld.actor.ActorWorld;
import info.gridworld.grid.Location;
import java.awt.Color;

/*
 */
public class CircleBugRunner
{
    public static void main(String[] args)
    {
        ActorWorld world = new ActorWorld();
        CircleBug tommy = new CircleBug(6);
        tommy.setColor(Color.BLUE);
        world.add(new Location(7, 8), tommy);
        world.show();
    }
}
