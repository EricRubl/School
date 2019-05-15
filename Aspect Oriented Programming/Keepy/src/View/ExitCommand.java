package View;

public class ExitCommand extends Command
{

    ExitCommand(String key)
    {
        super(key);
    }

    @Override
    public void execute()
    {
        System.exit(0);
    }
}
