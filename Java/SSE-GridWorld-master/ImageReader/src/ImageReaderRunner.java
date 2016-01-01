/**
 * ImageReader runner
 */

import imagereader.Runner;

public final class ImageReaderRunner {

    private ImageReaderRunner() {

    }

    public static void main(String[] args){  
        ImplementImageIO imageioer = new ImplementImageIO();  
        ImplementImageProcessor processor = new ImplementImageProcessor();  
        Runner.run(imageioer, processor);  
    }

}
