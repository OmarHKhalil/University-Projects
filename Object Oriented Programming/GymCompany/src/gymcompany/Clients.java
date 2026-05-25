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
public class Clients extends Stackeholders{
    Scanner input = new Scanner(System.in);
    private static int counter = 0;
    private int client_id;
    private int age;
    private int weight;
    private int height;
    private int card_num;
    private LocalDate startDate;
    private LocalDate endDate;
    private String subscribedType;

    public Clients(String firstName, String lastName, String gender, long phone, int age, int weight, int height, int card_num, LocalDate startDate, LocalDate endDate, String subscribedType ) {
        super(firstName, lastName, gender, phone);
        counter++;
        client_id = counter;
        setAge(age);
        setWeight(weight);
        setHeight(height);
        setCardnum(card_num);
        setStartDate(startDate);
        setEndDate(endDate);
        setSubscribedType(subscribedType);
    }

    Clients() {
       
    }

    public int getClient_id() {
        return client_id;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    public int getWeight() {
        return weight;
    }

    public void setWeight(int weight) {
        this.weight = weight;
    }

    public int getHeight() {
        return height;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public int getCardnum() {
        return card_num;
    }

    public void setCardnum(int card_num) {
        this.card_num = card_num;
    }

    public LocalDate getStartDate() {
        return startDate;
    }

    public void setStartDate(LocalDate startDate) {
        this.startDate = startDate;
    }

    public LocalDate getEndDate() {
        return endDate;
    }

    public void setEndDate(LocalDate endDate) {
        this.endDate = endDate;
    }

    public String getSubscribedType() {
        return subscribedType;
    }

    public void setSubscribedType(String subscribedType) {
        this.subscribedType = subscribedType;
    }
    
 
    public static Clients CreateClient(String fName, String lName, String g, int p, int a, int w, int h, String type, int card_num, LocalDate startDate, LocalDate endDate, String subscribedType) {
        Clients client = new Clients(fName, lName, g, p, a, w, h, card_num, startDate, endDate, subscribedType);
        return client;
    }
    public void addsport(ArrayList<Sports> sport, ArrayList<Sports> addsport) {

        int i = 1;

        System.out.println("Enter the chosen sport");
        String a = input.next();
        for (Sports spp : addsport) {
            if (spp.getName().equals(a)) {
                i = 0;
            }
        }
        if (i == 1) {
            for (Sports sp : sport) {
                if (sp.getName().equals(a)) {
                    if (sp.exist() == 1) {
                        addsport.add(sp);
                      
                        sp.min();
                       
                    } else {
                        System.out.println("the number of place is full");
                       
                    }
                }
            }
        } else {
            System.out.println("Spoer is already involved");
           
        }}
    public int checkCard(int number, ArrayList<Clients> client) {
        for (Clients c : client) {
            if (number == c.card_num) {
                if (c.checkDate() == 1) {
                    System.out.println("The Date of card is  effective, choice the sports");
                    return 1;
                } else {
                    System.out.println("Sorry,the Date of card is  inactive");
                    return 0;
                }
            }

        }
        System.out.println("Sorry the card number is wrong or not exist");
        return 0;
    }
      public int checkDate() {
        LocalDate currentDate = LocalDate.now();
        if (endDate.isAfter(currentDate)) {
            return 1;
        } else {
            return 0;
        }
    }
//      public void checkType(String subscribedType, ArrayList<Cards> card, int number) {
//        for (Cards crd : card) {
//            if (crd.card_num == number) {
//                if (subscribedType.equals("silver")) {
//                    crd.subscribedType = "silver";
//                } else if (subscribedType.equals("gold")) {
//                    crd.subscribedType = "gold";
//                }
//            } else {
//                crd.subscribedType = "normal";
//            }
//        }
//    }
    public String toString() {
        return String.format("Client[Full Name: %s %s  Gender:%s Phone:%d  Age:%d Weight:%d Height:%d] \n  Card[Card Number: %d  Start Date: %s  End Date: %s  subscribedType: %s]", super.getFirstName(), super.getLastName(), super.getGender(), super.getPhone(), age, weight, height, card_num, startDate, endDate, subscribedType);
    }
}
