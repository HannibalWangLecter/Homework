import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import info.gridworld.actor.*;
import info.gridworld.grid.Grid;
import info.gridworld.grid.Location;

import java.awt.Color;

public final class HorseTest extends TestCase {

    public HorseTest() {

    }

    public static void main(String args[]) {
        junit.textui.TestRunner.run(HorseTest.class);
    }

    /**
    *Task to test the basic act,move through a rock and replace a flower
    */
    public void testAct() {
        ActorWorld world = new ActorWorld();
        Horse amy = new Horse();
        Rock rock = new Rock();
        Flower flower = new Flower();
        amy.setDirection(Location.NORTH);
        world.add(new Location(8, 0), amy);
        world.add(new Location(6, 1), new Rock());
        world.add(new Location(7, 0), rock);

        assertEquals(8, amy.getLocation().getRow());
        assertEquals(0, amy.getLocation().getCol());
        amy.act();

        // the rock turn to blue and the barriar one disappear
        Color c = new Color(0, 0, 255);
        assertEquals(6, amy.getLocation().getRow());
        assertEquals(1, amy.getLocation().getCol());
        assertEquals(c, amy.getColor());
    }

    /**
    *Test when two horse face, eating.
    */
    public void testAct2 () {
        ActorWorld world = new ActorWorld();
        Horse amy = new Horse();
        Horse bob = new Horse();
        amy.setDirection(90);
        bob.setDirection(270);
        world.add(new Location(9, 3), amy);
        world.add(new Location(9, 7), bob);

        amy.act();
        bob.act();
        
        // bob ate amy!
        assertEquals(8, bob.getLocation().getRow());
        assertEquals(5, bob.getLocation().getCol());
    }
}
