/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package gymcompany;

import java.util.ArrayList;

/**
 *
 * @author aa
 */
public class Reporting {
     public static void list(ArrayList<Clients> client, ArrayList<Clients> clientsilver, ArrayList<Clients> clientgold, ArrayList<Clients> clientnormal) {

    
                 
              
            
           
        System.out.println("All client contine:");
        for (Clients c1 : client) {
          
            System.out.println(c1);
        }
    }

    public static void sub(ArrayList<Sports> sport, ArrayList<Subscribers> subscrip, ArrayList<Sports> subsport) {
        for (Sports sp : sport) {
            int count = 0;
            for (Subscribers sub : subscrip) {
                for (Sports s : sub.getSport()) {
                    if (sp.getName().equals(s.getName())) {
                        count++;
                    }
                }
            }
            if (count <= 3 && count > 0) {
                subsport.add(sp);
            }
        }
        System.out.println("Sports in which less than 3 clients have participated are:");
        for (Sports spp : subsport) {
            System.out.println(spp);
        }
    }
}
