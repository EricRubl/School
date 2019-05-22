import View.View;

import java.io.IOException;
import java.util.logging.Logger;
import java.util.logging.FileHandler;
import java.util.logging.SimpleFormatter;

public class Keepy
{
    public static void main(String[] args)
    {
        Logger logger = Logger.getLogger("KeepyLogger");
        FileHandler fh;

        try
        {
            fh = new FileHandler("keepy.log");
            logger.addHandler(fh);
            SimpleFormatter formatter = new SimpleFormatter();
            fh.setFormatter(formatter);
            logger.setUseParentHandlers(false);

        } catch (SecurityException | IOException e)
        {
            e.printStackTrace();
        }

        View view = new View();
        view.run();
    }
}
