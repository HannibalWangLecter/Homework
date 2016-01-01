/**
  *The jumper will firstly jump 2 steps.
  *If the 2 steps ahead has flowers or is empty, jump 2 steps
  *else if 2 steps ahead has bug,rock, or out of grid, and
  *     1 step ahead is flower or empty, jump 1 step
  *else turn
  */

import info.gridworld.grid.Grid;
import info.gridworld.actor.*;
import info.gridworld.grid.Location;
import java.awt.Color;


public class Jumper extends Bug
{
    /**
     * Constructs a red Jumper in default.
     */
    public Jumper()
    {
        setColor(Color.RED);
    }

    /**
     * Constructs a bug of a given color.
     */
    public Jumper(Color bugColor)
    {
        setColor(bugColor);
    }

    /**
     * Moves if it can move, turns otherwise.
     */
    public void act()
    {
        int steps = judgeJumperMoveStep();

        // get direction and jumper`s location
        int direction = getDirection();
        Location currLoc = getLocation();
        
        //get the location that one step ahead the jumper
        Location oneStepAhead = currLoc.getAdjacentLocation(direction); 

        if (steps == 0)
        {
            turn();
            return;
        }
        else if (steps == 1)
        {
            moveTo(oneStepAhead);
        }
        else
        {
            //get the location that two steps ahead the jumper
            Location twoStepsAhead = oneStepAhead.getAdjacentLocation(direction);
            moveTo(twoStepsAhead);
        }
    }



    /**
     * Tests whether this bug can move forward into a location
     * if it can jump 2 steps, return 2
     * if it can jump only 1 steps, return 1
     * if it cannot jump, return 0
     */
    public int judgeJumperMoveStep()
    {
        Grid<Actor> gr = getGrid();
        if (gr == null)
            return 0;

        // get direction and jumper`s location
        int direction = getDirection();
        Location loc = getLocation();
        
        //get the location that one step ahead the jumper
        Location oneStepAhead = loc.getAdjacentLocation(direction); 
        //get the location that two steps ahead the jumper
        Location twoStepsAhead = oneStepAhead.getAdjacentLocation(direction);

        /**
          *firstly, try to jump two steps
          *judge two steps ahead is valid or not:
          *  only have flower or empty
          */
        if (judge(twoStepsAhead))
        {
            return 2;
        }
        /**
         *if it can not move 2 steps ahead
         */
        else
        {
            /**
              *judge whether it can move 1 steps:
              * one steps ahead is flower or empty
              */
            if (judge(oneStepAhead))
            {
                 return 1;
            }
            else
            {
                return 0;
            }
        }
    }

    public boolean judge(Location location)
    {
        Grid<Actor> gr = getGrid();
        if (gr == null)
            return false;
        if (gr.isValid(location))
        {
            Actor actor = gr.get(location);
            if (actor instanceof Flower || actor == null)
                return true;
        }
        return false;
    }

}
