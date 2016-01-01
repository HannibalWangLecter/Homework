import java.awt.Image;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.awt.image.MemoryImageSource;

import java.io.File;
import java.io.IOException;
import java.io.FileInputStream;

import javax.imageio.ImageIO;
import imagereader.IImageIO;

/**
 * bitmap Io task
 */
public class ImplementImageIO implements IImageIO {

    // in x64 system, int occupy 4 byte 
    // 0x00ff ensure Compulsory type conversion
	private static final int FF = 0xff;

    private Image image;
    private int width;
    private int height;
    private int pixelBits;
    private int bitmapSize;
    private FileInputStream fp;

// auxiliary function
    private void init() {
        fp = null;
        width = 0;
        height = 0;
        pixelBits = 0;
        bitmapSize = 0;
    }


    private int bitOperate(byte[] data) {
        int i = 0;
        int offset = 0;
        int result = 0;
        for (i = 0; i < data.length; i++) {
            result = result | (((int)data[i]&FF) << offset);
            offset += 8;
        }
        return result;     
    }

    private int rgbOperate(byte[] rgb, int index) {
        int i = 0;
        int offset = 0;
        int result = (255 & FF) << 24;
        for (i = 0; i < 3; i++) {
            result = result | (((int)rgb[index+i]&FF) << offset);
            offset += 8;
        }
        return result;
    }

    /**
     * read BMP with binary filestream
     */
    public Image myRead(String fileName) {

        init();

        byte fourByteArray[] = new byte[4];
        byte twoByteArray[] = new byte[2];

        try {
            fp = new FileInputStream(fileName);
        } catch (Exception e) {
            System.out.println("File new fail, #1");
        }

        try {

            fp.skip(18);
            
            // byte #18-21  save width and heigth in pixels
            fp.read(fourByteArray, 0, 4);
            width = bitOperate(fourByteArray);

            // #22-25
            fp.read(fourByteArray, 0, 4);
            height = bitOperate(fourByteArray);

        } catch (Exception e) {
            System.out.println("File read height and width, #2");
        }

        try {
            // #28-29
            fp.skip(2);
            fp.read(twoByteArray,0,2);
            
            fp.skip(4);
            fp.read(fourByteArray,0,4);
            
            // bitmap size
            bitmapSize = bitOperate(fourByteArray);
            pixelBits = (((int)twoByteArray[1] & FF) << 8) | ((int)twoByteArray[0] & FF);            
        } catch (Exception e) {
            System.out.println("File infomation catch, #3");
        }        

        
        // Pixel alignment with "cover" to a multiple of 4 
        try {

            if (pixelBits != 24) {
                image = null;                
                System.out.println("Not realColor format , ##");
                // while it is realColor, a pixel occupies three bytes
            } else {    
                int col = 0;
                int row = 0; // for loop
                int pos = 0; // the current file pointer of pixelData
                int cover = ((bitmapSize / height) - width * 3) % 4;

                int pixelData[] = new int[height * width];
                
                // differ from pixel sizes !
                byte rgbData[] = new byte[bitmapSize];
                
                fp.skip(16);
                fp.read(rgbData, 0, bitmapSize);
                
                for (row = 0; row < height; row++) {
                    for (col = 0; col < width; col++) {
                        // from bottom to top , left to right
                        int t = width * (height - row) + col - width;
                        pixelData[t] = rgbOperate(rgbData, pos);
                        pos += 3;
                    }
                    pos += cover;
                }

                // to set value memory source
                MemoryImageSource ms = new MemoryImageSource(width, height, pixelData, 0, width);
                // use encapsulation toolkit
                image = Toolkit.getDefaultToolkit().createImage(ms); 
            }

            fp.close();
            return image;

        } catch (Exception e) {
            System.out.println("File translation fail, #4");
        }
        
        return null;
    }
    
    /**
     * save as format bmp
     */

    public Image myWrite(Image img, String fileName) {
            
        File imageFile = new File(fileName);

        int width = img.getWidth(null);
        int height = img.getHeight(null);

        // create a bufferedImage without alaph 
        BufferedImage bufImage = new BufferedImage(width, height, BufferedImage.TYPE_INT_BGR);

        try {
            bufImage.getGraphics().drawImage(img, 0, 0, width, height, null);
        } catch (Exception e) {
            e.printStackTrace();
        }

        // use the system api 
        try {
            // system requires exception handler
            ImageIO.write(bufImage, "bmp", imageFile);
        } catch (Exception e) {
            System.out.println("File writing, catch exception, #5");
        }
        
        return img;
    }

}
