/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gymcompany;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author aa
 */
public class Employees extends Stackeholders {

    private String userName;
    private String passworde;
    Scanner input = new Scanner(System.in);

    public Employees(String userName, String passworde, String firstName, String lastName, String gender, long phone) {
        super(firstName, lastName, gender, phone);
        this.userName = userName;
        this.passworde = passworde;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getPassworde() {
        return passworde;
    }

    public void setPassworde(String password) {
        this.passworde = password;
    }

    public boolean checkEmployee(String user, String pass) {
        if (userName.equals(user) && passworde.equals(pass)) {
            return true;
        } else {
            return false;
        }
    }

    public void Createsportwithemployee(ArrayList<Sports> sport) {
        System.out.println("please,Enter the Sport Name");
        String names = input.next();
        System.out.println("please,Enter the roomNumber");
        int r_num = input.nextInt();
        System.out.println("please,Enter number of place");
        int num_place = input.nextInt();
        System.out.println("please,Enter the time");
        String time = input.next();
        System.out.println("please,Enter the coach name");
        String c_name = input.next();
        System.out.println("please,Enter the price");
        double sub_price = input.nextDouble();
        sport.add(Sports.CreateSport(names, r_num, num_place, time, c_name, sub_price));
    }

    public void Createclientwithemployee(ArrayList<Clients> client) {
        Subscribers subcard = new Subscribers();
        System.out.println("Please,Enter the first name:");
        String fName = input.next();
        System.out.println("Enter the lsat name:");
        String lName = input.next();
        System.out.println("Enter the gender male or female:");
        String g = input.next();
        System.out.println("Enter the phone number:");
        long p = input.nextLong();
        System.out.println("Enter the age then weight then heigh");
        int a = input.nextInt();
        int w = input.nextInt();
        int h = input.nextInt();
        System.out.println("Now,We craete the card of client");
        System.out.println("Enter the Card Number:");
        int cardNum = input.nextInt();
        while (checkcard(client, cardNum) == 0) {
            System.out.println("Enter another number card ");
            cardNum = input.nextInt();
        }

        System.out.println("Please,Enter the day of start then month of start then year of start");
        int start_day = input.nextInt();
        int start_month = input.nextInt();
        int start_year = input.nextInt();
        LocalDate start_date = LocalDate.of(start_year, start_month, start_day);
        System.out.println("Please,Enter the day of end then month of start then year of start");
        int end_day = input.nextInt();
        int end_month = input.nextInt();
        int end_year = input.nextInt();
        LocalDate end_date = LocalDate.of(end_year, end_month, end_day);
        System.out.println("The type is normal");
        String type = "normal";
        Clients c = new Clients(fName, lName, g, p, a, w, h, cardNum, start_date, end_date, type);
        client.add(c);
        for (Clients c1 : client) {
            System.out.println(c1.getCardnum());
        }

    }

    public int checkcard(ArrayList<Clients> client, int number) {

        for (Clients c : client) {
            if (c.getCardnum() == number) {
                System.out.println("The card number is already there");
                return 0;
            }
        }
        return 1;
    }

    public void CreateSubscriptioncard(ArrayList<Clients> client, ArrayList<Sports> sport, ArrayList<Subscribers> subcard) {
        boolean add = true;
        Sports s = new Sports();
        Clients c = new Clients();

        LocalDate date = LocalDate.now();
        ArrayList<Sports> choice = new ArrayList<Sports>();
        double total = 0;
        //ArrayList<Sport> choice = new ArrayList<Sport>();
        System.out.println("Please,Enter the number of card");
        int number = input.nextInt();

        if (Subscribers.checksub(subcard, choice, number) == 0) {

            if (c.checkCard(number, client) == 1) {
                s.sportavalible(sport);
                c.addsport(sport, choice);

                for (Clients cc : client) {
                    if (cc.getCardnum() == number) {

                        if (choice.size() == 2) {
                            c.setSubscribedType("silver");

                        } else if (choice.size() > 2) {
                            c.setSubscribedType("gold");
                        } else {
                            c.setSubscribedType("normal");
                        }
                        for (Sports sp : choice) {
                            total += sp.getSubPrice();
                        }
                        if (choice.size() > 0) {
                            Subscribers sub = new Subscribers(date, cc, choice, total);
                            subcard.add(sub);
                        }
                    }
                }

            }

        } else {
            double total1 = 0;
            for (Clients cc : client) {
                if (cc.getCardnum() == number) {
                    while (add == true) {
                        if (cc.checkCard(number, client) == 1) {
                            s.sportavalible(sport);
                            cc.addsport(sport, choice);
                            System.out.println("To add another sport enter true to out enter false");
                            add = input.nextBoolean();
                        }
                    }

                    for (Sports sp : choice) {

                        total1 += sp.getSubPrice();
                        
                    }
                   
                    for (Subscribers sub : subcard) {
                        if (cc.getCardnum() == sub.getClient().getCardnum()) {
                            sub.setSport(choice);

                            sub.addsub(sub, cc, choice, total1);
                        }
                    }

                    if (choice.size() == 2) {
                        cc.setSubscribedType("silver");

                    } else if (choice.size() > 2) {
                        cc.setSubscribedType("gold");

                    } else {
                        cc.setSubscribedType("normal");

                    }
                }
            }
        }
    }

    public String toString() {

        return String.format("Employees[First Name: %s -- Last Name: %s -- Gender: %S -- Phone Number: %d \n username: %s  passworde: %s]", super.getFirstName(), super.getLastName(), super.getGender(), super.getPhone(), userName, passworde);
    }
}
