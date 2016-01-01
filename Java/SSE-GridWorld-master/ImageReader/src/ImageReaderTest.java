import static org.junit.Assert.*;

import java.awt.Image;
import java.awt.image.BufferedImage;
import java.io.FileInputStream;
import java.io.IOException;

import javax.imageio.ImageIO;

import org.junit.Before;
import org.junit.Test;

import java.util.*;

public class ImageReaderTest {

    @Test
    public void testBlue() throws IOException { 

        System.out.println("File reading, writing, catch exception, #1");

        ImplementImageIO testerIO = new ImplementImageIO();
        Image image= testerIO.myRead("1.bmp");

        //filter process
        ImplementImageProcessor processor = new ImplementImageProcessor();
        Image filter = processor.showChanelB(image);
        BufferedImage test = new BufferedImage(filter.getWidth(null), filter.getHeight(null), BufferedImage.TYPE_INT_BGR);
        test.getGraphics().drawImage(filter, 0, 0, filter.getWidth(null), filter.getHeight(null), null);
        testerIO.myWrite(test, "testPhoto/1_blue_test.bmp");

        BufferedImage goal = ImageIO.read(new FileInputStream("goal/1_blue_goal.bmp"));
        BufferedImage filterBlue = ImageIO.read(new FileInputStream("testPhoto/1_blue_test.bmp"));

        Random random = new Random();
        int width = Math.abs(random.nextInt())%goal.getWidth(null);
        int height = Math.abs(random.nextInt())%goal.getHeight(null);

        System.out.println("Random test pixels, width,#1 " + width);
        System.out.println("Random test pixels, height,#2 " + height);
        System.out.println("");
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                assertEquals(true, (goal.getRGB(i, j) == filterBlue.getRGB(i, j)));
            }
        }
    }

    @Test
    public void testGray() throws IOException { 

        System.out.println("File reading, writing, catch exception, #2");

        ImplementImageIO testerIO = new ImplementImageIO();
        Image image= testerIO.myRead("2.bmp");

        //filter process
        ImplementImageProcessor processor = new ImplementImageProcessor();
        Image filter = processor.showGray(image);
        BufferedImage test = new BufferedImage(filter.getWidth(null), filter.getHeight(null), BufferedImage.TYPE_INT_BGR);
        test.getGraphics().drawImage(filter, 0, 0, filter.getWidth(null), filter.getHeight(null), null);
        testerIO.myWrite(test, "testPhoto/2_gray_test.bmp");

        BufferedImage goal = ImageIO.read(new FileInputStream("goal/2_gray_goal.bmp"));
        BufferedImage filterGray = ImageIO.read(new FileInputStream("testPhoto/2_gray_test.bmp"));

        Random random = new Random();
        int width = Math.abs(random.nextInt())%goal.getWidth(null);
        int height = Math.abs(random.nextInt())%goal.getHeight(null);

        System.out.println("Random test pixels, width,#1 " + width);
        System.out.println("Random test pixels, height,#2 " + height);
        System.out.println("");
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                assertEquals(true, (goal.getRGB(i, j) == filterGray.getRGB(i, j)));
            }
        }
    }

}
