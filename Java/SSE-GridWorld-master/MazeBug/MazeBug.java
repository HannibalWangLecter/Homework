import info.gridworld.actor.Actor;
import info.gridworld.actor.Bug;
import info.gridworld.actor.Flower;
import info.gridworld.grid.*;
import info.gridworld.actor.*;

import java.awt.Color;
import java.util.ArrayList;
import java.util.Random;
import java.util.Stack;

import javax.swing.JOptionPane;

/**
 * A <code>MazeBug</code> can find its way in a maze. <br />
 * Dfs algorithm with Stack
 */
public class MazeBug extends Bug {
	public Location next;
	public Location last;
	public boolean isEnd = false;
	public Stack<ArrayList<Location>> crossLocation = new Stack<ArrayList<Location>>();
	public Integer stepCount = 0;
	boolean hasShown = false;//final message has been shown

	/**
	 * Constructs a box bug that traces a square of a given side length
	 * 
	 * @param length
	 *            the side length
	 */
	public MazeBug() {
		setColor(Color.GREEN);
		last = new Location(0, 0);
	}


    /**
     *calcualting the relative angle
     */
    private int calcualteAngle(Location loc, int direction) {
        int dir = getLocation().getDirectionToward(loc);
        int angle = direction - dir;
        angle = ((angle + 360)%360)/90;
        return angle;
    } 

	/**
	 * Moves to the next location of the square.
	 */
	public void act() {
		boolean willMove = canMove();
		if (isEnd == true) {
		//to show step count when reach the goal		
			if (hasShown == false) {
				String msg = stepCount.toString() + " steps";
				JOptionPane.showMessageDialog(null, msg);
				hasShown = true;
			}
		} else if (willMove) {
		    // still have certain unaccessed way
		    Location curLoc = getLocation();
            ArrayList<Location> newNode = new ArrayList<Location> ();
            newNode.add(curLoc);
            crossLocation.push(newNode);
            
			move();
			last = curLoc;
			//increase step count when move
			stepCount++;
		} else {
            // can not move forward on this node and have to traces back
            if (!crossLocation.empty()) {            
                crossLocation.pop();
            }
            
            next = last;
            move();
            stepCount++;
            
            if (!crossLocation.empty()) {
                ArrayList<Location> locList = crossLocation.peek();
                last = locList.get(0);
            } else {
                // do nothing - it return to start.
            }
        } 
	}

    /**
     *auxiliary function reachEnd
     */

    private boolean reachEnd(Actor a) {
        if (a instanceof Rock) {
            if (a.getColor().getRed() == 255) {
                return true;
            }
        }
        return false;
    } 

	/**
	 * Find all positions that can be move to.
	 * 
	 * @param loc
	 *            the location to detect.
	 * @return List of positions.
	 */
	public ArrayList<Location> getValid(Location loc) {
		Grid<Actor> gr = getGrid();
		if (gr == null)
			return null;
		ArrayList<Location> valid = new ArrayList<Location>();
        int i = 0;
        for (i = 0; i < 360; i+=90) {
            // move forward left right and back
            Location dirLoc = loc.getAdjacentLocation(getDirection()+i);
            if (gr.isValid(dirLoc)) {
                Actor a = gr.get(dirLoc);
                if (reachEnd(a)) {
                    isEnd = true;
                    valid.add(dirLoc);
                } else if (a == null) {
                    // if there is a flower, it means node accessed!!!
                    valid.add(dirLoc);
                }
            }
        }
		return valid;
	}

	/**
	 * Tests whether this bug can move forward into a location that is empty or
	 * contains a flower.
	 * 
	 * @return true if this bug can move.
	 */
	public boolean canMove() {
	
	    Grid<Actor> gr = getGrid();
		ArrayList<Location> validArray = getValid(getLocation());

        if (gr == null || validArray.isEmpty() || isEnd) {
            return false;
        } else {
            Random rand = new Random(23);
            int ran = rand.nextInt(validArray.size());
            next = validArray.get(ran);
            return true;
        }
	}
	/**
	 * Moves the bug forward, putting a flower into the location it previously
	 * occupied.
	 */
	public void move() {
		Grid<Actor> gr = getGrid();
		if (gr == null)
			return;
		Location loc = getLocation();
		if (gr.isValid(next)) {
			setDirection(getLocation().getDirectionToward(next));
			moveTo(next);
		} else {
			removeSelfFromGrid();
		}
		Flower flower = new Flower(getColor());
		flower.putSelfInGrid(gr, loc);
	}
}

