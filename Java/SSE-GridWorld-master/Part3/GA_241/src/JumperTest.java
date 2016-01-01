import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;

import info.gridworld.actor.*;
import info.gridworld.grid.Grid;
import info.gridworld.grid.Location;

import java.awt.Color;

public final class JumperTest extends TestCase {

    public JumperTest() {

    }

    public static void main(String args[])
    {
        junit.textui.TestRunner.run(JumperTest.class);
    }

    /**
    *Task to test the basic act,move through a rock and replace a flower
    */
    public void testAct() {
        ActorWorld world = new ActorWorld();
        Jumper amy = new Jumper(Color.CYAN);
        Rock rock = new Rock();
        Flower flower = new Flower();
        amy.setDirection(Location.NORTH);
        world.add(new Location(3,3), amy);
        world.add(new Location(2,3), rock);
        world.add(new Location(1,3), flower);
        amy.act();
        Grid gra = amy.getGrid();
        Grid grb = flower.getGrid();
        assertEquals(1, amy.getLocation().getRow());
        assertEquals(3, amy.getLocation().getCol());
        assertEquals(true, grb == null);
    }

    /**
    *Task to test the basic act,stopped by a rock and move only a grid
    */
    public void testAct1() {
        ActorWorld world = new ActorWorld();
        Jumper amy = new Jumper(Color.CYAN);
        Rock rock = new Rock();
        Flower flower = new Flower();
        amy.setDirection(Location.NORTH);
        world.add(new Location(3,3), amy);
        world.add(new Location(1,3), rock);
        amy.act();
        assertEquals(2, amy.getLocation().getRow());
        assertEquals(3, amy.getLocation().getCol());        
    }

    /**
    *Task to test the basic act,stopped by two rock and turn
    */
    public void testActTurn() {
        ActorWorld world = new ActorWorld();
        Jumper amy = new Jumper(Color.CYAN);
        Rock rock = new Rock();
        Rock rock2 = new Rock();

        amy.setDirection(Location.NORTH);
        world.add(new Location(0,3), amy);
        amy.act();
        assertEquals(0, amy.getLocation().getRow());
        assertEquals(3, amy.getLocation().getCol());
        assertEquals(Location.NORTHEAST, amy.getDirection());        
    }

    /**
    *Task to test the basic act,when face to the border!
    */
    public void testActBorder() {

        ActorWorld world = new ActorWorld();
        Jumper amy = new Jumper(Color.CYAN);
        amy.setDirection(Location.NORTH);
        world.add(new Location(1,3), amy);
        amy.act();
        assertEquals(0, amy.getLocation().getRow());
        assertEquals(3, amy.getLocation().getCol());
        assertEquals(Location.NORTH, amy.getDirection());        
    }

    /**
    *Task to test the basic act,when two Jumpers meet
    *Distance: one grid
    */
    public void testActFacing() {

        ActorWorld world = new ActorWorld();
        Jumper amy = new Jumper(Color.CYAN);
        Jumper bob = new Jumper(Color.BLUE);
        amy.setDirection(Location.NORTH);
        bob.setDirection(Location.SOUTH);
        world.add(new Location(1,3), bob);
        world.add(new Location(3,3), amy);
        amy.act();
        bob.act();

        // check amy's position
        assertEquals(2, amy.getLocation().getRow());
        assertEquals(3, amy.getLocation().getCol());
        assertEquals(Location.NORTH, amy.getDirection());

        // check bob's position
        assertEquals(3, bob.getLocation().getRow());
        assertEquals(3, bob.getLocation().getCol());
        assertEquals(Location.SOUTH, bob.getDirection());               
    }

    public void testActFacingLong() {

        ActorWorld world = new ActorWorld();
        Jumper amy = new Jumper(Color.CYAN);
        Jumper bob = new Jumper(Color.BLUE);
        amy.setDirection(Location.NORTH);
        bob.setDirection(Location.SOUTH);
        world.add(new Location(1,3), bob);
        world.add(new Location(4,3), amy);
        amy.act();
        bob.act();

        // check amy's position
        assertEquals(2, amy.getLocation().getRow());
        assertEquals(3, amy.getLocation().getCol());
        assertEquals(Location.NORTH, amy.getDirection());

        // check bob's position
        assertEquals(3, bob.getLocation().getRow());
        assertEquals(3, bob.getLocation().getCol());
        assertEquals(Location.SOUTH, bob.getDirection());               
    }

}
