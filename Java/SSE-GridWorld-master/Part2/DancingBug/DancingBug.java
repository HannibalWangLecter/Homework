/* 
 * GridWorld Case Study
 * @author kinsang
 */

import info.gridworld.actor.Bug;

public class DancingBug extends Bug
{
    private int steps;
    private int length;
    private int [] danceTime;

    /*
     * Constructs a Dancing bug
     * @param length the side length
     */
    public DancingBug(int []times)
    {
        steps = 0;
        length = times.length;  // length cp
        danceTime = new int[length];  // initialised

        int i = 0;
        for (i = 0; i < length; i++) {
            danceTime[i]=times[i];
        }
    }

    /**
     * Moves to the next location of the Dancing.
     */
    public void act()
    {
        // dance times
        int i = 0;
        for (i = 0; i < danceTime[steps];i++) {
            turn();
        }

        //basic move as a bug
        if (canMove()) {
            move();
            steps++;
        } else {
            turn();
        }

        if (steps==length) {
            steps=0; // reset the length
        }
        
    }
}
