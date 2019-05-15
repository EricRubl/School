import Model.Entry;
import Repository.MemoryRepo;
import org.aspectj.lang.JoinPoint;
import org.aspectj.lang.annotation.After;
import org.aspectj.lang.annotation.Aspect;

@Aspect
public class Observer
{
    @After("execution(* Repository.MemoryRepo.add(..)) && args(entry)")
    public void addDB(JoinPoint joinPoint, Entry entry) throws Exception
    {
        MemoryRepo memoryRepo = (MemoryRepo) joinPoint.getTarget();
        memoryRepo.databaseRepo.addEntry(entry);
    }

    @After("execution(* Repository.MemoryRepo.update(..)) && args(entry)")
    public void updateDB(JoinPoint joinPoint, Entry entry) throws Exception
    {
        MemoryRepo memoryRepo = (MemoryRepo) joinPoint.getTarget();
        memoryRepo.databaseRepo.updateEntry(entry);
    }

    @After("execution(* Repository.MemoryRepo.delete(..)) && args(entry)")
    public void deleteDB(JoinPoint joinPoint, Entry entry) throws Exception
    {

        MemoryRepo memoryRepo = (MemoryRepo) joinPoint.getTarget();
        memoryRepo.databaseRepo.deleteEntry(entry);

    }
}
