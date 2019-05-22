package Controller;

import Model.Entry;
import Repository.MemoryRepo;

public class Controller
{
    private MemoryRepo memoryRepo;
    private Boolean authentication;

    public Controller()
    {
        this.memoryRepo = new MemoryRepo();
        this.authentication = false;
    }

    public Boolean getAuthentication()
    {
        return authentication;
    }

    @Loggable
    public void setAuthentication(Boolean authentication)
    {
        this.authentication = authentication;
    }

    @Secure
    @Loggable
    public void add(Entry entry) throws Exception
    {
        memoryRepo.add(entry);
    }

    @Secure
    @Loggable
    public void update(Entry entry) throws Exception
    {
        memoryRepo.update(entry);
    }

    @Secure
    @Loggable
    public void delete(Entry entry) throws Exception
    {
        memoryRepo.delete(entry);
    }

    @Secure
    @Loggable
    public Entry get(String account) throws Exception
    {
        return memoryRepo.get(account);
    }
}
