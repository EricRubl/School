package View;

public class View
{
    private static double begin;

    public View()
    {
        begin = System.currentTimeMillis();
        System.out.println("Loading...");
    }

    public void run()
    {
        CommandMenu menu = new CommandMenu();
        menu.addCommand(new ExitCommand("exit"));
        menu.addCommand(new HelpCommand("help"));
        double end = System.currentTimeMillis();
        System.out.println(String.format("Loaded in: %.3f seconds", ((end - begin) / 1000)));
        menu.show();
    }
}
