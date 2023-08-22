import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class StudentQueries {
    private static Connection connection;
    private static PreparedStatement addStudent;

    public static void addStudent(String firstName, String lastName, String studentID) {
        connection = DBConnection.getConnection();
        try {
            addStudent = connection.prepareStatement("INSERT INTO app.student (firstname, lastname, studentid) VALUES (?, ?, ?)");
            addStudent.setString(1, firstName);
            addStudent.setString(2, lastName);
            addStudent.setString(3, studentID);
            addStudent.executeUpdate();
        } catch(SQLException sqlException) {
            sqlException.printStackTrace();
        }
    }
}
