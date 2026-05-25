/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Main.java to edit this template
 */
package gymcompany;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author aa
 */
public class GymCompany {

    private static ArrayList<Clients> client = new ArrayList<Clients>();
    private static ArrayList<Clients> clientNormal = new ArrayList<Clients>();
    private static ArrayList<Clients> clientSilver = new ArrayList<Clients>();
    private static ArrayList<Clients> clientGold = new ArrayList<Clients>();
    private static ArrayList<Employees> employee = new ArrayList<Employees>();
    private static ArrayList<Sports> sport = new ArrayList<Sports>();
    private static ArrayList<Sports> sportsbs = new ArrayList<Sports>();
    private static ArrayList<Subscribers> subscribe = new ArrayList<Subscribers>();

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner input = new Scanner(System.in);
        Admins admin = new Admins("omar", "alzoubi", "male", 032554);
//        admin.addEmployee(employee);
//        System.out.println(employee.get(0));
//        employee.get(0).Createsportwithemployee(sport);
//        System.out.println(sport.get(0));
//        employee.get(0).Createclientwithemployee(client);
//        employee.get(0).Createclientwithemployee(client);
//        System.out.println(client.get(0));
//        employee.get(0).CreateSubscriptioncard(client, sport, subscribe);
//        employee.get(0).CreateSubscriptioncard(client, sport, subscribe);
//        employee.get(0).CreateSubscriptioncard(client, sport, subscribe);
//        System.out.println(client.get(0));
//        System.out.println(client.get(1));
//        System.out.println(subscribe.get(0));
//        System.out.println(sport.get(0));
//        Reporting.list(client, clientSilver, clientGold, clientNormal);
//        Reporting.sub(sport, subscribe, sportsbs);
        System.out.println("Please,Enter '0' to exit \nEnter '1' to add employee \nEnter '2' to add sports by employee \nEnter '3' to add clients by employee \nEntere '4' to add subscribe by employee \nEnter '5' to view all clients \nEnter '6' to view sports which less than 3 subscribe \nEnter '7' to view all of subscribers \nEnter '8' to view the sport client has subscribe in \nEnter '9' to view all of client's information");
        int choice = input.nextInt();
        while (choice != 0) {
            switch (choice) {
                case 1:
                    admin.addEmployee(employee);
                    break;
                case 2:
                    System.out.println("Enter the username then passworde:");
                    String username = input.next();
                    String passworde = input.next();
                    for (Employees em : employee) {
                        if (username.equals(em.getUserName()) && passworde.equals(em.getPassworde())) {
                            em.Createsportwithemployee(sport);
                        }
                    }
                    System.out.println("the username and passworde is wrong");
                    break;
                case 3:
                    System.out.println("Enter the username then passworde:");
                    String username1 = input.next();
                    String passworde1 = input.next();
                    for (Employees em : employee) {
                        if (username1.equals(em.getUserName()) && passworde1.equals(em.getPassworde())) {
                            em.Createclientwithemployee(client);
                            break;
                        }
                        System.out.println("the username and passworde is wrong");
                    }
                    break;
                case 4:
                    System.out.println("Enter the username then passworde:");
                    String username2 = input.next();
                    String passworde2 = input.next();
                    for (Employees em : employee) {
                        if (username2.equals(em.getUserName()) && passworde2.equals(em.getPassworde())) {
                            em.CreateSubscriptioncard(client, sport, subscribe);
                            break;
                        }
                    }
                    System.out.println("the username and passworde is wrong");
                    break;
                case 5:
                    Reporting.list(client, clientSilver, clientGold, clientNormal);
                    break;
                case 6:
                    Reporting.sub(sport, subscribe, sportsbs);
                    break;
                case 7:
                    for (Subscribers sub : subscribe) {
                        System.out.println(sub);
                    }
                    break;
                case 8:
                    System.out.println("Enter the card number");
                    int number = input.nextInt();
                    for (Subscribers sub : subscribe) {
                        if (sub.getClient().getCardnum() == number) {
                            System.out.println(sub.getSport());
                        }
                    }
                    break;
                case 9:
                    System.out.println("Enter the number card of client ");
                    int number1 = input.nextInt();
                    for(Clients c : client){
                        if(c.getCardnum()==number1){
                            for(Subscribers sub1 : subscribe){
                                if(sub1.getClient().getCardnum()==number1)
                                    System.out.println(c);
                                System.out.println(sub1);
                            }
                        }
                            
                    }
                    break;
                default:
                    System.out.println("invalid choice");
            }
            System.out.println("Please, Enter '1' to add employee \nEnter '2' to add sports by employee \nEnter '3' to add clients by employee \nEntere '4' to add subscribe by employee \nEnter '5' to view all clients \nEnter '6' to view sports which less than 3 subscribe \nEnter '7' to view all of subscribers \nEnter '8' to view the sport client has subscribe in \nEnter '9' to view all of client's information");
            choice = input.nextInt();

        }
    }
}
