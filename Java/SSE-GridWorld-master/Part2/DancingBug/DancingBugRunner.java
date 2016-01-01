/* 
 * @author Kinsang
 */

import info.gridworld.actor.ActorWorld;
import info.gridworld.grid.Location;
import java.awt.Color;

/*
 */
public class DancingBugRunner
{
    public static void main(String[] args)
    {
        int count[] = {1,2,3,4,5,6,7,4,3,2,1,5,6,7};
        ActorWorld world = new ActorWorld();
        DancingBug tommy = new DancingBug(count);
        tommy.setColor(Color.BLUE);
        world.add(new Location(5, 5), tommy);
        world.show();
    }
}
