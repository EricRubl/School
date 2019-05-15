package Model;

public class Entry {
    private String account;
    private String password;

    public Entry(String account, String password)
    {
        this.account = account;
        this.password = password;
    }

    public String getAccount() {
        return account;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    @Override
    public String toString()
    {
        return account + " | " + password;
    }
}
