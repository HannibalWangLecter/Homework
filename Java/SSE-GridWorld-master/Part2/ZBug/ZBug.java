/* 
 * GridWorld Case Study
 * @author kinsang
 */

import info.gridworld.actor.Bug;

public class ZBug extends Bug
{
    private int steps;
    private int state;
    private int sideLength;

    /**
     * Constructs a Z bug
     * @param length the side length
     * @param state the different part of image "Z"
     */
    public ZBug(int length)
    {
        steps = 0;
        state = 0;
        sideLength = length;
    }

    /**
     * Moves to the next location of the Z.
     */
    public void act()
    {
        /* State0  turn to east*/
        if (state == 0) {
            turn();
            turn();
            state++;
        }

        /*
         *State 1 3 5 are the side of "Z"
        */
        if ((steps < sideLength) && (state%2 == 1) && canMove())
        {
            move();
            steps++;
            if (steps == sideLength) {
                state++;
                steps = 0;
            }
        }

        /* The first angle*/
        if (state == 2) {
            turn();
            turn();
            turn();
            state++;
        }

        /*The Second angle*/
        if (state == 4) {
            int i = 0;
            for(i=0;i<5;i++) {
                turn();
            }
            state++;
        }
    }
}
