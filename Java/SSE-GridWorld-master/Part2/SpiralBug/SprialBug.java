/* 
 * GridWorld Case Study
 * @author kinsang
 */

import info.gridworld.actor.Bug;

public class SprialBug extends Bug
{
    private int steps;
    private int sideLength;

    /*
     * Constructs a Sprial bug
     * @param length the side length
     */
    public SprialBug(int length)
    {
        steps = 0; // init
        sideLength = length; //length
    }

    /**
     * Moves to the next location of the Sprial.
     */
    public void act()
    {
        if (steps < sideLength && canMove())
        {
            move();
            steps++;
        }
        else
        {
            turn(); // change the angle
            turn();
            sideLength += 2; // to make the sprial
            steps = 0; // to reset the length
        }
    }
}
