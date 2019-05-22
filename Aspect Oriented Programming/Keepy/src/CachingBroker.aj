import Model.Entry;
import Repository.MemoryRepo;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;

import java.util.Optional;

@Aspect
public class CachingBroker
{
    @Around("execution(* Repository.MemoryRepo.get(..)) && args(account)")
    public Entry getDB(ProceedingJoinPoint joinPoint, String account) throws Throwable
    {
        MemoryRepo memoryRepo = (MemoryRepo) joinPoint.getTarget();
        Optional<Entry> found = memoryRepo.entries.stream().filter(e -> e.getAccount().equals(account)).findFirst();

        if (found.isPresent())
        {
            return found.get();
        } else
        {
            Entry entry = (Entry) joinPoint.proceed();
            memoryRepo.entries.add(entry);
            return entry;
        }
    }
}
