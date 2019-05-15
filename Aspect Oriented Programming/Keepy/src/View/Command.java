package View;

public abstract class Command
{
    private String key;

    Command(String key)
    {
        this.key = key;
    }

    public abstract void execute();

    String getKey()
    {
        return this.key;
    }
}
