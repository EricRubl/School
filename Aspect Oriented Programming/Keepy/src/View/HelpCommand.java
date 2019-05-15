package View;

import java.util.HashMap;

public class HelpCommand extends Command
{

    static private HashMap<String, String> commandMap = new HashMap<>();

    static
    {
        commandMap.put("add book <ISBN> <Title> <Author> <Price>", "Adds a new book to the list");
        commandMap.put("update book <ISBN> <Title> <Author> <Price>",
            "Updates an existing book, by ISBN");
        commandMap.put("delete book <ISBN>", "Removes a book, by ISBN");
        commandMap.put("add client <Name> <Date>",
            "Adds a new client to the list, date must be of DD-MM-YYYY format");
        commandMap.put("update client <Name> <Date>", "Updates an existing client, by ISBN");
        commandMap.put("delete client <Name>", "Removes a client, by name");
        commandMap.put("list books", "Prints all the books");
        commandMap.put("list clients", "Prints all the clients");
        commandMap.put("list purchases", "Prints all the purchases");
        commandMap
            .put("sell <ISBN> <Name>", "Sells a book to a client, adds a new purchase to the list");
        commandMap.put("backup", "Performs a backup of the current data to the disk");
        commandMap.put("restore", "Performs a restore of an older version of the data");
        commandMap.put("q / exit / quit", "Safely closes the app");

        commandMap.put("sort books", "Prints the books sorted by the number of purchases");
        commandMap
            .put("sort clients activity", "Prints the clients sorted by the number of purchases");
        commandMap
            .put("sort clients profit", "Prints the clients sorted by the amount of money spend");

        commandMap.put("filter books author", "Prints the books sorted by authors");
        commandMap.put("filter books price", "Prints the books sorted by prices");
        commandMap.put("filter books title", "Prints the books sorted by titles");
        commandMap.put("filter clients name", "Prints the clients sorted by names");
        commandMap.put("filter clients dob", "Prints the clients sorted by date of birth");
    }

    HelpCommand(String key)
    {
        super(key);
    }

    @Override
    public void execute()
    {
        String prettyPrinter = String.format("\t\t\t%-56s%s", "Command", "Description");
        System.out.println(prettyPrinter);
        commandMap.forEach((k, v) ->
        {
            String new_k = String.format("%-56s", k);
            System.out.println("\t\t" + new_k + v);
        });
    }
}
