/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gymcompany;

import java.time.LocalDate;
import java.util.ArrayList;

/**
 *
 * @author aa
 */
public class Subscribers {
    private static int counter = 0;
    private int sub_id;
    private LocalDate date;
    private Clients client;
    private ArrayList<Sports> sport = new ArrayList<Sports>();
    private double total_amount;

    public Subscribers(LocalDate date, Clients client, ArrayList<Sports> sport, double total_amount) {
        counter++;
        sub_id=counter;
        setDate(date);
        setTotal_amount(total_amount);
        setSport(sport);
        setClient(client);
    }

    Subscribers() {
    }

    public int getSubid() {
        return sub_id;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }

    public ArrayList<Sports> getSport() {
        return sport;
    }

    public void setSport(ArrayList<Sports> sport) {
        this.sport = sport;
    }

    public Clients getClient() {
        return client;
    }

    public void setClient(Clients client) {
        this.client = client;
    }

    public double getTotal_amount() {
        return total_amount;
    }

    public void setTotal_amount(double total_amount) {
        this.total_amount = total_amount;
    }
    
    
    public static void addsub(Subscribers subscribe,Clients client, ArrayList<Sports> sport, double amount) {
//        for (Sports sp : sport) {
//            amount += sp.getSubPrice();
//            System.out.println(sp);
//        }
        if (sport.size() == 2) {System.out.println("silver");
                        client.setSubscribedType("silver");
                    
                    } else if (sport.size() > 2) {System.out.println("gold");
                        client.setSubscribedType("gold");
                 
                    } else {
                        client.setSubscribedType("normal");
                       
                    }
        if (client.getSubscribedType().equals("silver")) {
            System.out.println("omar");
            double amount1  = amount * 0.9;
           subscribe.setTotal_amount(amount1); 
        } else if (client.getSubscribedType().equals("gold")) {
            System.out.println("ali");
            double amount1  = amount * 0.85;
            subscribe.setTotal_amount(amount1);
        } else {
           subscribe.setTotal_amount(amount);
        }
        
    }
    public static int checksub(ArrayList<Subscribers> subcard, ArrayList<Sports> choice, int number) {
        for (Subscribers sub : subcard) {
            if (sub.getClient().getCardnum() == number) {
                System.out.println(sub.getSubid() + " im subscribe  " + number);
                for (Sports sp : sub.sport) {
                    choice.add(sp);
                }
                return 1;
            }

        }

        return 0;
    }
     public String toString() {
        for (Sports sp : sport) {
            System.out.println(sp.getName() + " ");
        }
        return "DATE:" + date +"Client:"+client + "amount" + total_amount;
    }
}
