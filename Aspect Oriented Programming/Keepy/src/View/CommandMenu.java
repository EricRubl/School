package View;

import Controller.Controller;

import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

class CommandMenu
{
    private static ArrayList<Pattern> syntaxList = new ArrayList<>();
    private Map<String, Command> commandSet;
    private Controller controller;

    static
    {
        syntaxList.add(Pattern.compile("^\\s*(add)\\s*([0-9a-zA-Z]+)\\s*([0-9a-zA-Z]+)\\s*$"));
        syntaxList.add(Pattern.compile("^\\s*(get)\\s*([0-9a-zA-Z]+)\\s*$"));
    }

    CommandMenu()
    {
        this.commandSet = new HashMap<>();
        this.controller = new Controller();
        controller.setAuthentication(true);
    }

    void addCommand(Command command)
    {
        this.commandSet.put(command.getKey(), command);
    }

    private <T> void printArrayList(List<T> list)
    {
        if (list == null)
        {
            return;
        }
        for (T i : list)
        {
            System.out.println(i);
        }
    }


    private void filterCommand(ArrayList<String> arguments) throws Exception
    {
        try
        {
            switch (arguments.get(0))
            {
                case "add":
                {
                    break;
                }
                case "delete":
                {
                    break;
                }
                case "update":
                {
                    break;
                }
                case "get":
                {
                    System.out.println(controller.get(arguments.get(1)));
                }
            }
        }
        catch (Exception e)
        {
            System.err.println(e.getMessage());
            return;
        }

        throw new Exception("Invalid Command!");
    }

    private void executeCommand(String inputString) throws Exception
    {
        for (Pattern pattern : syntaxList)
        {
            Matcher matcher = pattern.matcher(inputString);
            if (matcher.find())
            {
                ArrayList<String> arguments = new ArrayList<>();
                for (int i = 1; i <= matcher.groupCount(); ++i)
                {
                    arguments.add(matcher.group(i));
                }
                filterCommand(arguments);
                return;
            }
        }
        throw new Exception("Invalid Command!");
    }

    void show()
    {
        Scanner input = new Scanner(System.in);
        while (true)
        {
            System.out.print("-> ");
            String inputString = input.nextLine();
            if (inputString.equals("q"))
            {
                System.exit(0);
            }

            Command command = commandSet.get(inputString);

            if (command == null)
            {
                try
                {
                    executeCommand(inputString);
                } catch (Exception e)
                {
                    System.out.println("Invalid command. Type 'help' for more details about the command");
                }
                continue;
            }
            command.execute();
        }
    }
}