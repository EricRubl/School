package Repository;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

class DatabaseConnector
{
    private Connection connection;

    private Connection getNewConnection() throws SQLException, ClassNotFoundException
    {
        Connection conn;
        Class.forName("org.postgresql.Driver");
        conn = DriverManager.getConnection("jdbc:postgresql://localhost:5432/keepy");
        return conn;
    }

    Connection getConnection() throws Exception
    {
        try
        {
            if (connection == null || connection.isClosed())
            {
                connection = getNewConnection();
            }
            return connection;
        }
        catch (SQLException | ClassNotFoundException ex)
        {
            throw new Exception("Can't connect to the database :(");
        }
    }
}
