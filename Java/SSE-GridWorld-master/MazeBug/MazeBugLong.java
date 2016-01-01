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

    // my variable
    private int direction[] = new int[4];
    private int usedDir;
	/**
	 * Constructs a box bug that traces a square of a given side length
	 * 
	 * @param length
	 *            the side length
	 */
	public MazeBug() {
		setColor(Color.GREEN);
		last = new Location(0, 0);
        int i = 0;
        for (i = 0; i < 4;i++) {
            direction[i] = 1;
        }
        direction[2] = 0;
        usedDir = 0;
        ArrayList<Location> valid = new ArrayList<Location>();
        crossLocation.push(valid);
	}


    /**
     *calcualting the relative angle
     */
    private int calcualteAngle(Location loc, int direction) {
        int dir = getLocation().getDirectionToward(loc);
        int angle = direction - dir;
        if (angle < 0) {
            angle += 360;
        }
        angle /= 90;
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
            ArrayList<Location> newNode = new ArrayList<Location> ();
            newNode.add(getLocation());
            crossLocation.push(newNode);
            last = getLocation();

            if (getValid(getLocation()).size() > 1) {
                int curDir = getDirection();
                int to = calcualteAngle(next, curDir);
                direction[to]++;
                usedDir = to;
            }

			move();
			//increase step count when move
			stepCount++;
		} else {
            // can not move on this node and have to traces back
            next = last;
            if (getValid(getLocation()).size() > 1) {
                direction[usedDir]--;
            }
            move();
            stepCount++;
            crossLocation.pop();

            if (crossLocation.peek().size() != 0) {
                last = crossLocation.peek().get(0);
            }
        } 
	}

    /**
     *auxiliary function reachEnd
     */

    private boolean reachEnd(Actor a) {
        if (a instanceof Rock) {
            if (a.getColor().getRed() == Color.RED.getRed()) {
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
        for (i = 0; i < 4; i++) {
            Location dirLoc = loc.getAdjacentLocation(getDirection()+Location.LEFT*i);
            if (gr.isValid(dirLoc)) {
                Actor a = gr.get(dirLoc);
                if (reachEnd(a)) {
                    isEnd = true;
                    valid.add(dirLoc);
                } else if (a == null) {
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
		ArrayList<Location> nextArray = getValid(getLocation());
        Grid<Actor> gr = getGrid();
        if (gr == null) {
            return false;
        } else if (nextArray.size() == 0) {
            return false;
        } else {
            int i = 0;
            int max = 0;
            for (Location loc : nextArray) {
                Actor a = gr.get(loc);

                if (a instanceof Rock) {
                    isEnd = true;
                    next = getLocation();
                    return true;
                }
                int curDir = getDirection();
                int to = calcualteAngle(loc, curDir);
                if (direction[to] > direction[max]) {
                    max = i;
                }
                i++;
            }
            next = nextArray.get(max);
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
		} else
			removeSelfFromGrid();
		Flower flower = new Flower(getColor());
		flower.putSelfInGrid(gr, loc);
	}
}

