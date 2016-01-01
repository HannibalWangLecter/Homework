import java.awt.Image;
import java.awt.Toolkit;
import java.awt.image.RGBImageFilter;
import java.awt.image.FilteredImageSource;

import imagereader.IImageProcessor;

//implements a filter for the set of interface methods that of auxiliary
/*
 * Each filter calls a corresponding auxiliary method.
*/
public class ImplementImageProcessor implements IImageProcessor {
    
    private Toolkit kit = Toolkit.getDefaultToolkit(); 

    public Image showChanelR(Image img) {
        RedFilter red = new RedFilter();
        FilteredImageSource src = new FilteredImageSource(img.getSource(),red);
        return kit.createImage(src);
    }

    public Image showChanelG(Image img) {
        GreenFilter green = new GreenFilter();
        FilteredImageSource src = new FilteredImageSource(img.getSource(),green);
        return kit.createImage(src);
    }

    public Image showChanelB(Image img) {
        BlueFilter blue = new BlueFilter();
        FilteredImageSource src = new FilteredImageSource(img.getSource(),blue);
        return kit.createImage(src);
    }

    public Image showGray(Image img) {
        GrayFilter gray = new GrayFilter();
        FilteredImageSource src = new FilteredImageSource(img.getSource(),gray);
        return kit.createImage(src);
    }

}
