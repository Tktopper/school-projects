import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

public class CourseQueries {
    private static Connection connection;
    private static PreparedStatement addCourse;
    private static PreparedStatement getCourseList;
    private static ResultSet resultSet;
    
     public static void addCourse(String courseCode, String semester) {
        connection = DBConnection.getConnection();
        try {
            addCourse = connection.prepareStatement("INSERT INTO app.course (coursecode, semester) VALUES (?, ?)");
            addCourse.setString(1, courseCode);
            addCourse.setString(2, semester);
            addCourse.executeUpdate();
        } catch(SQLException sqlException) {
            sqlException.printStackTrace();
        }
    }
    
public static void addCourse(String course, String semester, String description, String seats) {
    connection = DBConnection.getConnection();
    try {
        addCourse = connection.prepareStatement("INSERT INTO app.course (coursecode, semester, description, seats) VALUES (?, ?, ?, ?)");
        addCourse.setString(1, course);
        addCourse.setString(2, semester);
        addCourse.setString(3, description);
        addCourse.setString(4, seats);
        addCourse.executeUpdate();
    } catch(SQLException sqlException) {
        sqlException.printStackTrace();
    }
}


    
    public static ArrayList<String> getCourseList() {
        connection = DBConnection.getConnection();
        ArrayList<String> courseList = new ArrayList<String>();
        try {
            getCourseList = connection.prepareStatement("SELECT coursecode FROM app.course ORDER BY coursecode");
            resultSet = getCourseList.executeQuery();
            
            while(resultSet.next()) {
                courseList.add(resultSet.getString(1));
            }
        } catch(SQLException sqlException) {
            sqlException.printStackTrace();
        }
        
        
        return courseList;
    }
    
}
