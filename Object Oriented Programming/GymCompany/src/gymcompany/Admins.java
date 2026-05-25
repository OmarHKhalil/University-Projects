/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gymcompany;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author aa
 */
public class Admins extends Stackeholders {

    private String username = "admine";
    private String password = "watini2002";
    Scanner input = new Scanner(System.in);

    public Admins(String firstName, String lastName, String gender, long phone) {
        super(firstName, lastName, gender, phone);
    }

    public Admins() {
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public void addEmployee(ArrayList<Employees> employee) {
        System.out.println("Please, Enter the first name of employee:");
        String fname = input.next();
        System.out.println("Enter the LAST name of employee:");
        String lname = input.next();
        System.out.println("Enter the gender of employee:");
        String gender = input.next();
        System.out.println("Enter the phone number of employee:");
        long phone = input.nextLong();
        System.out.println("Enter the username then password:");
        String username = input.next();
        String passworde = input.next();
        while (passworde.equals(username)) {

            System.out.println("password equals username enter a different password");
            System.out.println("Enter the username then password:");
            String username1 = input.next();
            String passworde1 = input.next();
            username = username1;
            passworde = passworde1;
        }
        Employees em = new Employees(username, passworde, fname, lname, gender, phone);
        employee.add(em);
    }

}
