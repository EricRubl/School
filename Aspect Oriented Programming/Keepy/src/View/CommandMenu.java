package View;

import Controller.Controller;
import Model.Entry;

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
        syntaxList.add(Pattern.compile("^\\s*(update)\\s*([0-9a-zA-Z]+)\\s*([0-9a-zA-Z]+)\\s*$"));
        syntaxList.add(Pattern.compile("^\\s*(get)\\s*([0-9a-zA-Z]+)\\s*$"));
        syntaxList.add(Pattern.compile("^\\s*(delete)\\s*([0-9a-zA-Z]+)\\s*$"));
        syntaxList.add(Pattern.compile("^\\s*(login)\\s*([0-9a-zA-Z]+)\\s*$"));
        syntaxList.add(Pattern.compile("^\\s*(logout)\\s*$"));
    }

    CommandMenu()
    {
        this.commandSet = new HashMap<>();
        this.controller = new Controller();
    }

    void addCommand(Command command)
    {
        this.commandSet.put(command.getKey(), command);
    }


    private void filterCommand(ArrayList<String> arguments) throws Exception
    {
        try
        {
            switch (arguments.get(0))
            {
                case "add":
                {
                    controller.add(new Entry(arguments.get(1), arguments.get(2)));
                    return;
                }
                case "delete":
                {
                    controller.delete(new Entry(arguments.get(1), ""));
                    return;
                }
                case "update":
                {
                    controller.update(new Entry(arguments.get(1), arguments.get(2)));
                }
                case "get":
                {
                    System.out.println(controller.get(arguments.get(1)));
                    return;
                }
                case "login":
                {
                    if(arguments.get(1).equals("secret"))
                    {
                        controller.setAuthentication(true);
                        return;
                    }
                    throw new Exception("Incorrect password");
                }
                case "logout":
                {
                    controller.setAuthentication(false);
                    return;
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