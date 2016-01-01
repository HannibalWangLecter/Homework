/* 
 * GridWorld Case Study
 * @author kinsang
 */

import info.gridworld.actor.Bug;

public class CircleBug extends Bug
{
    private int steps;
    private int sideLength;

    /*
     * Constructs a circle bug
     * @param length the side length
     */
    public CircleBug(int length)
    {
        steps = 0;  // initialised
        sideLength = length;
    }

    /**
     * Moves to the next location of the circle.
     */
    public void act()
    {
        if (steps < sideLength && canMove())
        {
            move();
            steps++; // basic move
        }
        else
        {
            turn();  // turn 
            steps = 0;  // reset
        }
    }
}
