
import info.gridworld.actor.ActorWorld;
import info.gridworld.actor.Bug;
import info.gridworld.actor.Flower;
import info.gridworld.actor.Rock;
import info.gridworld.grid.Location;

/**
 * This class runs a world that contains crab critters. <br />
 * This class is not tested on the AP CS A and AB exams.
 */
public class KingCrabRunner
{

    private KingCrabRunner() {

    }

    public static void main(String[] args)
    {
        ActorWorld world = new ActorWorld();
        world.add(new Location(7, 5), new Bug());
        world.add(new Location(5, 4), new Bug());
        world.add(new Location(5, 7), new Bug());
        world.add(new Location(7, 3), new Bug());
        world.add(new Location(6, 5), new Bug());
        world.add(new Location(5, 3), new Bug());
        world.add(new Location(4, 4), new Bug());
        world.add(new Location(4, 5), new KingCrab());
        world.add(new Location(6, 1), new KingCrab());
        world.show();
    }
}
