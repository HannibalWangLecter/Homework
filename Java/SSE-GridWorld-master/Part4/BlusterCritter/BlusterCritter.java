/* 
 * Part 4
 * @author Kinsang 
 */

import info.gridworld.actor.*;
import info.gridworld.grid.*;

import java.util.ArrayList;
import java.awt.Color;

/**
 * A <code>ChameleonCritterKid</code> takes on the color of neighboring actors as
 * it moves through the grid. <br />
 */
public final class BlusterCritter extends Critter {

    private int courage;
    private static final double DARKENING_FACTOR = 0.05;

    public BlusterCritter(int c) {
        courage = c;
    }

    public void darken() {
        Color c = getColor();
        int red = (int) (c.getRed() * (1 - DARKENING_FACTOR));
        int green = (int) (c.getGreen() * (1 - DARKENING_FACTOR));
        int blue = (int) (c.getBlue() * (1 - DARKENING_FACTOR));

        red = red>1?red:1;
        green = green>1?green:1;
        blue = blue>1?blue:1;

        setColor(new Color(red, green, blue));
    }


    public void brighten() {
        Color c = getColor();
        int red = (int) (c.getRed() * (1 + DARKENING_FACTOR));
        int green = (int) (c.getGreen() * (1 + DARKENING_FACTOR));
        int blue = (int) (c.getBlue() * (1 + DARKENING_FACTOR));

        red = red<=255?red:255;
        green = green<=255?green:255;
        blue = blue<=255?blue:255;

        setColor(new Color(red, green, blue));
    }

    //override the processActors method, to change color as required
    public void processActors(ArrayList<Actor> actors) {
        int n = actors.size();

        if (n < courage) {
            brighten();
        } else {
            darken();
        }
    }

    public ArrayList<Actor> getActors() {
        Grid gr = getGrid();
        ArrayList<Actor> actors = new ArrayList<Actor>();
        
        Location curLoc = getLocation();
        int curRow = curLoc.getRow();
        int curCol = curLoc.getCol();

        // there is isValid() to make sure the grid is in gridworld
        int borderLeft = curCol-2;
        int borderRight = curCol+2;
        int borderUp = curRow-2;
        int borderDown = curRow+2;

        int i = 0;
        int j = 0;

        for (i = borderLeft; i <= borderRight; i++) {
            for (j = borderUp; j <= borderDown; j++) {
                if (j != curRow && i != curCol) {
                    Location loc = new Location(j, i);
                    if (gr.isValid(loc)) {
                        Actor a = getGrid().get(loc);
                        if (a instanceof Critter) {
                            actors.add(a);
                        }
                    }
                }
            }
        }

        return actors;
    } 
}
