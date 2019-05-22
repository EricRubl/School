import Controller.Controller;
import org.aspectj.lang.ProceedingJoinPoint;
import org.aspectj.lang.annotation.Around;
import org.aspectj.lang.annotation.Aspect;

@Aspect
public class AuthBroker
{
    @Around("@annotation(Controller.Secure)")
    public Object checkAuth(ProceedingJoinPoint joinPoint) throws Throwable
    {
        Controller controller = (Controller) joinPoint.getTarget();

        if(controller.getAuthentication())
        {
            return joinPoint.proceed();
        }
        else
        {
            throw new Exception("Operation not permitted due to security reasons!");
        }
    }
}
