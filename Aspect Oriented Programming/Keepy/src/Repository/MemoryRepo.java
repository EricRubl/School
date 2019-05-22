package Repository;

import Model.Entry;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class MemoryRepo
{
    public List<Entry> entries;
    public DatabaseRepo databaseRepo;

    public MemoryRepo()
    {
        this.databaseRepo = new DatabaseRepo();
        this.entries = new ArrayList<>();
    }

    public void add(Entry entry) throws Exception
    {
        if(entries.stream().anyMatch(e -> e.equals(entry)))
        {
            throw new Exception("Duplicate entry!");
        }

        entries.add(entry);
    }

    public void update(Entry entry) throws Exception
    {
        if(entries.stream().noneMatch(e -> e.getAccount().equals(entry.getAccount())))
        {
            throw new Exception("Entry does not exist!");
        }

        entries.stream().filter(e -> e.getAccount().equals(entry.getAccount())).forEach(e -> e.setPassword(entry.getPassword()));
    }

    public void delete(Entry entry) throws Exception
    {
        if(entries.stream().noneMatch(e -> e.getAccount().equals(entry.getAccount())))
        {
            throw new Exception("Entry does not exist!");
        }

        entries = entries.stream().filter(e -> e.equals(entry)).collect(Collectors.toList());
    }

    public Entry get(String account) throws Exception
    {
        try
        {
            return databaseRepo.getEntry(account);
        } catch (Exception e)
        {
            throw new Exception("Entry does not exist!");
        }

    }
}
