/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gymcompany;

/**
 *
 * @author aa
 */
public class Stackeholders {

    private String firstName;
    private String lastName;
    private String gender;
    private long phone;

    public Stackeholders(String firstName, String lastName, String gender, long phone) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.gender = gender;
        this.phone = phone;
    }

    public Stackeholders() {
    }
    

    public String getFirstName() {
        return firstName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public long getPhone() {
        return phone;
    }

    public void setPhone(long phone) {
        this.phone = phone;
    }
    @Override
     public String toString() {
        return String.format("Stackeholders[First Name: %s -- Last Name: %s -- Gender: %S -- Phone Number: %d]", firstName, lastName, gender, phone);
    }

}
