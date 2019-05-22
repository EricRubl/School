import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;
import java.util.logging.Logger;

@Aspect
public class Loggy {
    @Around("@annotation(Controller.Loggable)")
    public Object log(ProceedingJoinPoint joinPoint) throws Throwable
    {
        Object[] args = joinPoint.getArgs();
        Object result = joinPoint.proceed(args);
        Logger logger = Logger.getLogger("KeepyLogger");
        logger.info("Method: " + joinPoint.getSignature());
        return result;
    }
}
