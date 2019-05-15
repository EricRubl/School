package Repository;

import Model.Entry;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class DatabaseRepo
{
    private DatabaseConnector databaseConnector;

    DatabaseRepo()
    {
        this.databaseConnector = new DatabaseConnector();
    }

    public void addEntry(Entry entry) throws Exception
    {
        Connection connection = databaseConnector.getConnection();

        try
        {
            PreparedStatement preparedStatement = connection.prepareStatement("INSERT INTO entries(account, password) VALUES (?, ?)");
            preparedStatement.setString(1, entry.getAccount());
            preparedStatement.setString(2, entry.getPassword());
            preparedStatement.executeUpdate();
        }
        catch (SQLException ex)
        {
            throw new Exception("Database error :(");
        }
    }

    public void updateEntry(Entry entry) throws Exception
    {
        Connection connection = databaseConnector.getConnection();

        try
        {
            PreparedStatement preparedStatement = connection.prepareStatement("UPDATE entries SET password=? WHERE account=?");
            preparedStatement.setString(1, entry.getAccount());
            preparedStatement.setString(2, entry.getPassword());
            preparedStatement.executeUpdate();
        }
        catch (SQLException ex)
        {
            throw new Exception("Database error :(");
        }
    }

    public void deleteEntry(Entry entry) throws Exception
    {
        Connection connection = databaseConnector.getConnection();

        try
        {
            PreparedStatement preparedStatement = connection.prepareStatement("DELETE FROM entries WHERE account=?");
            preparedStatement.setString(1, entry.getAccount());
            preparedStatement.executeUpdate();
        }
        catch (SQLException ex)
        {
            throw new Exception("Database error :(");
        }
    }

    Entry getEntry(String account) throws Exception
    {
        Connection connection = databaseConnector.getConnection();

        try
        {
            PreparedStatement preparedStatement = connection.prepareStatement("SELECT * FROM entries WHERE account=?");
            preparedStatement.setString(1, account);
            ResultSet resultSet = preparedStatement.executeQuery();

            resultSet.next();

            return new Entry(resultSet.getString("Account"), resultSet.getString("Password"));
        }
        catch (SQLException ex)
        {
            throw new Exception("Database error :(");
        }
    }
}
