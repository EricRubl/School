import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;

@Aspect
public class PerformanceMonitoring
{
    @Around("execution(* Repository.DatabaseRepo.*(..))")
    public Object logTime(ProceedingJoinPoint joinPoint) throws Throwable {
        final long start, end;
        Object[] args = joinPoint.getArgs();
        start = System.nanoTime();
        Object result = joinPoint.proceed(args);
        end = System.nanoTime();
        System.out.println("Method: " + joinPoint.getSignature() + " " + (end - start) / 1000 / 1000 + " ms");
        return result;
    }
}